#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 512
#define ON 1
#define OFF 0

typedef struct{
    int seq;
    int msg_type;
    int payload;
    char data[BUFSIZE];
}Packet;

void error_handling(char * message);

int main(int argc, char ** argv){
    int debugging;
    int expectedseqnum = 0;
    int ack = htonl(expectedseqnum);

    int serv_sock;
    int str_len = -1, num = 0;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    int clnt_addr_size;

    FILE *fp;
    Packet *apacket;

    if(argc != 3){
        printf("Usage : %s <port> <on/off>\n", argv[0]);
        exit(1);
    }

    /* setting debuffing mode */
    if(strcmp(argv[2], "on") == 0){
        debugging = ON;
    }
    else if(strcmp(argv[2], "off") == 0){
        debugging = OFF;
    }
    else{
        printf("Usage : %s <port> <on/off>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(serv_sock == -1)
        error_handling("UDP socket error");
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1)
        error_handling("bind() error");
    
    apacket = (Packet*)malloc(sizeof(Packet));

    while(1){
        clnt_addr_size = sizeof(clnt_addr);

        str_len = recvfrom(serv_sock, (void*)apacket, sizeof(Packet), 0, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

        if(apacket->seq == expectedseqnum) /* if receive in-order packet */
        {
            expectedseqnum++;
            if(debugging)
                printf("received seq num %d, accepted, send ack %d\n", apacket->seq, expectedseqnum);
            
            ack = htonl(expectedseqnum);
            sendto(serv_sock, &ack, 4, 0, (struct sockaddr*)&clnt_addr, clnt_addr_size);

            if(apacket->msg_type == 0) /* in case of file name */
            {
                fp = fopen(apacket->data, "wb");
            }
            else /* in case of file data */
            {
                fwrite(apacket->data, sizeof(char), apacket->payload, fp);
                if(apacket->msg_type==2){
                    fclose(fp);
                    printf("Done : last packet accepted\n");
                }
            }
        }
        else /* if receive out-of-order packet */
        {
            if(debugging)
                printf("received seq num %d, discard, (re)send ack %d\n", apacket->seq, expectedseqnum);

            sendto(serv_sock, &ack, 4, 0, (struct sockaddr*)&clnt_addr, clnt_addr_size);
        }
    }

    return 0;
}

void error_handling(char * message){
    perror(message);
    exit(1);
}