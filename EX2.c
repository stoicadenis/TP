#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

struct ex1 {
	long int a;
	char* b, * c;
};

union ex2{
	long int a;
	char* b, * c;
};

int main(void) {
	struct ex1 x;
	union ex2 y;
	printf("Pentru STRUCTURA\n");
	printf("Spatiul ocupat de o variabila la structura: %d\n", sizeof(x));
	x.a = 10;
	x.b = "ABCD";
	x.c = "EFG";
	printf("%d\n", x.a);
	printf("%s\n", x.b);
	printf("%s\n", x.c);

	printf("Pentru UNIUNE\n");
	printf("Spatiul ocupat de o variabila la uniune: %d\n", sizeof(y));
	y.a = 10;
	y.b = "ABCD";
	y.c = "EFG";
	printf("%d\n", y.a);
	printf("%s\n", y.b);
	printf("%s\n", y.c);
}