#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
	int an, put, nrl;
	char marca[20], model[20], color[20];
}autom;

void citire(autom* a, int* n) {
	(*n)++;
		printf("Cititi marca autovehiculului: ");
		getchar();
		scanf("%s", &a[*n].marca);
		printf("Cititi modelul masinii: ");
		getchar();
		scanf("%s", &a[*n].model);
		printf("Cititi culoarea masinii: ");
		getchar();
		scanf("%s", &a[*n].color);
		printf("Cititi anul de fabricatie al masinii: ");
		scanf("%d", &a[*n].an);
		printf("Cititi numarul de locuri al masinii: ");
		scanf("%d", &a[*n].nrl);
		printf("Cititi puterea masinii: ");
		scanf("%d", &a[*n].put);
}

void afis_five(autom* a, int n) {
	bool ok = false;
	for(int i=0;i<=n;i++)
		if (a[i].nrl == 5) {
			printf("Marca: ");
			puts(a[i].marca);
			printf("Model: ");
			puts(a[i].model);
			printf("Culoare: ");
			puts(a[i].color);
			printf("Nr. Locuri: %d   An fabricatie: %d   Putere: %d\n", a[i].nrl, a[i].an, a[i].put);
			ok = true;
		}
	if (!ok)
		printf("Nu exista masini cu 5 locuri inregistrate!\n");
}

void sort_put(autom* a, int n) {
	autom aux;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if (a[i].put > a[j].put) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	for(int i=0;i<=n;i++)
		printf("Marca: %s Model: %s Culoare: %s Nr. Locuri: %d   An fabricatie: %d   Putere: %d\n", a[i].marca, a[i].model, a[i].color, a[i].nrl, a[i].an, a[i].put);
}

void afis_an(autom* a, int an, int n) {
	bool ok = false;
	for (int i = 0; i <= n; i++)
		if (a[i].an == an) {
			printf("Marca: ");
			puts(a[i].marca);
			printf("Model: ");
			puts(a[i].model);
			printf("Culoare: ");
			puts(a[i].color);
			printf("Nr. Locuri: %d   An fabricatie: %d   Putere: %d\n", a[i].nrl, a[i].an, a[i].put);
			ok = true;
		}
	if (!ok)
		printf("Nu exista masini cu acest an de fabricatie!\n");
}

int main() {
	autom a[50];
	int n = -1, opt, an;
	do {
		printf("0. Iesire\n");
		printf("1. Citire autovehicul\n");
		printf("2. Afisare masini cu 5 locuri\n");
		printf("3. Sortare in ordine crescatoare in functie de putere + afisare\n");
		printf("4. Afisare autovehicule dupa un anumit an\n");
		printf("Cititi optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt) {
		case 0: exit(0);
			break;
		case 1:
			citire(a, &n);
			break;
		case 2:
			afis_five(a, n);
			break;
		case 3:
			sort_put(a, n);
			break;
		case 4:
			printf("Cititi anul de fabricatie dupa care doriti sa cautati: ");
			scanf("%d", &an);
			afis_an(a, an, n);
			break;
		default:
			printf("Nu exista optiunea citita!!!\n");
			break;
		}
	} while (1);
	return 0;
}