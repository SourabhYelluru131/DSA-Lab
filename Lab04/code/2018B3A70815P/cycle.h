/* cycle.h */
#ifndef cycle
#define cycle 
#include "mymem.h"
#include "linkedlist.h"
#include <stdbool.h>

//typedef enum{FALSE,TRUE} bool;

linkedList* createList(int N);
void createCycle(linkedList* ls);
bool testCyclic(linkedList* ls);
void printls(linkedList* ls);

#endif
/* end of cycle.h */
