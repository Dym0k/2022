#include <stdio.h>
#include "tool.h"

int main(int argc, const char* argv[])
{
	float pl = 0;
	 Point A = { 0,0 };
	Point B = { 4,0 };
	 Point C = { 0,0 };
	Point D = { 4,16 };
Point arrayOfPoint[2] = { C, D };

	Square *a = createSquare(&A, &B);
	printSquare(a);
	pl = plOfsquare(a);
	printf("ploshad = %.0f\n", pl);

	Square *b = createSquareWithCoordinate(3, 7, 0, 5);
	printSquare(b);
	pl = plOfsquare(b);
	printf("ploshad = %.0f\n", pl);

	Square *c = createSquareWithArrayOfPoint(arrayOfPoint);
	printSquare(c);
	pl = plOfsquare(c);
	printf("ploshad = %.0f\n", pl);

	destroySquare(a);
	destroySquare(b);
	destroySquare(c);
	return 0;
}
