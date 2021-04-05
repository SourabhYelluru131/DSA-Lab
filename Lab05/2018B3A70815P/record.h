/* record.h */
#include<stdio.h>
int* stacktop;
typedef struct Date{
        int month;
        int year;
}date;
typedef struct record{
        unsigned long long int CNo;
        char* Bcode;
        date exp;
        char* Fname;
        char* Lname;
}record;

record* newRecord();
void insertInOrder(record** arr,int size,record* rec);
void insertionSort(record** arr,int size);
void writeTo(FILE* f, record** arr, int size);
void printArray(record** arr, int size);

/* end of record.h */
