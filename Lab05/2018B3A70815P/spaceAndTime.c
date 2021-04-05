/* spaceAndTime.c */
#include<stdlib.h>
#include<sys/time.h>
#include"record.h"

record** measureReadTime(char* file,int* size){
	int minsize=10;
	FILE* f = fopen(file,"r");
	record** arr = (record**)malloc(minsize*sizeof(record*));
	int ind=0;
	int currsize = minsize;
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	while(!feof(f)){
		char* str;
		record* r = newRecord();
		int year,month;
				fscanf(f,"\"%llu,%[^,],%d/%d,%[^,],%[^\"]\"\n",&(r->CNo),r->Bcode,&(r->exp.month),&(r->exp.year),r->Fname,r->Lname);
		if(ind>=currsize){
			currsize*=2;
			arr = realloc(arr,sizeof(record)*currsize);
		}
		arr[ind]=r;
		ind++;
	}
	fclose(f);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	f = fopen("result.txt","a");
	fprintf(f,"Read %d records in %f milliseconds\n",ind,elapsedTime);
	fclose(f);
	*size = ind;
	return arr;
}

void measureSortTimeAndSpace(record** arr, int* size){
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	int ref;
	insertionSort(arr,*size);
	long long int size_of_stack = &ref - stacktop;
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	FILE* f = fopen("result.txt","a");
	fprintf(f,"Sorted %d records in %f milliseconds\n",*size,elapsedTime);
	fprintf(f,"Size of recursion for %d records is %lld bytes\n",*size,size_of_stack);
	fclose(f);
}
/* end of spaceAndTime.c */
