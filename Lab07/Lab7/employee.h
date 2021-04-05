/* employee .h */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<stdio.h>
typedef struct{
	int empID;
	char name[10];
}Employee;

void printArray(Employee* arr, int size);
void readFile(FILE* f, Employee* arr);
#endif

/* end of employee.h */
