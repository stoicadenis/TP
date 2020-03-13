#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void citire(int** a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = malloc(4 * sizeof(int*));
		for (int j = 0; j < 4; j++)
			citesc(a[i][j]);
	}
}

void anual(int** a, int n) {
	int ok;
	for (int i = 0; i < n; i++) {
		ok = 1;
		for (int j = 1; j < 4; j++)
			if (a[i][j - 1] > a[i][j]) ok = 0;
		if (ok == 1)
			printf("Produsul %d a crescut in vanzari pe parcursul unui an.\n", i);
		else
			printf("Produsul %d nu a crescut in vanzari pe parcursul unui an.\n", i);
	}
}

void afis(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main() {
	int** a, n;
	citesc(n);
	a = malloc(n * sizeof(int*));
	citire(a, n);
	afis(a, n);
	anual(a, n);
	free(a);
	system("pause");
	return 0;
}