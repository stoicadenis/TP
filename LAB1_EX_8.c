#define _CRT_SECURE_NO_WARNINGS
#define citire(a) scanf("%d", &a)

#include <stdlib.h>
#include <stdio.h>

int ackermann(int m, int n) {
	if (m == 0) return (n + 1);
	if (m > 0 && n == 0) return ackermann(m - 1, 1);
	else if (m > 0 && n > 0) return ackermann(m - 1, ackermann(m, n - 1));
	else printf("Nu se poate calcula!");
}

int main() {
	int m, n;
	citire(m);
	citire(n);
	printf("Rezultatul este: %d\n", ackermann(m, n));
	system("pause");
	return 0;
}