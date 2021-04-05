/* employee.c */
#include<stdio.h>
#include<stdlib.h>
#include"employee.h"

void printArray(Employee* arr, int size){
	for(int i=0;i<size;i++){
		printf("{Name: %s, ID: %d }\n",arr[i].name, arr[i].empID);
	}
}
void readFile(FILE* f, Employee* arr){
	int i=0;
	while(!feof(f)){
		fscanf(f,"%[^ ] %d ",arr[i].name, &arr[i].empID);
		i++;
	}
}
/* end of employee.c */
