/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"
#include "multiq.h"
int main(int argc, char *argv[]){
        FILE *filept = fopen(argv[1],"r");
        MultiQ* mulq = createMQ(10);
	while(!feof(filept)){
                int temp1,temp2;
                fscanf(filept, "%d,%d", &temp1,&temp2);
                Task* tt = (Task *)malloc(sizeof(Task));
		tt->TaskID = temp1;
		tt->priority = temp2;
		mulq = addMQ(mulq,tt);
        }
        fclose(filept);
	printf("After adding, total size = %d \n", sizeMQ(mulq));
        for(int i=1;i<11;i++) printf("%d ", sizeMQbyPriority(mulq,i));
	printf("\n");
	int cnt = 0;
	while(!isEmptyMQ(mulq)){
		cnt++;
		Task* tt = nextMQ(mulq);
		mulq = delNextMQ(mulq);
		printf("%d\n",cnt);
		printf("%d, %d \n", tt->TaskID, tt->priority);
	}
}
/* end of driver.c */ 
