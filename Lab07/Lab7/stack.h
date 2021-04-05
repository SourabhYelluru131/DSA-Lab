/* stack.h */
#ifndef STACK_H
#define STACK_H

typedef struct IPNode{
	int l;
	int r;
	struct IPNode* next;
}IPNode;
typedef struct{
	IPNode* top;
	int size;
}IPStack;

IPStack* newStack();
void push(IPStack* stack, int a, int b);
IPNode* pop(IPStack* stack);
#endif
/* end of stack.h */
