/* cycle2.c */
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
                if(curr->next) curr = curr->next;
        }
        ls->tail = curr;
        FILE* fptr;
        fptr = fopen("createListOutput.txt","w");
        fprintf(fptr,"Current memory allocated is : %ld\n",totalmem);
        fclose(fptr);
        return ls;
}

/*
void createCycle(linkedList * ls){
        int N = ls->size;
        srand(time(NULL)+1);
        if(rand()%2==0){
		printf("Cycling...\n");
                int rr = rand()%1000;
                Node* curr = ls->head;
                while(*(int*)curr->element != rr) curr = curr->next;
                ls->tail->next = curr;
        }
}
*/

void createCycle(linkedList* ls){
        srand(time(NULL)+1);
        if(rand()%2){
                printf("linkedlist is being converted to a cycled linkedlist...\n");
                int llsize = ls->size;
                Node* current = ls->head;
                int r = rand()%(llsize);
                printf("%d\n",r);
                while(r-- > 0){
                        current= current->next;
                }
                ls->tail->next = current;
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

linkedList* reverseList(linkedList* ls){
	Node* l, *m, *r;
	l = ls->head;
	m = l->next;
	r = m->next;
	l->next = NULL;
	while(r!=NULL){
		m->next = l;
		l = m;
		m = r;
		r = r->next;
	}
	m->next = l;
	ls->head = m;
	return ls;
}

bool testCyclic(linkedList* ls){
	if(ls->size<3) return false;
	Node* currhead = ls->head;
	ls = reverseList(ls);
	if(ls->head==currhead) return true;
	return false;
}

/* end of cycle2.c */
