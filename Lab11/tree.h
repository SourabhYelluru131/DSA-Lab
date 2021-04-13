/* tree.h */
#include<stdio.h>

typedef struct leaf{
	char* IPAdd;
}Leaf;

typedef struct node{
	char* dName;
	struct node** children;
	struct leaf* leaf;
}Node;

Node* createTree(int N);
char** breakIntoArray(char* name,int* lent);
Node* insertIntoTree(Node* root,char* name, char* ip,int N);
Node* readFile(FILE* f);
void find(Node* root, char* domain);
/* end of tree.h */
