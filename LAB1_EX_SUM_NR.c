#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int s(int n) {
	if (n == 0) return 0;
	if (n > 0) return s(n / 10) + n % 10;
}

int main() {
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Suma cifrelor este: %d\n", s(n));
	system("pause");
	return 0;
}