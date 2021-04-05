/* multiq.c */
#include <stdbool.h>
#include <stdlib.h>
//#include "linkedlist.h"
#include "que.h"
#include "multiq.h"
MultiQ* createMQ(int num){
	MultiQ* lq = (MultiQ*) malloc(sizeof(MultiQ));
	lq->list = (Queue**) malloc(num*sizeof(Queue*));
	for(int i=0;i<num;i++){
		Queue* mq = newQ();
		(lq->list)[i]=mq; 
	}
	lq->size=num;
	return lq;
}
MultiQ* addMQ(MultiQ* mq, Task* t){
	int pp = t->priority-1;
	Queue* qq = (mq->list)[pp];
	qq = addQ(qq, t);
	return mq;
}
Task* nextMQ(MultiQ* mq){
	int i;
	for(i=mq->size-1;i>=0;i--){
		if(isEmptyQ((mq->list)[i])){
			if(i==0) return NULL;
		}
		else break;
	}
	Task* tt = front((mq->list)[i]);
	return tt;
}
MultiQ* delNextMQ(MultiQ* mq){
	int i;
	for(i=mq->size-1;i>=0;i--){
                if(isEmptyQ((mq->list)[i])){
                        if(i==0) return mq;
                }
                else break;
        }
        Task* tt = front((mq->list)[i]);
        if(tt!=NULL) delQ((mq->list)[i]);
	return mq;
}
bool isEmptyMQ(MultiQ* mq){
	if(nextMQ(mq)) return false;
	else return true;
}
int sizeMQ(MultiQ* mq){
	int count = 0;
	for(int p=1;p<mq->size+1;p++){
		count += sizeMQbyPriority(mq,p);
	}
	return count;
}
int sizeMQbyPriority(MultiQ* mq,int p){
	p = mq->size-p+1;
	Queue * qq = getQueueFromMQ(mq,p);
	return qq->list->count;
}
Queue* getQueueFromMQ(MultiQ* mq, int p){
        Queue* qq = (mq->list)[p-1];
	return qq;
}
MultiQ* loadData(FILE* f){
        MultiQ* mulq = createMQ(10);
        while(!feof(f)){
                int temp1,temp2;
                fscanf(f, "%d,%d", &temp1,&temp2);
                Task* tt = (Task *)malloc(sizeof(Task));
                tt->TaskID = temp1;
                tt->priority = temp2;
                mulq = addMQ(mulq,tt);
        }
        fclose(f);
	return mulq;
}
MultiQ* testDel(MultiQ* mulq,int num){
	int nums = num;
	while(num--){
                Task* tt = nextMQ(mulq);
                mulq = delNextMQ(mulq);
                //printf("%d, %d \n", tt->TaskID, tt->priority);
        }
	Task* tt = nextMQ(mulq);
	if(tt) printf("Deleted %d tasks. Highest priority =  %d\n",nums,tt->priority);
	else printf("Deleted %d tasks. No more tasks remaining\n",nums);
	return mulq;
}
/* end of multiq.c */
