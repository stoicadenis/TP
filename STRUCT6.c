#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ora;
	float grade;
}temp;

int main(void) {
	temp t[10];
	int n, orai, orasf, k = 0, i;
	float s = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &t[i].ora);
		scanf("%f", &t[i].grade);
	}
	printf("Cititi ora de inceput apoi ora de sfarsit: \n");
	scanf("%d", &orai);
	scanf("%d", &orasf);
	for (i = 0; i < n; i++) {
		if (t[i].ora >= orai && t[i].ora <= orasf) {
			s += t[i].grade;
			k++;
		}
	}
	if (k == 0)
		printf("Nu exista temperaturi in intervalul citit\n");
	else
		printf("Media temperaturilor este: %f", s / k);
}