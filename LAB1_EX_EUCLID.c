#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int AlgEuclid(int x, int y) {
	int z;
	while (y) {
		z = x % y;
		x = y;
		y = z;
	}

	return x;
}

int main() {
	int a, b;
	printf("Citeste a si b: ");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("CMMDC este: %d", AlgEuclid(a, b));
	system("pause");
	return 0;
}