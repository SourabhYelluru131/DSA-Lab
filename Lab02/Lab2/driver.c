/* driver.c */
#include<stdlib.h>
#include<stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){
	FILE *fileptr = fopen(argv[1],"r");
	struct linkedList *head = (struct linkedList *) malloc(sizeof(struct linkedList));
	while(!feof(fileptr)){
		int temp;
		fscanf(fileptr, "%d ", &temp);
		insertFirst(head,temp);
	}
	fclose(fileptr);
	printList(head);
	head->first = deleteFirst(head);
	printList(head);
	FILE *fileptr2 = fopen("sampleOutput.txt","w");
	struct node* curr = head->first;
	while(curr!=NULL){
		int elem = curr->element;
		fprintf(fileptr2,"%d\n", elem);
		curr = curr->next;
	}
	fclose(fileptr2);
	//printf("\nsearching 9: %d\n",search(head,9));
	//head->first = delete(head,9);
	//printList(head);
	//printf("\nsearching 9: %d\n",search(head,9));
	//head->first = delete(head,9);
}
