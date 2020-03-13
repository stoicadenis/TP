#define _CRT_SECURE_NO_WARNINGS
#define M_MAX 30
#define N_MAX 20
#define citire(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

void read(float a[N_MAX][M_MAX], int m, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%f", &a[i][j]);
}

void transpusa(float a[N_MAX][M_MAX], float b[M_MAX][N_MAX], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][i];
			printf("%.2f ", b[i][j]);
		}
		printf("\n");
	}
				
}

int main() {
	float a[N_MAX][M_MAX], b[M_MAX][N_MAX];
	int m, n;
	do {
		printf("Cititi un m[1,30] si un n[1,20]\n");
		citire(m);
		citire(n);
	} while (m > 30 && n > 20);
	read(a, m, n);
	transpusa(a, b, m, n);
	//afis(b, m ,n);
	system("pause");
	return 0;
}