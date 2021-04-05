/* mymem.h */
#include <stdio.h>
#include <stdlib.h>

size_t totalmem;

void* myalloc(size_t size);
void myfree(void* ptr);
void printMem();

/* end of mymem.h */
