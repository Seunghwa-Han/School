#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define BUFSIZE 100

void copy_f(char source[], char target[], int flag_v);
void copy_m(char * arr[], int s, int e, int flag_v);
void copy_d(char source[], char target[], int flag_v);

int main(int argc, char * argv[]){
	int opt;
	int flag_f =0, flag_m = 0, flag_d = 0, flag_v = 0;
	int start, end; 
	
	while((opt = getopt(argc, argv, "f:m:d:v"))!=-1) {
		switch (opt) {
			case 'v': flag_v = 1; break;
			case 'f':
				flag_f = 1;
				if (strcmp(optarg,"v")==0){
					flag_v = 1;
					optind++;
				}
				start = optind -1;
				// printf("%s\n", optarg); 
				for(; optind<argc && *argv[optind]!='-'; optind++){
					end = optind;
					// printf("%s ",argv[optind]);
				}
				// printf("\n");

				break;
			case 'm':
				flag_m = 1;
				if (strcmp(optarg,"v")==0){
					flag_v = 1;
					optind++;
				}

				start = optind -1;
				//printf("%s\n", optarg); 
				for(; optind<argc && *argv[optind]!='-'; optind++){
					end = optind;
					//printf("%s ",argv[optind]);
				}
				//printf("\n");

				break;
			case 'd':
				flag_d = 1;
				if (strcmp(optarg,"v")==0){
					flag_v = 1;
					optind++;
				}

				start = optind -1;
				//printf("%s\n", optarg); 
				for(; optind<argc && *argv[optind]!='-'; optind++){
					end = optind;
					//printf("%s ",argv[optind]);
				}
				//printf("\n");
				break;
			case '?': printf("Unkown flag : %c \n", optopt);
		}	
	}					

	if (flag_f){
		copy_f(argv[start], argv[end], flag_v);
	}
	else if (flag_m){
		copy_m(argv, start, end, flag_v);
	}
	else if (flag_d){
		copy_d(argv[start], argv[end], flag_v);
	}

}


void copy_f(char source[], char target[], int flag_v){
	int fd_r, fd_w, read_bytes;
	char buf[BUFSIZE];
	struct stat file_stat;
	int file_permission;

	// open source file
	fd_r = open(source, O_RDONLY);
	if ( fd_r == -1) {
		perror(source);
		exit(1);
	}

	// load file permission of source file 
	int ret = stat(source, &file_stat);
	if ( ret == -1){
		perror(source);
		exit(1);
	}
	file_permission = file_stat.st_mode;

	// open target file
	
	fd_w = open(target, O_CREAT|O_WRONLY, file_permission);
	if ( fd_w == -1){
		perror(target);
		exit(1);
	}

	// read data from source file
	while ((read_bytes = read(fd_r, buf, BUFSIZE)) > 0){
		// write file data
		write(fd_w, buf, read_bytes);
	}	

	// close file discriptor
	close(fd_r);
	close(fd_w);

	chmod(target, file_permission);

	if (flag_v) {
			printf("Copy File: %s -> %s\n", source, target); 
	}

}

void copy_m(char * arr[], int s, int e, int flag_v){
	struct stat file_stat;
	int file_permission;

	// make directory 
	stat("./", &file_stat);
	file_permission = file_stat.st_mode;
	int ret = mkdir(arr[e], file_permission);
	if ( ret == -1 && errno != EEXIST){
		perror(arr[e]);
		exit(1);
	}

	// iterate for all source files
	for ( int i = s; i<e; i++){
		char * tmp_d = malloc(sizeof(char)*20);
		strcpy(tmp_d, arr[e]);
		strcat(strcat(tmp_d,"/"), arr[i]);

		copy_f(arr[i], tmp_d, flag_v);
		free(tmp_d);
	}

	chmod(arr[e], file_permission);
}

void copy_d(char source[], char target[], int flag_v){
	DIR * dp = NULL; // directory pointer 
	struct dirent * entry = NULL; 
	struct stat file_stat;
	int file_permission;

	// make target directory 
	stat(source, &file_stat);
	file_permission = file_stat.st_mode;
	mkdir(target, file_permission);

	// open source directory
	if ( (dp = opendir(source)) == NULL){
		perror(source);
		exit(1);
	}

	// read source directory
	while((entry = readdir(dp))!=NULL){
		// if file name is . or .. -> skip
		if ( strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
			continue;
		}

		int ret = lstat(entry->d_name, &file_stat);

		char * tmp_s = malloc(sizeof(char)*20);
		strcpy(tmp_s, source);
		strcat(strcat(tmp_s,"/"), entry->d_name);

		if ( ret == -1){
			lstat(tmp_s, &file_stat);
		}
		char * tmp_d = malloc(sizeof(char)*20);
		strcpy(tmp_d, target);
		strcat(strcat(tmp_d,"/"), entry->d_name);

		if(S_ISDIR(file_stat.st_mode)){ // if directory
			copy_d(tmp_s, tmp_d, flag_v);
		}
		else if(S_ISREG(file_stat.st_mode)){ // if file
			copy_f(tmp_s, tmp_d, flag_v); 		
		}	

		free(tmp_s);
		free(tmp_d);
	}	

	closedir(dp);

	chmod(target, file_permission);

}
