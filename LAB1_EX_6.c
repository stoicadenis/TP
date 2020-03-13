#define _CRT_SECURE_NO_WARNINGS
#define citire(a) scanf("%d", &a)

#include <stdlib.h>
#include <stdio.h>

int cmmmdc(int a, int b) {
	if (a == b) return a;
	if (a > b) cmmmdc(a - b, b);
	else cmmmdc(a, b - a);
}

int main() {
	int a, b;
	citire(a);
	citire(b);
	printf("CMMMDC: %d", cmmmdc(a, b));
	system("pause");
	return 0;
}