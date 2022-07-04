#include <stdio.h>
#include "list.h"

int main(int argc, const char *argv[])
{
	List *hlist = createlist();
	int value;
	int i;
	int num;
	init_list(hlist);
	printf("Введіть значення нового елементу: ");
	scanf("%d", &value);
	add_to_tail(hlist, value);
	
	printf("Щоб додати значення введіть в термінал 1 та натисніть Enter: ");
	scanf("%d", &i);
	while(i==1){
		printf("\nВведіть значення нового елементу: ");
		scanf("%d", &value);
		add_to_tail(hlist, value);
		i = 0;
		printf("\nЩоб додати значення введіть в термінал 1 та натисніть Enter,\n або 'іншу клавішу'+Enter, для виводу списку: ");
		scanf("%d", &i);
	}
	
	print_all_list(hlist);
	printCount(hlist);
	do{
		printf("Введіть від 1 до %ld, щоб вивести потрібний елемент зі списку: ", countoOfList(hlist));
		scanf("%d", &num);
	}while(num<1 || num>(int)countoOfList(hlist));
	printSeparateEl(hlist, num);
	
	deleteList(hlist);
}
