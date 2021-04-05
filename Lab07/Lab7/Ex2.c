#include"stdio.h"
#include"stdlib.h"
#include "customsort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "employee.h"
#include <sys/time.h>
#include <assert.h>
#include <math.h>

double* testRun(Employee* arr, int n){
	double* res = (double*)malloc(2*sizeof(double));				//Results of the run
	struct timeval t1, t2;
	double elapsedTime;
	Employee* newarr = (Employee*)malloc(n*sizeof(Employee));	//making a copy
	for(int i=0;i<n;i++) newarr[i]=arr[i];
	
	gettimeofday(&t1,NULL);     //start time
	InsertionSortIter(arr,0,n-1);     //run Quick sort
	gettimeofday(&t2,NULL);		//end time
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	res[0]=elapsedTime;
	
	gettimeofday(&t1,NULL);     	//start time
	QuickSortIter(newarr,0,n-1,0);  //run Insertion sort
	gettimeofday(&t2,NULL);			//end time
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	res[1]=elapsedTime;
	return res;
}

int estimateCutoff(Employee* arr,int size){
	int min = 1, max = size;
	//double rleft, rcen, rright;
	//double* res1 = testRun(arr,min);
	//double* res2 = testRun(arr,max);
	double* currres;
	//assert(res1[1]<=res1[0]);
	//assert(res2[1]>=res2[0]);
	
	int mid = (min+max)/2;
	int prevmid = -1;
	Employee newarr[size];
	while(mid!=prevmid){
		prevmid = mid;
		
		for(int i=0;i<mid;i++) newarr[i]=arr[i];
		currres = testRun(newarr, mid);
		if(currres[0]<currres[1]) min = mid;
		else max = mid;
		
		mid=(min+max)/2;
	}
	return mid;
}

int main(int argc, char* argv[]){
	FILE *filept = fopen(argv[1],"r");
	char* out = "output.txt";
	FILE *of = fopen(argv[2],"a");
	FILE *outputfile = fopen(out,"a");
	int size = atoi(argv[1]);
	Employee* arr = (Employee*)malloc((size+1)*sizeof(Employee));
	readFile(filept,arr);
	arr[size] = arr[size-1];
	fclose(filept);
	printArray(arr,size);
	int t = estimateCutoff(arr,size);
	printf("Est cutoff is %d\n",t);
	
	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);
	QuickSortIter(arr,0,size,t);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printArray(arr,size);
    for(int i=0;i<size;i++) fprintf(of,"%s %d\n",arr[i].name,arr[i].empID);
  	fclose(of);
	fprintf(outputfile, "Time Taken to sort %d elements with customSort cutoff %d: %lf milliseconds.\n",size,t,elapsedTime);
	fclose(outputfile);
	printf("Time Taken to sort %d elements with customSort cutoff %d: %lf milliseconds.\n",size,t,elapsedTime);
}