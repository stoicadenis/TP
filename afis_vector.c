#define _CRT_SECURE_NO_WARNIGS
#include<stdio.h>
#include<stdlib.h>

void afis(int* v, int n) {
	if (n > 0) {
		printf("%d\n", v[0]);
		afisare(v + 1, n - 1);
	}
}

int main() {
	int v[] = { 7,-5,4,3,2,-9,-8 };
	afis(v, 5);

	return 0;
}