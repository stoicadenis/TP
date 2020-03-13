#define _CRT_SECURE_NO_WARNINGS
#define N_MAX 9
#include <stdio.h>
#include <stdlib.h>

void citire(int v[], int n) {
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);
}

int egal(int v1[], int v2[], int n) {
	for (int i = 0; i < n; i++)
		if (v1[i] != v2[i]) return 0;
	return 1;
}

int main() {
	int v1[N_MAX], v2[N_MAX],n;
	do {
		scanf("%d", &n);
	} while (n > N_MAX);
	citire(v1, n);
	citire(v2, n);
	if (egal(v1, v2, n)) printf("Vectorii sunt egali\n");
	else printf("Vectorii nu sunt egali\n");
	system("pause");
	return 0;
}