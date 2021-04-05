/* mymem.c */
#include "mymem.h"

size_t totalmem=0;

void* myalloc(size_t size){
	void* mem = calloc(1,size+sizeof(size_t)); // Allocate size and one extra space to store the size
	if(mem==NULL) return mem;
	*(size_t*)mem = size; // Store the value of size in mem
	totalmem += size; 
	mem += sizeof(size_t); //Shift mem to point to the actual first element
	return mem;
}

void myfree(void* ptr){
	ptr -= sizeof(size_t);
	totalmem-=(*(size_t*)ptr);
	free(ptr);
}

void printMem(){
	printf("Total memory used: %ld\n", totalmem);
}
/* end of mymem.c */
