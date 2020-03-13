#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void linO(int n) {
	for (int i = 0; i < n; i++)
		printf("*");
	printf("\n");
}

void linV(int n) {
	for (int i = 0; i < n; i++)
		if (i == 0 || i == n - 1) printf("*");
		else printf(" ");
	printf("\n");
}

int main() {
	int n;
	printf("n= ");
	scanf("%d", &n);
	linO(n);
	linV(n);
	linO(n);
	linV(n);
	linO(n);
	system("pause");
	return 0;
}