/* testlscycle.c */
#include <stdio.h>
#include <stdlib.h>
#include "cycle.h"
#include<sys/time.h>

int main(int argc, char*argv[]){
	struct timeval t1, t2, t3, t4;
        double elapsedTime;
	int N = atoi(argv[1]);
	gettimeofday(&t1, NULL);
	linkedList* ls = createList(N);
	gettimeofday(&t2, NULL);
	createCycle(ls);
	gettimeofday(&t3, NULL);
	//printls(ls);
	if(testCyclic(ls)) printf("True\n");
	else printf("False\n");
	gettimeofday(&t4, NULL);
	
	//createList() 
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	double tt1 = elapsedTime;

	//createCycle()
	elapsedTime = (t3.tv_sec - t2.tv_sec) * 1000.0;
        elapsedTime += (t3.tv_usec - t2.tv_usec) / 1000.0;
	double tt2 = elapsedTime;
	
	//testCycle()
	elapsedTime = (t4.tv_sec - t3.tv_sec) * 1000.0;
        elapsedTime += (t4.tv_usec - t3.tv_usec) / 1000.0;
	double tt3 = elapsedTime;
	
	FILE* filep = fopen("output.csv","a");
	fprintf(filep,"%d, %ld, %f, %f, %f\n",N,totalmem,tt1,tt2,tt3);
	fclose(filep);
	
}

/* end of testlscycle.c */
