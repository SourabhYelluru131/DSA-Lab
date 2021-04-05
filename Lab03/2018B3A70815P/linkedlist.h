/* linkedlist.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdio.h>
//structur definitions
//structure of a linked list node
struct node{
	void* element;
	struct node* next;
};
struct linkedList{
	int count;
	struct node * first;
};
typedef struct linkedList linkedList;
//function declarations
void insertFirst(linkedList * head, void* ele);
void insertLast(linkedList * head, void* ele);
struct node * deleteFirst(linkedList * head);
/* End of linkedlist.h */
#endif
