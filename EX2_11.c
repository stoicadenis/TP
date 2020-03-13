#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void citire(int** a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			citesc(a[i][j]);
	}
}

void suma_l(int** a, int* vl, int n) {
	int s;
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < n; j++)
			s += a[i][j];
		vl[i] = s;
	}
		
}

void suma_c(int** a, int* vc, int n) {
	int s;
	for (int j = 0; j < n; j++) {
		s = 0;
		for (int i = 0; i < n; i++)
			s += a[i][j];
		vc[j] = s;
	}
		
	free(a);
}

void afis(int* v, int n) {
	for (int i = 0; i < n; i++)
			printf("%d ", *(v+i));
	printf("\n");
}

int main(void) {
	int** a, * vl, * vc, n;
	citesc(n);
	a = malloc(n * sizeof(int*));
	vl = malloc(n * sizeof(int*));
	vc = malloc(n * sizeof(int*));
	citire(a, n);
	suma_l(a, vl, n);
	suma_c(a, vc, n);
	printf("Suma pe liniile matricei:\n");
	afis(vl, n);
	printf("Suma pe coloanele matricei:\n");
	afis(vc, n);
}