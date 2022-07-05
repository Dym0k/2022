#include <stdio.h>
#include "tree.h"

void main(int argc, const char *argv[])
{
	int num;
	tree *Tree = createTree();
	printf("Введіть кількість елментів, які ви хочете внести до дерева від 3 до 7: \n");
	do{
		printf("Ввод: ");
		scanf("%d", &num);
		if(num<3 || num>7){
			printf("Введено кількість не за умовою, спробуйте ще раз: \n");
		}
	}while(num<3 || num>7);
	enter_El(Tree, num);



	printTree(Tree);

	deleteTree(Tree);
}
