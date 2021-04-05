/* driver.c */
#include<stdio.h>
#include<stdlib.h>
#include "record.h"
#include"spaceAndTime.h"
#include<sys/time.h>

int main(int argc,char *argv[]){
	int size;
	record** arr = measureReadTime(argv[1],&size);
	measureSortTimeAndSpace(arr,&size);
	//printArray(arr,size);
}
/* end of driver.c */
