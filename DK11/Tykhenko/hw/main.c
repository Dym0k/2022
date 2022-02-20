#include <stdio.h>
#include "dk_tool.h"


int main(){

	int row;
	int length;

	do{
		printf("Введіть кількість стовпців: ");
		scanf("%d", &row);
	}while(row<2);
	do{
		printf("Введіть кількість строк: ");
		scanf("%d", &length);
	}while(length<2);

	int matr[row][length];
	int *p=&matr[0][0];
	int matr1[row][length];
	int *p1=&matr1[0][0];
	int smatr[row][length];
	int *sp=&smatr[0][0];


	int n=1;
	wmatr(row, length, p, n);
	n++;
	wmatr(row, length, p1, n);

	sum_matr(p, p1, sp, row, length);
	
	return 0;
}
