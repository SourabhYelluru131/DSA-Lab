/* linkedlist.h */
#ifndef linkedlist
#define linkedlist
#include <stdio.h>

struct Node{
	void* element;
	struct Node* next;
};
typedef struct Node Node;

typedef struct linkedList{
	Node* head;
	int size;
	Node* tail;
} linkedList;

#endif
/* end of linkedlist.h */
