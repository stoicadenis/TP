#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void sort(int* a, int* b) {
	int aux;
	if (*a == *b) return;
	if (*a < * b) return;
	else {
		aux = *a;
		*a = *b;
		*b = aux;
	}
}

int main() {
	int a, b;
	printf("a= ");
	scanf("%d", &a);
	printf("b= ");
	scanf("%d", &b);
	sort(&a, &b);
	printf("Primul numar este %d iar al doilea este %d", a, b);
	system("pause");
	return 0;
}