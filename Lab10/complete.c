/* complete.c */
#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int value;
	struct node* left;
	struct node* right;
	int bal;
}Node;


Node* AVLROOT;


Node* parent(Node* root,Node* target){
	if(!root || !target || root==target) return NULL;
	if(target->value > root->value){
		if(root->right->value != target->value) return parent(root->right,target);
		else return root;
	}
	else{
		if(root->left->value != target->value) return parent(root->left,target);
		else return root;
	}
}


Node* find(Node* node,int value){
	if(!node) return NULL;
	if(node->value==value) return node;
	else{
		if(node->value>value) return find(node->left,value);
		else return find(node->right,value);
	}
}


int max(int a,int b){
	return a>b ? a : b;
}


int min(int a, int b){
	return a<b ? a : b;
}


int isAVL(Node* root){
	int left,right;
	if(!root)
		return 0;
	left = isAVL(root->left);
	if(left == -1)
	{
		return left;
	}
	right =  isAVL(root->right);
	if(right == -1)
		return right;
	if(abs(left-right)>1)
	{
	return -1;
	}
	return max(left,right)+1;
}



Node* right_rotate(Node* x){
	/*
				x		=		y
			   / \		=	   /  \
			  y   z		=	  t1   x
			 /  \       =		  /  \
			t1  t2		=		 t2   z
	*/
	Node* y = x->left;
	Node* z = x->right;
	Node* t1 = y->left;
	Node* t2 = y->right;
	y->right = x;
	x->left = t2;
	x->bal = x->bal + 1 - min(y->bal, 0);
	y->bal = y->bal + 1 + max(x->bal, 0);
	return y;
}


Node* left_rotate(Node* x){			// return top node after rotate
	/*
				x		=		y
			   / \		=	   /  \
			  t1  y		=	  x   t3
			 	 /  \ 	=	 /  \
				t2  t3	=	t1  t2
	*/
	Node* y = x->right;
	Node* t1 = x->left;
	Node* t2 = y->left;
	Node* t3 = y->right;
	y->left = x;
	x->right = t2;
	x->bal = x->bal - 1 - max(y->bal, 0);
	y->bal = y->bal - 1 + min(x->bal, 0);
	return y;
}


Node* rotate(Node* x,Node* y, Node* z){			//return the top node
	//x = grandparent, y = parent, z = self
	if(!x || !y || !z) return x;
	if(AVLROOT==x) AVLROOT=y;
	//printf("%d %d %d\n",x->value,y->value,z->value);
	if(x->value < y->value && y->value < z->value){				//Right imbalance tree
		return left_rotate(x);							
	}
	else{
		if(x->value < z->value && z->value < y->value){			//RL Rotation
			x->right = right_rotate(y);
			return left_rotate(x);
		}
		else{
			if(x->value > y->value && y->value > z->value){		//Left imbalance tree
				
				return right_rotate(x);
			}
			else{									//LR Rotation
				if(x->value>z->value && z->value>y->value){
					x->left = left_rotate(y);
					return right_rotate(x);
				}
			}
		}
	}
	return x;
}



Node* delete(Node* node, int value){
	if(!node) return NULL;																//search unsuccessful
	if(node->value>value){
		node->left = delete(node->left,value);
		if(node->right){
			if(node->right->bal==0 || node->right->bal==1) return left_rotate(node);	//L0 & L1 rotation
			else{
				node->right = right_rotate(node->right);									//L-1 rotation
				return left_rotate(node);
			}
			return node;
		}
	}
	else{
		if(node->value<value){
			node->right = delete(node->right,value);
			if(node->left){
				if(node->left->bal==0 || node->left->bal==1) return right_rotate(node);		//R0 & R1 rotation
				else{
					node->left = left_rotate(node->left);									//R-1 rotation
					return right_rotate(node);
				}
			}
			return node;
		}
		else{
			if(!node->left && !node->right){
				free(node);
				return NULL; 											//Leaf node
			}
			if(!node->right && node->left) {							//Left node exists but right is NULL
				Node* temp =  node->left;
				free(node);
				return temp;
			}							
			Node* temp = node->right;									//Other case -> Right node eixts
			while(temp->left) temp=temp->left;
			node->value = temp->value;
			//printf("%p %p \n",node->right,temp);
			node->right = delete(node->right,temp->value);
			//printf("Reached here\n");
			return node;
		}
	}
	return node;
}


Node* add(Node* node, int value){
	Node* root;
	Node* x, *y, *z;
	if(!node){
		root = (Node*)malloc(sizeof(Node));
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->value = value;
		temp->bal=0;
		temp->left=NULL;
		temp->right=NULL;
		node = temp;
		return node;
	}
	root=node;
	if(node->value>value){
		node->bal--;
		node->left = add(node->left,value);
		y = node->left;
		if(value > node->left->value) z = y->right;
		else z = y->left;
	}
	else{
		node->bal++;
		node->right = add(node->right,value);
		y = node->right;
		if(value > y->value) z = y->right;
		else z = y->left;
	}
	x = root;
	//printf("AVL of %d is %d \n",root->value,isAVL(root));
	if(isAVL(root)>1) return root;
	//printf("Rotating %d!!\n",x->value);
	return rotate(x,y,z);
}


void printTree(Node* n){
	if(n){
		printTree(n->left);
		printf("%d ",n->value);
		printTree(n->right);
	}
}

int main(){
	Node* root = NULL; //= (Node*)malloc(sizeof(Node));
	root=add(root,25);
	AVLROOT=root;
	add(AVLROOT,20);
	add(AVLROOT,36);
	add(AVLROOT,10);
	add(AVLROOT,22);
	add(AVLROOT,30);
	add(AVLROOT,40);
	add(AVLROOT,5);
	add(AVLROOT,12);
	add(AVLROOT,28);
	add(AVLROOT,38);
	add(AVLROOT,48);
	add(AVLROOT,1);
	add(AVLROOT,8);
	add(AVLROOT,15);
	add(AVLROOT,45);
	add(AVLROOT,50);
	printTree(AVLROOT);
	printf("\n");
	/*Node* arr[100];
	int i=0,j=1;
	arr[0]=root;
	while(arr[i]!=NULL){
		printf("%d ",arr[i]->value);
		if(arr[i]->left){
			printf("left: %d ",arr[i]->left->value);
			arr[j]=arr[i]->left;
			j++;
		}
		if(arr[i]->right){
			printf("right: %d ",arr[i]->right->value);
			arr[j]=arr[i]->right;
			j++;
		}
		printf("\n");
		i++;
	}*/
	printTree(AVLROOT);
	printf("\n");
}
/* end of complete.c */
