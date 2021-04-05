/* merge.h */
typedef struct{
	char name[10];
	float cgpa;
} student;

void printStudent(student* stud);
void printArray(student** arr,int n);
void mergeSortRec(student** arr, int s, int e);
void merge(student** Ls1, int sz1, student** Ls2, int sz2,student** mrg);
/* end of merge.h */
