/* cycle1.c */
#include <stdio.h>
#include <sys/time.h>
#include "cycle.h"

linkedList* createList(int N){
        srand(time(NULL));
        linkedList* ls = (linkedList*)myalloc(sizeof(linkedList));
        ls->head = (Node *)myalloc(sizeof(Node));
        (ls->head->element) = (int *)myalloc(sizeof(int));
        *(int*)(ls->head->element) = rand()%1000;
        ls->size = 1;
        Node* curr = ls->head;
        for(int i=0;i<N-1;i++){
                Node* temp = (Node *)myalloc(sizeof(Node));
                curr->next = temp;
                ls->size = ls->size + 1;
                curr->element = (int *)myalloc(sizeof(int));
                *(int *)(curr->element) = rand()%1000;
                temp->next = NULL;
                curr = curr->next;
        }
        FILE* fptr;
        fptr = fopen("createListOutput.txt","w");
        fprintf(fptr,"Current memory allocated is : %ld\n",totalmem);
        fclose(fptr);
        return ls;
}

/*
void createCycle(linkedList* ls){
	srand(time(NULL)+1);
	if(rand()%2){
		printf("Cycling\n");
		Node* current = ls->head;
		int r = rand()%1000;
		printf("%d\n",r);
		while(*(int*)current->element != r){
			current= current->next;
		}
		ls->tail->next = current;
	}
}
*/
void createCycle(linkedList* ls){
        srand(time(NULL)+1);
        if(rand()%2){
                printf("linear -> cyclic\n");
		int llsize = ls->size;
                Node* current = ls->head;
                int r = rand()%(llsize);
                printf("%d\n",r);
                while(r-- > 0){
                        current= current->next;
                }
		Node* temp = current;
		while(current->next!=NULL) current = current->next;
		current->next = temp;
        }
}

void printls(linkedList* ls){
	int N = ls->size;
	N+=2;
	Node* curr = ls->head;
	while(N-- && curr){
		printf("%d\n",*(int*)(curr->element));
		curr = curr->next;
	}
	printf("Done\n");
}

bool testCyclic(linkedList* ls){
        if(ls->size<3) return false;
	Node *turtle, *hare;
	hare = ls->head;
	turtle = ls->head;
	int n = 0;
	while(hare!=NULL && hare->next!=NULL && hare->next->next!=NULL){
		hare = hare->next->next;
		n+=2;
		turtle = turtle->next;
		if(hare==NULL|| hare->next==NULL || turtle==NULL){
			printf("NULL at n = %d\n",n);
			return false;
		}
		if(hare==turtle) return true;
	}
	printf("2\n");
	return false;
}

/* end of cycle1.h */
