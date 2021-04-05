#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
/* Global variables */
int gbooksize=0;

/* structs */
typedef struct node{
	int findex;
	int count;
	struct node* next;
}Node;

typedef struct{
	Node* head;
	Node* tail;
	int length;
}list;

typedef struct {
	list** table;
	int tablesize;
	int base;
	int ecnt;
	int icost;
	int qcost;
}hashT;


/* Function definitions */
int hashify(char * s, int base, int size){
	int len = strlen(s);
	int hash=0;
	for(int i=0;i<len;i++){
		hash+=s[i];
		hash%=base;
	}
	hash%=size;
	return hash;
}


int collisionCount(char** book, int base, int size){
	int arr[size];						//array to record collisions
	memset(arr,0,sizeof(int)*size);		//set arr to all 0s
	int collisions = 0;					//Initially number of collisions=0
	for(int i=0;i<gbooksize;i++){
		int currhash = hashify(book[i],base,size);
		arr[currhash]++;
	}
	for(int i=0;i<size;i++) if(arr[i]>1) collisions+=arr[i]-1;
	return collisions;
}


bool filter(char* str){
	int i;
	for(i=0;i<strlen(str);i++){
		if(!isalpha(str[i])) return 0;		//Checks if string are all alphabets
	}
	return 1;
}


char** parser(FILE *f){
	int noOfStrings=0;
	int currsize=10;
	char** book = (char**)malloc(currsize*sizeof(char*));
	for(int i=0;!feof(f);i++){
		char* temp = (char*)malloc(1000);
		if(i>=currsize){
			currsize*=2;				//In case array size is not enough, increase size
			book = (char**)realloc(book,currsize*sizeof(char*));
		}
		fscanf(f,"%s",temp);			//scan for next string
		if(filter(temp)){				//Only if string is completely alphabet
			book[i]=(char*)malloc(strlen(temp)*sizeof(char));
			strcpy(book[i],temp);		//Adding found string into array
			noOfStrings++;				//Increment count of valid strings found
		}
		else i--;
	}
	fclose(f);
	printf("No of valid strings = %d\n",noOfStrings);
	gbooksize = noOfStrings;
	return book;
}


void profile(char** book, int* i1, int* i2){
	int minc=gbooksize;
	//Select primes in range [5000,5000000],[50000,50000000],[500000,500000000]
	int primes[] ={5001,5009,5011,5000011,5000077,5000081,50021,50023,50033,50000017,50000021,50000047,500009,500029,500041,500000003,500000009,500000041};
	int sizes[] = {5000,50000,500000};
	int arr[18];
	int ind1=0,ind2=0,k=0;
	memset(arr,0,sizeof(int)*18);
	for(int i=0;i<=2;i++){
		for(int j=6*i;j<6*(i+1);j++){
			int c = collisionCount(book,primes[j],sizes[i]);
			arr[k]=c;
			k++;
			if(c<minc){
				minc = c;
				*i1=sizes[i];				//Stores indices of min collision 
				*i2=primes[j];
			}
		}
	}
	for(int i=0;i<18;i++) printf("%d ",arr[i]);
	printf("\n");
	printf("Minimum collisions = %d\n",minc);
}


void printbook(char** book){
	for(int i=0;i<gbooksize;i++){
		printf("%s\n",book[i]);
	}
}


list* createList(){
	list* L = (list*)malloc(sizeof(list));
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	return L; 
}


hashT* createHashTable(int tablesize, int base){
	hashT* ht = (hashT*)malloc(sizeof(hashT));
	ht->table = (list**)malloc(tablesize*sizeof(list*));
	for(int i=0;i<tablesize;i++) (ht->table)[i]=createList();
	ht->base = base;
	ht->tablesize = tablesize;
	ht->ecnt = 0;
	ht->icost=0;
	ht->qcost=0;
	return ht;
}


void insert(hashT* ht, char** book, int index){
	int hash = hashify(book[index],ht->base,ht->tablesize);
	ht->ecnt++;
	list* l = ht->table[hash];
	if(!l->head){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->findex=index;
		temp->count=1;								//First occurence of string
		l->head = temp;
		l->tail = temp;
		l->length=1;								//Size = 1 after adding to empty list
	}
	else{
		Node* curr = l->head;
		while(curr){
			ht->icost++;
			if(!strcmp(book[curr->findex],book[index])){
				curr->count++;						//Found a new occurence of old string
				break;
			}
			else{
				if(!curr->next) break;
				else curr = curr->next;					//Traversing the entire list until 
			}
		}
		if(!curr->next){
			Node* temp = (Node*)malloc(sizeof(Node));	//Add node to end of list
			temp->findex=index;
			temp->count=1;
			curr->next = temp;
			l->tail = temp;
			l->length++;								//Increment length of linked list 
		}
	}
}


int insertAll(char** book, hashT* ht){
	for(int i=0;i<gbooksize;i++) insert(ht,book,i);
	return ht->icost;
}


Node* lookup(hashT* ht, char** book, int index){
	char* s = book[index];
	int hash = hashify(s,ht->base,ht->tablesize);
	Node* curr = ht->table[hash]->head;
	while(curr && strcmp(book[curr->findex],book[index])){
		ht->qcost++;					//Increment qcost as queries increase
		curr=curr->next;
	}
	return curr;						//Returns node corresponding to the string
}


int lookupAll(hashT* ht, char** book, double m){
	ht->qcost=0;						//Resetting query cost in the beginning
	for(int i=0;i<(int)(m*gbooksize);i++) lookup(ht,book,i);
	return ht->qcost;					//Returning query cost at the end
}



	/* MAIN */
	
int main(int argc, char** argv){
	char** books;
	FILE* f = fopen("aliceinwonderland.txt","r");
	books = parser(f);
	//printbook(books);
	int optimumSize, optimumPrime;
	profile(books,&optimumSize, &optimumPrime);
	printf("%d, %d\n",optimumSize,optimumPrime);
	hashT* ht = createHashTable(optimumSize, optimumPrime);
	insertAll(books,ht);
	double m = 0.05;
	int querycost = lookupAll(ht,books,m);
	printf("Query cost (m=%f) = %d\n",m,querycost);
}