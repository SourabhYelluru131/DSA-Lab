/* tree.c */
#include"tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Node* createTree(int N){
	Node* root = (Node*)malloc(sizeof(Node));
	root->dName=NULL;
	root->children = (Node**)malloc(N*sizeof(Node*));		//N is not required, but worst case
	root->leaf = NULL;
	return root;
}

char** breakIntoArray(char* name,int* lent){
	char** names = NULL;
	int len = 0;
	char* p = strtok(name,".");
	while(p){
		names = realloc(names,sizeof(char*) * ++len);
		if(names==NULL) exit(-1);								//Memory allocation failure
		names[len-1]=p;
		p=strtok(NULL,".");
	}
	names = realloc(names,sizeof(char*)*(len+1));
	names[len]=0;
	*lent = len;
	return names;
}

Node* insertIntoTree(Node* root,char* name, char* ip,int N){
	int len;
	Node* curr = root;
	char** names = breakIntoArray(name,&len);
	for(int i=len-1;i>=0;i--){
		if(curr->children[0]==NULL){
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->children = (Node**)malloc(N*sizeof(Node*));
			temp->dName = names[i];
			curr->children[0]=temp;
			curr=curr->children[0];
		}
		else{
			int j=0;
			while(curr->children[j]!=NULL && strcmp(curr->children[j]->dName,names[i])!=0) j++;
			if(curr->children[j]==NULL){
				Node* temp = (Node*)malloc(sizeof(Node));
				temp->children = (Node**)malloc(N*sizeof(Node*));
				temp->dName = names[i];
				curr->children[j]=temp;
			}
			curr=curr->children[j];
		}
	}
	curr->leaf = (Leaf*)malloc(sizeof(Leaf));
	curr->leaf->IPAdd = ip;
	return root;
}

void find(Node* root, char* domain){
	int len;
	Node* curr = root;
	int arr[10];
	for(int i=0;i<10;i++) arr[i]=-1;
	int k=0;
	char** names = breakIntoArray(domain,&len);
	for(int i=len-1;i>=0;i--){
		int j=0;
		while(curr->children[j]!=NULL && strcmp(curr->children[j]->dName,names[i])!=0) j++;
		if(curr->children[j]!=NULL){
			arr[k]=j;
			k++;
			curr=curr->children[j];
		}
		else{
			int ind = 0;
			while(arr[ind]!=-1){
				printf("%d ",arr[ind]);
				ind++;
			}
			printf("\n");
			return;
		}
	}
	if(curr->leaf) printf("%s ",curr->leaf->IPAdd);
	printf("\n");
}

Node* readFile(FILE* f){
	int a,N;
	fscanf(f,"%d %d",&a,&N);
	Node* root = createTree(N); 
	for(int i=0;i<N;i++){
		char* Name, *IP, namet[100],ipt[100];
		fscanf(f,"%s %s",namet,ipt);
		Name = malloc(sizeof(char)*strlen(namet));
		IP = malloc(sizeof(char)*strlen(ipt));
		strcpy(Name,namet);
		strcpy(IP,ipt);
		insertIntoTree(root,Name,IP,N);
	}
	while(!feof(f)){
		int a;
		char dom[100],*domName;
		fscanf(f,"%d %s",&a,dom);
		domName = malloc(sizeof(char)*strlen(dom));
		strcpy(domName,dom);
		if(a==-1) break;
		printf("%s -> ",domName);
		find(root,domName);
	}
	fclose(f);
	return root;
}
/* end of tree.c */
