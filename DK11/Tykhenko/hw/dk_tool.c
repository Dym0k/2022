#include <stdio.h>
#include "dk_tool.h"


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

void sum_matr(int *pointer1, int *pointer2, int *sump, int a, int b ){
	printf("Сума матриць: \n");// знаходжу сумму матриць і одразу ж вивожу в термінал результат
		for(int j=0; j<(b); j++){
				for(int k=0; k<(a); k++){
					*( sump + ( j * a + k ) )=*( pointer1 + ( j * a + k ) ) +*( pointer2 + ( j * a + k ) ) ;
					printf("%d ", *( sump + ( j * a + k ) ));
				}
				printf("\n");
			}
}

