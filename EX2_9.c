#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void matrice(int** v, int m, int n) {
	for (int i = 0; i < m; i++) {
		v[i] = malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++)
			v[i][j] = (i * n) + j + 1;
	}
}

void afis(int** v, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}


int main() {
	int** v, m, n;
	citesc(m);
	citesc(n);
	v = malloc(m * sizeof(int*));
	matrice(v, m, n);
	afis(v, m, n);
	system("pause");
	return 0;
}