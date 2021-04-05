/* quicksort.c */
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"quicksort.h"
#include"insertionsort.h"
void swap(Employee a, Employee b){
	Employee temp = b;
	b = a;
	a = temp;
}
int partition(Employee* arr, int p, int r){
	int x = arr[r].empID;
	int i = p;
	for(int j=p;j<r;j++){
		if(arr[j].empID<=x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[r]);
	return i;
}
void QuickSortIter(Employee* arr, int s, int e, int S){
	if(S>1 && (e-s+1)<=S){
		InsertionSortIter(arr,s,e);
		return;
	}
	IPStack* stack = newStack();
	push(stack,s,e);
	while(stack->size>0){
		IPNode* temp = pop(stack);
		int l = temp->l;
		int r = temp->r;
		int next = partition(arr,l,r);
		if(next-1>l){
			if(S>1 && (next-l)<=S) InsertionSortIter(arr,l,next-1);
			else push(stack,l,next-1);
		}
		if(next+1<r){
			if(S>1 && (r-next)<=S) InsertionSortIter(arr,next+1,r);
			else push(stack,next+1,r);
		}
	}
}
/* end of quicksort.c */
