/* driver.c */
#include<stdio.h>
#include<stdlib.h>
#include"merge.h"

int main(int argc, char* argv[]){
	FILE* f = fopen(argv[1],"r");
	int n = atoi(argv[1]);
	student** sList = (student**)malloc(n*sizeof(student*));
	for(int i=0;i<n;i++) sList[i]=(student*)malloc(sizeof(student));
	int i=0;
	while(!feof(f)){
		fscanf(f,"%[^,],%f\n",sList[i]->name,&sList[i]->cgpa);
		i++;
	}
	mergeSortRec(sList,0,n-1);
	printArray(sList,n);
}
/* end of driver.c */
