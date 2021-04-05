/* stack.c */
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

IPStack* newStack(){
	IPStack* stack = (IPStack*)malloc(sizeof(IPStack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}
void push(IPStack* stack, int a, int b){
	IPNode* node = (IPNode*)malloc(sizeof(IPNode));
	node->l = a;
	node->r = b;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}
IPNode* pop(IPStack* stack){
	IPNode* node;
	if(stack->size==0){
		node->l = -1;
		node->r = -1;
		node->next = NULL;
		return node;
	}
	node = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	return node;
}
/* end of stack.c */
