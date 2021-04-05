/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"
int main(int argc, char *argv[]){
	FILE *filept = fopen(argv[1],"r");
	Stack * mystack = (Stack *)malloc(sizeof(Stack));
	while(!feof(filept)){
		int temp;
		fscanf(filept, "%d ", &temp);
		push(mystack,temp);
	}
	fclose(filept);
	//printList(mystack);
	//printf("%d",pop(mystack));
	printf("\nStack -> ");
	while(mystack->count>0){
		printf("%d ,",mystack->first->element);
		mystack->first = pop(mystack);
	}
}
