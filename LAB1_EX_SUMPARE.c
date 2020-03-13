#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int s_pare(int n) {
	if (n == 0) return 0;
	if (n > 0) {
		if ((n % 10) % 2 == 0) return s_pare(n / 10) + 1;
		return s_pare(n / 10);
	}
} 

int main() {
	int n;
	printf("n= ");
	scanf("%d", &n);
	printf("Numarul de cifre pare gasite sunt: %d\n", s_pare(n));
	system("pause");
	return 0;
}