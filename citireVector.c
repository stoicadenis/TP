#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void citire(int* a, int n, int i)
{
	if (i < n)
	{
		if (scanf("%d", &a[i]) == 1)
		{
			citire(a, n, i + 1);
		}
	}
}

int main() {
	int* v, n;
	scanf("%d", &n);
	v = malloc(n * sizeof(int*));
	citire(v, n, 0);

	return 0;
}