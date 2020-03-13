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

int subm(int** a, int** b, int n, int i, int p) {
	int x = p;
	for (int k = 0; k < n; k++) {
		p = x;
		for (int j = 0; j < n; j++) {
			if (a[i][p] != b[k][j]) return 0;
			p++;
		}
		i++;
	}
	return 1;
}

void comp(int** a, int** b, int m, int n) {
	int ok = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			if (a[i][j] == b[0][0])
				if (subm(a, b, n, i, j)) {
					printf("(%d, %d)\n", i, j);
					ok = 1;
				}
	}
	if (ok == 0) printf("NU EXISTA!");
}

int main(void) {
	int** a, ** b, m, n;
	citesc(m);
	citesc(n);
	a = malloc(m * sizeof(int*));
	b = malloc(n * sizeof(int*));
	citire(a, m);
	citire(b, n);
	comp(a, b, m, n);

}