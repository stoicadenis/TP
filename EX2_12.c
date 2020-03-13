#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdlib.h>
#include <stdio.h>

void init(int** v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++)
			v[i][j] = 0;

	}
}

void citire(int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			citesc(v[i][j]);
			if (v[i][j] == -1 || v[i][j]>n-1 || v[i][j]==i) break;
		}

	}
}

void afis(int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%3d ", v[i][j]);
		printf("\n");
	}
}

int contor(int** v, int n) {
	int i, j, k = 0;
	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 0; j < n; j++) {
			if (v[i][j] <= -1 || v[i][j] == i || v[i][j] >= n) j = n;
			else k++;
		}
		printf("Persoana numarul %d are %d prieteni.\n", i, k);
	}
}

int main(void) {
	int** v, n, i;
	citesc(n);
	v = malloc(n * sizeof(int*));
	init(v, n);
	citire(v, n);
	afis(v, n);
	contor(v, n);
}