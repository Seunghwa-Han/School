#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

void convert_lower(char * tmp); // convert to lower case 
int find_searchword(char * filename, char * search); // return # of search in the filename

int main(int argc, char * argv[]){

	if(argc <= 2){
		printf("Program should follow usage below.\n");
		printf("$ ./mpws searchfile1 searchfile2 ... searchword\n");
		return 0;
	}

	pid_t pid[argc-2];    // pid array for child process
	int result = 0;       // total number of search word
	char search_word[strlen(argv[argc-1])];   // search word 
	strcpy(search_word, argv[argc-1]);

	const int SIZE = 4096; // size of shared memory
	const char * name = "OS";
	int shm_fd;            // shared memory segment
	void * ptr;            // mapped shared memory 

	// create the shared memory segment
	shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

	// configure the size of the shared memory segment
	ftruncate(shm_fd, SIZE);

	//map the shared memory segment in the address space of the process
	ptr = (int *)mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd,0);
	if (ptr == MAP_FAILED){
		printf("Map failed\n");
		return -1;
	}

	// create children process
	for( int i = 1; i<=argc-2; i++){
		pid[i] = fork();

		if (pid[i] < 0){
			fprintf(stderr, "fork failed\n");
			return 1;
		} // child process 
		else if (pid[i] == 0){
			printf("Child Process: searching %s...\n", argv[i]);

			// find # of search word in the file
			int n = find_searchword(argv[i], search_word); 
			((int *)ptr)[i-1] = n;

			exit(0); // terminate child process
		} // parent process 
		else {
			wait(NULL);
		}
	}

	// print out the result in the parent process
	for(int i=1; i<=argc-2; i++){
		printf("%s: %d\n", argv[i], ((int*)ptr)[i-1]);
		printf("Result: %d \'%s\' found in %s\n",((int*)ptr)[i-1],search_word, argv[i]);
		result += ((int*)ptr)[i-1];
	}
	printf("Total count: %d\n", result);
}

int find_searchword(char * filename, char * search){
	int fd;              // file pointer
	int read_bytes;      // return value of read()
	const int BUFSIZE = 80;
	char buf[BUFSIZE+1]; // buffer for read file 
	int count = 0;       // # of search word 
	int size = strlen(search);  // length of search word

	convert_lower(search);      // convert to lower cases
	
	// open given file
	fd = open(filename, O_RDONLY);
	if (fd == -1){
		perror(filename);
		return 0;
	}
	// read given file
	while((read_bytes = read(fd, buf, BUFSIZE)) > 0){
		convert_lower(buf);
		char * ptr = strstr(buf, search);
		if(ptr == NULL)
			continue;
		else{
			// find all search word in buf
			while(ptr != NULL){
				count++;
				ptr = strstr(ptr+1, search);
			}
		}	
		// for the case of search word is truncated
		lseek(fd, -1*size, SEEK_CUR);
	}
	close(fd);

	return count;
}

void convert_lower(char * tmp){
	int size = strlen(tmp);
	for(int i=0; i< size; i++){
		if(isupper(tmp[i]))
			tmp[i] = tolower(tmp[i]);
	}
}
