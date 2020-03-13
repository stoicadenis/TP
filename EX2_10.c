#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void citire(int** v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++)
			citesc(v[i][j]);
	}
}

void afis(int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%3d ", v[i][j]);
		printf("\n");
	}
}

int trans(int (*v)[20][20], int n) {
	int aux, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			aux = (*v)[i][j];
			(*v)[i][j] = (*v)[j][i];
			(*v)[j][i] = aux;
		}
	return (*v);
}

int main() {
	int** v, n;
	citesc(n);
	v = (int*)malloc(n * sizeof(int*));
	citire(v, n);
	printf("Matricea inainte de interschimbare este:\n");
	afis(v, n);
	printf("Matricea dupa interschimbare este:\n");
	trans(v, n);
	afis(v, n);
	free(v);
	system("pause");
	return 0;
}