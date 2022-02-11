#include <stdio.h>

void wmatr(int a, int b, int *pointer, int num);// функція для заповнення та виводу матриці
int main()
{
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
	int k;
	int j;
	int n=1;
	wmatr(row, length, p, n);
	n++;
	wmatr(row, length, p1, n);

	printf("Сума матриць: \n");// знаходжу сумму матриць і одразу ж вивожу в термінал результат
	for(j=0; j<(length); j++){
			for(k=0; k<(row); k++){
				smatr[j][k]=*( p + ( j * row + k ) ) +*( p1 + ( j * row + k ) ) ;
				printf("%d ", smatr[j][k]);
			}
			printf("\n");
		}
	printf("\n");

	return 0;
}

void wmatr(int a, int b, int *pointer, int num){
	int k;
	int j;
	for(j=0; j<(b); j++){// цикл заповнення матриці
		for(k=0; k<(a); k++){
			printf("matr%d[%d][%d]: ", num, j, k);
			scanf("%d", ( pointer + ( j * a + k ) ) );
		}
	}

	printf("Матриця №%d\n", num);// цикл виводу матриці
	for(j=0; j<(b); j++){
		for(k=0; k<(a); k++){
			printf("%d ", *( pointer + ( j * a + k ) ) );
		}
		printf("\n");
	}
}
