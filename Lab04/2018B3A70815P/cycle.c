/* cycle.c */
#include "cycle.h"
#include "linkedlist.h"
#include <time.h>

linkedList* createList(int N){
	srand(time(NULL));
	linkedList* ls = (linkedList*)myalloc(sizeof(linkedList));
	ls->head = (Node *)myalloc(sizeof(Node*));
	(ls->head->element) = (int *)myalloc(sizeof(int));
	*(int*)(ls->head->element) = rand()%1000;
	ls->size = 1;
	Node* curr = ls->head;
	for(int i=0;i<N-1;i++){
		Node* temp = (Node *)myalloc(sizeof(Node*));
		curr->next = temp;
		ls->size = ls->size + 1;
		curr->element = (int *)myalloc(sizeof(int*));
        	*(int *)(curr->element) = rand()%1000;
		temp->next = NULL;
		if(curr->next) curr = curr->next;
	}
	ls->tail = curr;
	FILE* fptr;
	fptr = fopen("createListOutput.txt","w");
	fprintf(fptr,"Current memory allocated is : %ld\n",totalmem);
	fclose(fptr);
	return ls;		
}
void createCycle(linkedList * ls){
	int N = ls->size;
	srand(time(NULL)+1);
	if(rand()%2==0){
		int rr = rand()%1000;
		Node* curr = ls->head;
		while(*(int*)curr->element != rr) curr = curr->next;
		ls->tail->next = curr;
	}
}

bool testCyclic(linkedList* ls){
	return false;
}

/* end of cycle.c */
