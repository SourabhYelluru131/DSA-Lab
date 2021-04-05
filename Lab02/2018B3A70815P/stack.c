/* stack.c */
#include "stack.h"
#include "linkedlist.h"
void push(Stack* st, int elem){
	insertFirst(st, elem);
}
struct node* pop(Stack* st){
	if(st->count==0){
		printf("Stack empty.Cannot pop!");
		return NULL;
	}
	st->first = deleteFirst(st);
	return st->first;
}
