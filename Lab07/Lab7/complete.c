/* complete.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <math.h>
//Struct definitions

typedef struct{
	int empID;
	char name[10];
}Employee;
typedef struct IPNode{
	int l;
	int r;
	struct IPNode* next;
}IPNode;
typedef struct{
	IPNode* top;
	int size;
}IPStack;

//Function definitions

//Stack
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

//Employee
void printArray(Employee* arr, int size){
	for(int i=0;i<size;i++){
		printf("{Name: %s, ID: %d }\n",arr[i].name, arr[i].empID);
	}
}
void readFile(FILE* f, Employee* arr){
	int i=0;
	while(!feof(f)){
		fscanf(f,"%[^ ] %d ",arr[i].name, &arr[i].empID);
		i++;
	}
}
//Insertion Sort
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

//Quick Sort
void swap(Employee a, Employee b){
	Employee temp = b;
	b = a;
	a = temp;
}
int partition(Employee* arr, int p, int r){
	int x = arr[r].empID;
	int i = p;
	for(int j=p;j<r;j++){
		if(arr[j].empID<=x){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[r]);
	return i;
}
void QuickSortIter(Employee* arr, int s, int e, int S){
	if(S>1 && (e-s+1)<=S){
		InsertionSortIter(arr,s,e);
		return;
	}
	IPStack* stack = newStack();
	push(stack,s,e);
	while(stack->size>0){
		IPNode* temp = pop(stack);
		int l = temp->l;
		int r = temp->r;
		int next = partition(arr,l,r);
		if(next-1>l){
			if(S>1 && (next-l)<=S) InsertionSortIter(arr,l,next-1);
			else push(stack,l,next-1);
		}
		if(next+1<r){
			if(S>1 && (r-next)<=S) InsertionSortIter(arr,next+1,r);
			else push(stack,next+1,r);
		}
	}
}


//Test
double* testRun(Employee* arr, int n){
	double* res = (double*)malloc(2*sizeof(double));				//Results of the run
	struct timeval t1, t2;
	double elapsedTime;
	Employee* newarr = (Employee*)malloc(n*sizeof(Employee));	//making a copy
	for(int i=0;i<n;i++) newarr[i]=arr[i];
	
	gettimeofday(&t1,NULL);     //start time
	InsertionSortIter(arr,0,n-1);     //run Quick sort
	gettimeofday(&t2,NULL);		//end time
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	res[0]=elapsedTime;
	
	gettimeofday(&t1,NULL);     	//start time
	QuickSortIter(newarr,0,n-1,0);  //run Insertion sort
	gettimeofday(&t2,NULL);			//end time
	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	res[1]=elapsedTime;
	return res;
}

//ESTIMATE CUTOFF
int estimateCutoff(Employee* arr,int size){
	int min = 1, max = size;
	//double rleft, rcen, rright;
	//double* res1 = testRun(arr,min);
	//double* res2 = testRun(arr,max);
	double* currres;
	//assert(res1[1]<=res1[0]);
	//assert(res2[1]>=res2[0]);
	
	int mid = (min+max)/2;
	int prevmid = -1;
	Employee newarr[size];
	while(mid!=prevmid){
		prevmid = mid;
		
		for(int i=0;i<mid;i++) newarr[i]=arr[i];
		currres = testRun(newarr, mid);
		if(currres[0]<currres[1]) min = mid;
		else max = mid;
		
		mid=(min+max)/2;
	}
	return mid;
}

//MAIN
int main(int argc, char* argv[]){
	FILE *filept = fopen(argv[1],"r");
	char* out = "output.txt";
	FILE *of = fopen(argv[2],"a");
	FILE *outputfile = fopen(out,"a");
	int size = atoi(argv[1]);
	Employee* arr = (Employee*)malloc((size+1)*sizeof(Employee));
	readFile(filept,arr);
	arr[size] = arr[size-1];
	fclose(filept);
	printArray(arr,size);
	int t = estimateCutoff(arr,size);
	printf("Est cutoff is %d\n",t);
	
	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);
	QuickSortIter(arr,0,size,t);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printArray(arr,size);
    for(int i=0;i<size;i++) fprintf(of,"%s %d\n",arr[i].name,arr[i].empID);
  	fclose(of);
	fprintf(outputfile, "Time Taken to sort %d elements with customSort cutoff %d: %lf milliseconds.\n",size,t,elapsedTime);
	fclose(outputfile);
	printf("Time Taken to sort %d elements with customSort cutoff %d: %lf milliseconds.\n",size,t,elapsedTime);
}
/* end of complete.c */
