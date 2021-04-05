/* customsort.c */
#include "customsort.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "employee.h"
void customSort(Employee* arr, int s, int e){
	QuickSortIter(arr,s,e);
	InsertionSortIter(arr,s);
}
/* end of customsort.c */
