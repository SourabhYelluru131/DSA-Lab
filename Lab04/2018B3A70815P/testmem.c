/* testmem.c */
#include "mymem.h"
int main(){
	int r = rand()%15001 + 10000; // generates random number between 10000 and 25000
	printf("Value of M is %d\n", r);
	int* A = (int*)myalloc(r*sizeof(int));
	printMem();
	printf("First loc: %p\nLast loc: %p\n", A,A+r-1);
	myfree(A);
	printMem();
	return 0;
}
