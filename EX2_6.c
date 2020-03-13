#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void citeste(int a[26][25], int m, int n) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void afis(int a[26][25], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void add(int a[26][25], int *m, int n) {
	int i, j;
	for (i = *m; i > 1; i--) {
		for (j = 0; j < n; j++) {
			a[i][j] = a[i - 1][j];
		}
	}
	for (j = 0; j < n; j++)
		a[2][j] = 0;
	(*m)++;
}



int main() {
	int a[26][25], m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	citeste(a, m, n);
	afis(a, m, n);
	printf("\n");
	add(a, &m, n);
	afis(a, m, n);
	system("pause");
	return 0;
}