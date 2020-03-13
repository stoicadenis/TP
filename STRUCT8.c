#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nume[50];
	int zi, luna, an;
}elevi;

void citire(elevi* e, int n) {
	for (int i = 0; i < n; i++) {
		printf("Numele elevului %d este: ", i+1);
		getchar();
		fgets(e[i].nume, 50, stdin);
		printf("Data nasterii (D/M/Y): ");
		scanf("%d%d%d", &e[i].zi, &e[i].luna, &e[i].an);
	}
}

void sort(elevi* e, int n) {
	elevi aux;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if (strcmp(e[i].nume, e[j].nume) > 0) {
				aux = e[i];
				e[i] = e[j];
				e[j] = aux;
			}
}

int main(void) {
	elevi e[30];
	int n;
	printf("Cati elevi sunt in clasa?\n");
	scanf("%d", &n);
	citire(e, n);
	sort(e, n);
	for (int i=0; i < n; i++) {
		printf("%d. Numele: %s Data nasterii: %d.%d.%d\n", i+1, e[i].nume, e[i].zi, e[i].luna, e[i].an);
	}
}