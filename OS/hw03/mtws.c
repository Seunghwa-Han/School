#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

typedef struct{
	pthread_cond_t queue_c;   // conditional variable for inserting item into bounded buffer
	pthread_cond_t dequeue_c; // conditional variable for consuming item from bounded buffer

	pthread_mutex_t lock;     // mutex for accessing element of buffer
	pthread_mutex_t lock2;    // mutex for updating number of word in file

	char ** item; // element of buffer
	int capacity; // size of buffer
	int num;      // number of item
	int in;       // rear
	int out;      // front
	int result;   // number of word in file
} bounded_buffer;

bounded_buffer * buffer;

void print_help();         
void convert_lower(char * str);
void find_dir(char * dir);    // recursively add file in dir to bounded buffer, producer function
int find_word(char * file_name, char * s_word); // return the number of search word in file name 
void * runner(void * param);  // thread function (consumer)

void bounded_buffer_init(bounded_buffer * buf); // initiate variale in bounded buffer 
void bounded_buffer_queue(bounded_buffer * buf, char* item); // insert item into bounded buffer
char * bounded_buffer_dequeue(bounded_buffer * buf);         // delete item from bounded buffer

int num_files = 0;            // number of files in directory

int main(int argc, char * argv[]){

	if (argc <=5){
		print_help();
		return 0;
	}

	char * s_word;  // search word
	char * s_dir;   // search directory
	int num_t = 0;  // number of threads
	pthread_t * thread;

	buffer = malloc(sizeof(bounded_buffer));

	int opt;
	while((opt = getopt(argc, argv, "b:t:d:w:")) != -1){
		switch (opt) {
			case 'b':
				buffer->capacity = atoi(optarg);  
				break;
			case 't':
				num_t = atoi(optarg);
				thread = (pthread_t*)malloc(sizeof(pthread_t)*num_t);
				break;
			case 'd':
				s_dir = (char*)malloc(sizeof(char)*strlen(optarg));
				sprintf(s_dir,"%s",optarg);
				break;
			case 'w':
				s_word = (char*) malloc (sizeof(char)*strlen(optarg));
				sprintf(s_word,"%s",optarg);
				break;
		}
	}

	bounded_buffer_init(buffer);
	convert_lower(s_word);
	
	for(int i=0; i<num_t; i++){
		pthread_create(&thread[i], NULL, &runner, (void*)s_word);
	}	
	find_dir(s_dir);

	while(1){
		if(buffer->in == buffer->out){
			sleep(1);
			for(int i=0; i<num_t; i++){
				pthread_cancel(thread[i]);
			}
			break;
		}
	}
/*
	for(int i=0; i<num_t; i++){
		void *r;
		pthread_join(thread[i], &r);
		if(r == PTHREAD_CANCELED)
			printf("cancled\n");
	}
*/
	printf("Total found = %d (Num files=%d)\n", buffer->result, num_files); 
	return 0;
}

void find_dir(char * dir){
	DIR *dp;
	struct dirent *dirp;
	struct stat file_stat;

	dp = opendir(dir);
	while((dirp = readdir(dp)) != NULL){

		if (strcmp(dirp->d_name, ".")==0 || strcmp(dirp->d_name, "..")==0 || strcmp(dirp->d_name, ".DS_Store")==0){
				continue;
		}
		char * tmp = malloc(sizeof(char)*(strlen(dir)+1+strlen(dirp->d_name)));
		sprintf(tmp, "%s/%s", dir, dirp->d_name);

		int ret = lstat(tmp, &file_stat);
		if (ret == -1){
			perror(tmp);
		}

		if(S_ISDIR(file_stat.st_mode)){    // if directory 
			find_dir(tmp);
			free(tmp);
		}
		else{ // not directory but file
			char * item = malloc(sizeof(char)*(strlen(tmp)));
			sprintf(item, "%s", tmp);
			free(tmp);

			bounded_buffer_queue(buffer, item);
			num_files ++;
		}
	}	
	closedir(dp);
}

void * runner(void * param){
	pthread_t tid = pthread_self();
	char * s_word = (char *)param;
	char * file_name;

	printf("[Thread %ld] started searching \'%s\'...\n", (long)tid, s_word);

	while(1){
		
		file_name = bounded_buffer_dequeue(buffer);
		//printf("Dequeue_%s:%lu\n",file_name, (long)tid); 
/*
		pthread_mutex_lock(&(buffer->lock2));
			if(file_name != NULL){
				int res = find_word(file_name, s_word);
				printf("[Thread %ld-%d] %s : %d found\n", (long)tid, res, file_name, res);
				buffer->result += res;
			}
		pthread_mutex_unlock(&(buffer->lock2));
*/
		int res = 0;
		if(file_name != NULL){
			res = find_word(file_name, s_word);
			printf("[Thread %ld-%d] %s : %d found\n", (long)tid, res, file_name, res);
		}
		pthread_mutex_lock(&(buffer->lock2));
			buffer->result += res;
		pthread_mutex_unlock(&(buffer->lock2));

		//sleep(1);
	}

}

void bounded_buffer_queue(bounded_buffer * buf, char* item){
	pthread_mutex_lock(&(buf->lock));
		while((buf->in+1)%buf->capacity == buf->out)   // buffer is full
			pthread_cond_wait(&(buf->queue_c), &(buf->lock));

		buf->item[buf->in] = item;
		buf->in = (buf->in+1)%buf->capacity;
		buf->num++;
		//printf("queue: %s\n", item);

		pthread_cond_signal(&(buf->dequeue_c));
	pthread_mutex_unlock(&(buf->lock));
}

char * bounded_buffer_dequeue(bounded_buffer * buf){
	pthread_mutex_lock(&(buf->lock));
		while(buf->in == buf->out)
			pthread_cond_wait(&(buf->dequeue_c), &(buf->lock));

		char * tmp = buf->item[buf->out];
		buf->out = (buf->out+1)%buf->capacity;
		buf->num --;

		pthread_cond_signal(&(buf->queue_c));
	pthread_mutex_unlock(&(buf->lock));

	return tmp;
}

void bounded_buffer_init(bounded_buffer * buf){
	pthread_cond_init(&(buf->queue_c), NULL);
	pthread_cond_init(&(buf->dequeue_c), NULL);
	pthread_mutex_init(&(buf->lock), NULL);
	pthread_mutex_init(&(buf->lock2), NULL);
	buf->item = (char **)malloc(sizeof(char*)*buf->capacity);
	buf->num = 0;
	buf->in = 0;
	buf->out = 0;
	buf->result = 0;
}

int find_word(char * file_name, char * s_word){
	int  fd, read_bytes;
	const int BUFSIZE = 100;
	char buf[BUFSIZE+1];
	int count = 0;
	int size = strlen(s_word);

	fd = open(file_name, O_RDONLY);
	if (fd == -1){
		perror(file_name);
		exit(1);
	}

	read_bytes = read(fd, buf, BUFSIZE);
	while(1){
		convert_lower(buf);
		
		char * ptr = strstr(buf, s_word);
		while(ptr!=NULL){
			count++;
			ptr = strstr(ptr+1, s_word);
		}

		lseek(fd, -1*size+1, SEEK_CUR);
		read_bytes = read(fd, buf, BUFSIZE);
		if(read_bytes < BUFSIZE) break;
	}	

	close(fd);
	
	return count;
}

void convert_lower(char * str){
	int size = strlen(str);
	
	int i;
	for(i=0; i<size; i++){
		if(isupper(str[i]))
			str[i] = tolower(str[i]);
	}
}

void print_help(){
	printf("Usage: ./mtws\n");
	printf("  -b : bounded buffer size\n");
	printf("  -t : number of threads searching word (except for main thread)\n");
	printf("  -d : search directory\n");
	printf("  -w : search word\n");
}
