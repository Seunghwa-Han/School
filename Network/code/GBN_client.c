#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define BUFSIZE 512
#define ON 1
#define OFF 0
#define RTTS 0
#define RTTM 500
#define SLEEP 1

int send_base, nextseqnum;
char fname[BUFSIZE];
size_t fsize;
FILE *fp;    /* file pointer */
int num_pkt; /* total number of packet to send */
int sock;
struct sockaddr_in serv_addr;
int debug;
timer_t timerID;

void error_handling(char * message);
int createTimer(timer_t * _timerID);
int setTimer(timer_t * _timerID, int sec, int msec);
void timerHandler();

typedef struct{
    int seq;
    int msg_type;
    int payload;
    char data[BUFSIZE];
}Packet;

int main(int argc, char ** argv){
    int str_len, addr_size, i;
    int N; // sender window size 

    struct sockaddr_in from_addr;
    struct sigaction act;
    Packet apacket;

    if(argc != 5){
        printf("Usage : %s <IP> <port> <SWS> <on/off>\n", argv[0]);
        exit(1);
    }
    N = atoi(argv[3]);
    if(N > 10){
        printf("sender window size of GBN is smaller than 10\n");
        exit(1);
    }
    if(strcmp(argv[4], "on") == 0){
        debug = ON;
    }
    else if(strcmp(argv[4], "off") == 0){
        debug = OFF;
    }
    else{
        printf("enter valid input for debugging\n");
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1)
        error_handling("UDP socket error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    send_base = 0, nextseqnum = 0;
    int ack, prev_ack = -1;

    /* set file name */
    strcpy(fname, "time_table.xlsx");
    /* calculate total file size */
    if((fp = fopen(fname, "rb")) == NULL){
        perror(fname);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    num_pkt = fsize/BUFSIZE +2; /* total number of packets to send */

    printf("total file size: %d, file name: %s\n", fsize, fname);
    if(debug)
        printf("------------------------------------------------------\n");
    
    createTimer(&timerID);

    while(1){
        /* send data if window is not fulll */
        if(nextseqnum <= send_base+N-1 && nextseqnum < num_pkt){

            apacket.seq = nextseqnum;

            memset(apacket.data, 0x00, BUFSIZE); /* clear data buffer */

            if(apacket.seq == 0){  /* in case of file name */
                apacket.msg_type = 0;
                strcpy(apacket.data, fname);
                apacket.payload = strlen(fname);
                sendto(sock, (void *)&apacket, sizeof(apacket), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

            }
            else{  /* in case of file data */
                apacket.msg_type = 1;
                apacket.payload = fread(apacket.data, sizeof(char), BUFSIZE, fp);

                if(num_pkt-1 == apacket.seq){
                    /* in case of end of file */
                    apacket.msg_type = 2;
                }
                sendto(sock, (void *)&apacket, sizeof(Packet), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

            }

            if(send_base == nextseqnum){
                /* start timer */
                setTimer(&timerID, RTTS, RTTM);
                if(debug)
                    printf("start timer [seq %d]\n", send_base);
            }
            nextseqnum++;

            if(debug)
                printf("send [seq %d] [msg type %d] [payload %d]\n", apacket.seq, apacket.msg_type, apacket.payload);

        }
        else{ /* receive ack if sender window is full */

            addr_size = sizeof(serv_addr);
            str_len = recvfrom(sock, &ack, 4, 0, (struct sockaddr*)&serv_addr, &addr_size);
            ack = ntohl(ack);

            if(ack == prev_ack){  /* check duplicate ack*/

                if(debug)
                    printf("ignore duplicate ack %d\n", ack);

            } 
            else if(ack >= send_base && ack <= nextseqnum){
                /* check valid ack*/

                send_base = ack;

                if(debug)
                    printf("[ack %d] received\n", ack);
                
                if(send_base == nextseqnum){
                    /* stop timer */
                    setTimer(&timerID, 0, 0);
                    if(debug)
                        printf("stop timer [seq %d]\n", send_base);
                }
                else{
                    /* restart timer */

                    setTimer(&timerID, RTTS, RTTM);
                    if(debug)
                        printf("start timer [seq %d]\n", send_base);
                }
                prev_ack = ack;
            }

            if(ack == num_pkt)
                break;

        }
    }

    fclose(fp);
    close(sock);

    return 0;

}

void timerHandler(){
    Packet apacket;
    if(debug)
        printf("Timer-out [seq %d]\n", send_base);
    int i;

    /* start timer */
    setTimer(&timerID, RTTS, RTTM);
    if(debug)
        printf("recover & start timer [seq %d]\n", send_base);

    /* move file pointer */
    if(send_base == 0) // file name
        fseek(fp, 0, SEEK_SET);
    else
        fseek(fp, (send_base-1)*BUFSIZE, SEEK_SET);
    
    /* resend packet : send_base~nextseqnum-1*/
    for(i = send_base; i<=nextseqnum-1; i++){
        apacket.seq = i;

        memset(apacket.data, 0x00, BUFSIZE);
        if(apacket.seq == 0){ /* in case of file name */
            apacket.msg_type = 0;
            strcpy(apacket.data, fname);
            apacket.payload = strlen(fname);
            sendto(sock, (void *)&apacket, sizeof(apacket), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        }
        else{ /* in case of file data */
            apacket.msg_type = 1;
            apacket.payload = fread(apacket.data, sizeof(char), BUFSIZE, fp);

            if(num_pkt-1 == i){ /* end of file */
                apacket.msg_type = 2;
            }
            sendto(sock, (void *)&apacket, sizeof(Packet), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        }

        if(debug){
            printf("(re)send [seq %d] [msg type %d] [payload %d]\n", apacket.seq, apacket.msg_type, apacket.payload);
        }
    }
}

int createTimer(timer_t * _timerID){
    struct sigevent te;
    struct sigaction sa;
    /* Set up signal handler */
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timerHandler;
    sigemptyset(&sa.sa_mask);
    if(sigaction(SIGRTMIN, &sa, NULL) == -1){
        printf("sigaction error \n");
        exit(1);
    }

    /* Set and enable alarm */
    te.sigev_notify = SIGEV_SIGNAL;
    te.sigev_signo = SIGRTMIN;
    te.sigev_value.sival_ptr = _timerID;
    timer_create(CLOCK_REALTIME, &te, _timerID);

    return 0;
}

int setTimer(timer_t * _timerID, int sec, int msec){
    struct itimerspec its;
    /* one-shot timer */
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    its.it_value.tv_sec = sec;
    its.it_value.tv_nsec = msec * 1000000;
    timer_settime(_timerID, 0, &its, NULL);
}

void error_handling(char * message){
    perror(message);
    exit(1);
}