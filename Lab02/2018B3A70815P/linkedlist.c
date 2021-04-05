/* linkedlist.c */
#include<stdlib.h>
#include "linkedlist.h"
void insertFirst(struct linkedList * head, int ele){
	//create a node
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->element = ele;
	 
	//point to the old first node
	link->next = head->first;

	//point first to new first node
	head->first = link;
	head->count++;
}

struct node* deleteFirst(struct linkedList * head){
	struct node *temp = head->first;
	head->first = temp->next;
	head->count--;
	free(temp);
	return head->first;
}

void printList(struct linkedList* head){
	struct node *ptr = head->first;
	printf("\n[ ");
	while(ptr!=NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf("]");
}

int search(struct linkedList *head, int ele){
	struct node* curr = head->first;
	while(curr!=NULL){
		if(curr->element==ele) return 1;
		curr = curr->next;
	}
	return 0;
}

struct node * delete(struct linkedList *head, int ele){
	if(search(head, ele)==0){
		printf("Element does not exist in the linked list. Could not delete!\n");
		return NULL;
	}
	struct node* curr = head->first;
	if(curr->element==ele){
		//struct node* temp = head->first;
		head->first = curr->next;
		free(curr);
		return head->first;
	}
	struct node* prev = curr;
	curr = curr->next;
	while(curr!=NULL){
		if(curr->element==ele){
			prev->next = curr->next;
			free(curr);
			return head->first;
		}
		prev = curr;
		curr = curr->next;
	}
	return head->first;
}
