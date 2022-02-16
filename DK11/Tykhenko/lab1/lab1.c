#include <stdio.h>
#include <math.h>

int fktrl(int x);

int main()
{
	int a;
	int b;
	int c;
	float kor;
	float res1=0;
	int res2=0;

do{
	printf("Введіть число A: ");
	scanf("%d", &a);
}while(a<0);
do{
	do{
	printf("Введіть число B: ");
	scanf("%d", &b);
	}while(b==0);
	do{
	printf("Введіть число C: ");
	scanf("%d", &c);
	}while(c<0);
}while((b+c)<0);

	printf("A = %d, B = %d, C = %d\n", a, b, c);
	kor = b + c;
	res1=(a*sqrtf(kor))/b;


for(int d=0; d<=c; d++){
	int summa = a+d;
	res2 = res2 + fktrl(summa);
}

	printf("Q = %.3f\n", (res1+res2));

	return 0;

}

int fktrl(int x){
	int n;
	int fktr=1;
	for(n=1; n<=x; n++){
		 fktr = fktr * n;
	}
	return(fktr);
}
