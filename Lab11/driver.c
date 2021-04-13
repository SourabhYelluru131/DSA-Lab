/* driver.c */
#include <stdio.h>
#include"tree.h"

int main(){
	FILE* f = fopen("test.txt","r");
	Node* root = readFile(f);
}
/* end of driver.c */
