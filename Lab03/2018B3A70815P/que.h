/* que.h */
//#include "linkedlist.h"
#ifndef QUE_H
#define QUE_H
#include "linkedlist.h"
typedef struct Queue{
	linkedList* list;
	struct node* tail;
}Queue;
Queue* newQ();
bool isEmptyQ(Queue* q);
Queue* delQ(Queue* q);
void* front(Queue* q);
Queue* addQ(Queue* q, void* e);
int lengthQ(Queue* q);
/* End of que.h */
#endif
