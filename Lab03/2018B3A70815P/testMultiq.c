/* testMultiq.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "que.h"
#include "multiq.h"
int main(int argc, char *argv[]){
	struct timeval t1,t2;
	double timetaken;
        FILE *filept = fopen(argv[1],"r");
        gettimeofday(&t1,NULL);
	MultiQ* mq = loadData(filept);
        gettimeofday(&t2,NULL);
	timetaken = (t2.tv_sec-t1.tv_sec)*1000.0;
	timetaken += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time taken to add to multiqueue is %f ms.\n",timetaken);
	int tc;
        tc = atoi(argv[2]);
	gettimeofday(&t1,NULL);
        mq = testDel(mq,tc);
	gettimeofday(&t2,NULL);
        timetaken = (t2.tv_sec-t1.tv_sec)*1000.0;
        timetaken += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for  deletion: %f ms.\n",timetaken);
	timetaken/=tc;
	printf("Avg time per deletion: %f ms.\n",timetaken);
}
/* end of testMultiq.c */
