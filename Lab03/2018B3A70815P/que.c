/* que.c*/
#include <stdbool.h>
#include <stdlib.h>
#include "multiq.h"
#include "que.h"
Queue* newQ(){
	Queue* qp = (Queue*)malloc(sizeof(Queue));
	qp->list = (linkedList*)malloc(sizeof(linkedList));
	qp->tail = qp->list->first;
	return qp; 
}
bool isEmptyQ(Queue* q){
	return q->list->count==0;
}
Queue* delQ(Queue* q){
	struct node *temp = q->list->first;
	q->list->first = deleteFirst(q->list);
	return q;
}
void* front(Queue* q){
	if(!q->list || !q->list->first|| !q->list->first->element) return NULL;
	return q->list->first->element;
}
Queue* addQ(Queue* q, void* e){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->element = e;
	temp->next = NULL;
	linkedList *ll = q->list;
	struct node* curr = ll->first;
	int cnt = 0;
	while(curr && curr->next){
		curr = curr->next;
		cnt++;
	}
	if(curr) curr->next = temp;
	else{
		curr = temp;
		curr->next = NULL;
		ll->first = curr;
	}
	ll->count++;
	q->list = ll;
	q->tail = temp;
	return q;
}
int lengthQ(Queue* q){
	return q->list->count;
}
/* end of que.c */
