#define _CRT_SECURE_NO_WARNINGS
#define citire(a) fgets(a,50, stdin)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nume[50];
	float pret;
}produs;

void cit_p(produs* p, int *n) {
	char nume[50], ok=1;
	(*n)++;
	printf("Cititi numele produsului: ");
	getchar();
	fgets(nume, 50, stdin);
	if (*n == 0) {
		printf("Cititi pretul produsului: ");
		strcpy(p[*n].nume, nume);
		scanf("%f", &p[*n].pret);
		ok = 0;
	}
	else
		for(int i=0;i<*n;i++)
			if (!strcmp(p[i].nume, nume)) {
				printf("Cititi pretul produsului: ");
				scanf("%f", &p[i].pret);
				ok = 0;
				(*n)--;
			}
	if (ok == 1) {
		printf("Cititi pretul produsului: ");
		strcpy(p[*n].nume, nume);
		scanf("%f", &p[*n].pret);
	}
}

void afisare(produs* p, int n) {
	for (int i = 0; i <= n; i++)
		printf("No. %d => Nume: %s Pret: %f\n", i, p[i].nume, p[i].pret);
}

void delete(produs* p, char* nume, int *n) {
	for(int i=0;i<=*n;i++)
		if (!strcmp(p[i].nume, nume)) {
			for (int j = i + 1; j <= *n; j++)
				p[j - 1] = p[j];
			(*n)--;
			i--;
		}
}

void sort(produs* p, int n) {
	produs aux;
	for(int i=0;i<=n-1;i++)
		for( int j=0;j<=n;j++)
			if (p[i].pret < p[j].pret) {
				aux = p[i];
				p[i] = p[j];
				p[j] = aux;
			}
}

void afis_nume(produs* p, char* nume, int n) {
	int ok = 0;
	for (int i=0;i<=n;i++)
		if (strstr(p[i].nume, nume)) {
			ok = 1;
			printf("Pretul produsului %s este: %.2f\n", p[i].nume, p[i].pret);
		}
	if (ok == 0) printf("NU EXISTA!");
}

int main(void) {
	produs p[100];
	int opt, n = -1;
	char nume[50];
	do {
		scanf("%d", &opt);
		switch (opt) {
		case 1:
			cit_p(p, &n);
			break;
		case 2:
			afisare(p, n);
			break;
		case 3:
			getchar();
			fgets(nume, 50, stdin);
			afis_nume(p, nume, n);
			break;
		case 4:
			getchar();
			fgets(nume, 50, stdin);
			delete(p, nume, &n);
			break;
		case 5:
			sort(p, n);
			afisare(p, n);
			break;
		case 0: exit(0);
		}
	} while (1);
}

