/* record.c */
#include<stdio.h>
#include <stdlib.h>
#include "record.h"

record* newRecord(){
	record* r = (record*)malloc(sizeof(record));
	r->Bcode = (char*)malloc(5*sizeof(char));
	r->Fname = (char*)malloc(5*sizeof(char));
	r->Lname = (char*)malloc(5*sizeof(char));
	return r;
}

void insertInOrder(record** arr, int size,record* rec){
	record* temp;
	int i=0;
	while(arr[i]->CNo<rec->CNo) i++;
	for(;i<=size-1;i++){
		temp = arr[i];
		arr[i]=rec;
		rec=temp;
	}
}

void insertionSort(record** arr, int n){
	if(n==0){
		stacktop=&n;
		return;
	}
	insertionSort(arr,n-1);
	insertInOrder(arr,n,arr[n-1]);
} 
	
void printArray(record** arr,int size){
	for(int i=0;i<size;i++) printf("%llu, ",arr[i]->CNo);
	printf("\n");
}

/* end of record.c */
