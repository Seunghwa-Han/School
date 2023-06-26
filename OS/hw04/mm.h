#define _MM_H 1
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

// TODO include header files 

// TODO define structure for memory informaiton  
typedef struct node {
	void *mem_ptr;
	size_t mem_size; 
	struct node * link;
} node;

typedef struct list {
	node * front;
	node * rear;
	int num;
} list;	


// TODO Function declaration  
void *mm_malloc(size_t size);
void *mm_calloc(size_t num, size_t size);
void *mm_realloc(void *ptr, size_t size);
void mm_free(void *ptr);
void mm_status();
