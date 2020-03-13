#include<stdio.h>
#include<stdlib.h>

int nrpare(int* v, int n)
{
	if (n == 0)
		return 0;

	return (v[0] % 2 == 0) + nrpare(v + 1, n - 1);
}

int main() {
	int v[] = { 7, 2, 6, 1, 3 };
	printf("%d\n", nrpare(v, 5));

	return 0;
}