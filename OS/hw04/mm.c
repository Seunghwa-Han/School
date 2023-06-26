#include "mm.h"

list mem_list = {NULL, NULL, 0};  // memory allocation list

// add memory information to the memory allocation list
void add(node * tmp){
	if(mem_list.rear != NULL) // not empty 
		mem_list.rear->link = tmp;
	else
		mem_list.front = tmp;
	mem_list.rear = tmp;
	mem_list.num ++;
}


void *mm_malloc(size_t size){
	// create new node 
	node * tmp = mmap(0, sizeof(node), PROT_WRITE | PROT_READ, MAP_ANON | MAP_SHARED, -1, 0);
	tmp->mem_size = size;
	tmp->link = NULL;
	// allocate size bytes using mmap()
	tmp->mem_ptr = mmap(0, size, PROT_WRITE | PROT_READ, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
	
	// add node to memory allocation list 
	add(tmp);

	return tmp->mem_ptr;
}

void *mm_calloc(size_t num, size_t size){
	// create new node
	node * tmp = mmap(0, sizeof(node), PROT_WRITE | PROT_READ, MAP_ANON | MAP_SHARED, -1, 0);
	tmp->mem_size = size*num;
	tmp->link = NULL;
	// allocate size*num bytes using mmap()
	tmp->mem_ptr = mmap(0, size*num, PROT_WRITE | PROT_READ, MAP_ANON | MAP_SHARED, -1, 0);

	// add node to memory allocation list
	add(tmp);

	return tmp->mem_ptr;
}

void *mm_realloc(void *ptr, size_t size){
	// memory allocation list is empty
	if ( mem_list.front == NULL){
		printf("memory allocation list is empty.\n");
		return NULL;
	}

	// find ptr 
	node * curr = mem_list.front;
	while(curr != NULL && curr->mem_ptr != ptr){
		curr = curr->link;
	}

	// ptr is not exist 
	if(curr == NULL){
		printf("no such memory in memory allocation list");
		return NULL;
	}

	// change size of memory blcok pointed at prt to size bytes
	curr->mem_ptr = mremap(ptr, curr->mem_size, size, MREMAP_MAYMOVE);
	curr->mem_size = size;

	return curr->mem_ptr;
}

void mm_free(void *ptr){
	// find ptr and save previous node pointer of ptr
	node * prev = NULL;
	node * curr = mem_list.front;
	while(curr != NULL && curr->mem_ptr != ptr){
		prev = curr;
		curr = curr->link;
	}
	
	// ptr is not exist 
	if(curr == NULL){
		printf("no such memory in memory allocation list");
	       	return;
	}

	if(prev)   // prt is not front 
		prev->link = curr->link;
	else       // ptr is front
		mem_list.front = mem_list.front->link;
	if(mem_list.front == NULL)  // list becomes empty
		mem_list.rear = NULL;
	if(curr == mem_list.rear)   // ptr is rear
		mem_list.rear = prev;
	// free memory space pointed to by ptr
	munmap(curr->mem_ptr, curr->mem_size);
	// free memory space pointed to by memory allocation list
	munmap(curr, sizeof(node));
	mem_list.num--;
}

void mm_status(){
	// print memory allocation list 
	printf("Allocated Memory:\n");
	node * curr = mem_list.front;
	int i = 0;
	while(curr != NULL){
		printf("[%2d] Addr=%p, Size=%ld\n", i++, curr->mem_ptr, curr->mem_size);
		curr = curr->link;
	}
}

