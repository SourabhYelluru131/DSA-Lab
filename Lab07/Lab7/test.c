/* test.c */
// This file is made to check if Quick Sort and Insertion Sort are working
#include"stdio.h"
#include"stdlib.h"
#include "customsort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "employee.h"
#include <sys/time.h>
#include <assert.h>
#include <math.h>

int main(int argc, char* argv[]){
	FILE *filept = fopen(argv[1],"r");
	int size = atoi(argv[1]);
	Employee* arr = (Employee*)malloc(size*sizeof(Employee));
	readFile(filept,arr);
	//free(filept);
	printArray(arr,size);
	
	Employee* arr2 = (Employee*)malloc(size*sizeof(Employee));
	Employee* arr1 = (Employee*)malloc(size*sizeof(Employee));
	for(int i=0;i<size;i++){
		arr1[i]=arr[i];
		arr2[i]=arr[i];
	}
	
	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);
	QuickSortIter(arr1,0,size-1,0);
	gettimeofday(&t2, NULL);
	printArray(arr1,size);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Time Taken to sort %d elements = %lf milliseconds.\n",size,elapsedTime);
	
	gettimeofday(&t1, NULL);
	InsertionSortIter(arr2,0,size-1);
	gettimeofday(&t2, NULL);
	printArray(arr2,size);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Time Taken to sort %d elements = %lf milliseconds.\n",size,elapsedTime);
}