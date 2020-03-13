#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int prim(int n) {
	int d;
	if (n == 1) return 0;
	if (n % 2 == 0) return 0;
	for (d = 3; d * d < n; d++)
		if (n % d == 0) return 0;
	return 1;
}

int main() {
	int n;
	printf("n= ");
	scanf("%d", &n);
	if (prim(n)) printf("Numarul %d este PRIM!", n);
	else printf("Numarul %d NU este PRIM!", n);
	system("pause");
	return 0;
}