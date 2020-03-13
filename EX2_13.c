#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void init(int** v, int n) {
	for (int i = 0; i < n; i++) {
		v[i] = malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++)
			v[i][j] = 0;
	}
}

void citire(int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == j)v[i][j] = 0;
			else if (i < j) {
				citesc(v[i][j]);
				v[j][i] = v[i][j];
			}
	}
}

void afis(int** v, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", v[i][j]);
		printf("\n");
	}
}

void dist_min(int** v, int n) {
	int i, j, vmin, min_j;
	for (i = 0; i < n; i++) {
		vmin = v[i][0];
		min_j = 0;
		for (j = 0; j < n; j++) {
			if (vmin == 0 || (vmin > v[i][j] && v[i][j] > 0)) {
				vmin = v[i][j];
				min_j = j;
			}		
		}
		if (vmin != 0)
			printf("Cel mai aproape oras de %d este %d\n", i, min_j);
	}	
}

int main(void) {
	int** v, n;
	citesc(n);
	v = malloc(n * sizeof(int*));
	init(v, n);
	citire(v, n);
	afis(v, n);
	dist_min(v, n);
}