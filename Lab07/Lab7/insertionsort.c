/* insertionsort.c */
#include"employee.h"

void insert(Employee* arr, int n, Employee emp){
	Employee curr = emp,temp;
	for(int i=0;i<n;i++){
		if(curr.empID < arr[i].empID || i==n-1){
			temp = arr[i];
			arr[i] = curr;
			curr = temp;
		}
	}
}
void InsertionSortIter(Employee* arr,int s, int e){
	for(int i=s;i<e;i++) insert(arr,i+1,arr[i]);
}
/* end of insertionsort.c */
