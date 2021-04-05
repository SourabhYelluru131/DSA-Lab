/* merge.c */
#include "merge.h"
#include<stdio.h>
#include<stdlib.h>

int strcomp(char* a, char*b){
	int i=0,n=10;
	while(i<n && a[i]==b[i]) i++;
	if(i!=n){
		if(a[i]<b[i]) return -1;
		return 1;
	}
	return 0;
}
void printStudent(student* stud){
	printf("[Name: %s, CGPA: %f],\n",stud->name, stud->cgpa);
}
void printArray(student** arr,int n){
	for(int i=0;i<n;i++) printStudent(arr[i]);
}
int compare(student* a, student*b){
	if(a->cgpa < b->cgpa) return 1;
	else{
		if(a->cgpa == b->cgpa && strcomp(a->name,b->name)<0) return 1;
	}
	return 0;
}
void merge(student** Ls1, int sz1, student** Ls2, int sz2,student** mrg){
	if(sz1<=0 && sz2<=0) return;
	int i=0,j=0,k=0;
	while(i<sz1 && j<sz2){
		if(compare(Ls1[i],Ls2[j])){
			mrg[k]=Ls1[i];
			i++;
		}
		else{
			mrg[k]=Ls2[j];
			j++;
		}
		k++;
	}
	if(i<sz1){
		while(i<sz1){
			mrg[k]=Ls1[i];
			i++;
			k++;
		}
	}
	else{
		while(j<sz2){
			mrg[k]=Ls2[j];
			j++;
			k++;
		}
	}
}
void mergeSortRec(student** arr, int s, int e){
	if(s>=e) return;
	student** temp = (student**)malloc((e-s+1)*sizeof(student*));
	int m = (s+e)/2;
	mergeSortRec(arr,s,m);
	mergeSortRec(arr,m+1,e);
	merge(arr+s, m-s+1, arr+m+1, e-m, temp);
	for(int i=0;i<e-s+1;i++) arr[s+i]=temp[i];
	free(temp);
}

void mergeSortIter(student** arr, int s, int e){
	int m;
	for(int i=1;i<e-s+1;i*=2){
		for(int j=0;j<e-s+1;j+=2*i)
	}
}
/* end of merge.c */
