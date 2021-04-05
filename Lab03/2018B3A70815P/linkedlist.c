/* linkedlist.c */
#include<stdlib.h>
#include "linkedlist.h"
void insertFirst(struct linkedList * head, void* ele){
	//create a node
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->element = ele;
	 
	//point to the old first node
	link->next = head->first;

	//point first to new first node
	head->first = link;
	head->count++;
}
void insertLast(struct linkedList * head, void* ele){
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->element = ele;
	link->next = NULL;
	struct node* curr = head->first;
	while(curr->next) curr = curr->next;
	curr->next = link;
	head->count++;
}
struct node* deleteFirst(struct linkedList * head){
	struct node *temp = head->first;
	head->first = temp->next;
	head->count--;
	free(temp);
	return head->first;
}

