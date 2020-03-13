#define _CRT_SECURE_NO_WARNINGS
#define citire(a) scanf("%d", &a)
#include <stdlib.h>
#include <stdio.h>

void citirev(float v[], int k) {
	for (int i = 0; i < k; i++) scanf("%d", &v[i]);
}

void citirem(float a[10][10], int m, int n) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

int egal(float v1[10][10], float v2[], int i) {
	for (int j = 0; j < 5; i++)
		for(int k=0;k<10;k++)
		   if (v1[i][k] == v2[j]) return k;
	return -1;
}

int main() {
	int m, n, k;
	float v[5], a[10][10];
	citire(m);
	citire(n);
	citire(k);
	citirem(a, m, n);
	citirev(v, k);
	for (int i = 0; i < k; i++) {
		int j = egal(a, v, i);
		if (j != -1)
			printf("Vectorul se gaseste pe linia %d cu coloana %d\n", i, j);
		else
			printf("Vectorul nu se gaseste pe linia %d\n", i);
	}
	system("pause");
	return 0;
}