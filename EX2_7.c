#define _CRT_SECURE_NO_WARNINGS
#define citesc(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void citire(int a[10][10], int x, int y) {
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			citesc(a[i][j]);
}

void inmultire(int a[10][10], int b[10][10], int c[10][10], int m, int n, int p) {
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++) {
			s = 0;
			for (int k = 0; k < n; k++)
				 s = s +  a[i][k] * b[k][j];
			c[i][j] = s;
		}
			
}

void afis(int c[10][10], int m, int p) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}

int main() {
	int m, n, p, a[10][10], b[10][10], c[10][10];
	citesc(m);
	citesc(n);
	citesc(p);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++)
			c[i][j] = 0;
	citire(a, m, n);
	citire(b, n, p);
	inmultire(a, b, c, m, n, p);
	afis(c, m, p);
	return 0;
}