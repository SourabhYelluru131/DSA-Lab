/* multiq.h */
#ifndef MULTIQ_H
#define MULTIQ_H
#include <stdio.h>
#include "que.h"
typedef struct Task{
	int TaskID;
	int priority;
} Task;
typedef struct MultiQ{
	Queue** list;
	int size;
}MultiQ;
MultiQ* createMQ(int num);
MultiQ* addMQ(MultiQ* mq, Task* t);
Task* nextMQ(MultiQ* mq);
MultiQ* delNextMQ(MultiQ* mq);
bool isEmptyMQ(MultiQ* mq);
int sizeMQ(MultiQ* mq);
int sizeMQbyPriority(MultiQ* mq, int p);
Queue* getQueueFromMQ(MultiQ* mq, int p);
MultiQ* loadData(FILE* f);
MultiQ* testDel(MultiQ* mq, int num);
/* end of multiq.h */
#endif
