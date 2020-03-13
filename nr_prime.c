#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int prim(int n, int d) {
	if (n < 2) {
		return 0;
	}
	if (n % 2 == 0 && n != 2) {
		return 0;
	}
	if (n % d == 0 && n != d) {
		return 0;
	}
	if (d * d > n) {
		return 1;
	}
	prim(n, d + 2);
}

void construct(int* a, int n, int i, int val)
{
	int repeat = 1;
	if (i == n)
		return;
	while (repeat) {
		if (prim(val, 3)) {
			a[i] = val;
			repeat = 0;
		}
		else {
			val++;
		}
	}
	construct(a, n, i + 1, val + 1);
}

void afis(int* v, int n) {
	if (n > 0) {
		printf("%d\n", v[0]);
		afis(v + 1, n - 1);
	}
}

int main() {
	int* v, n;
	scanf("%d", &n);
	v = malloc(n * sizeof(n));
	construct(v, n, 0, 1);
	afis(v, n);

	return 0;
}