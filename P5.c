#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nume[50];
	int nrm;
}stud;

void citire(stud* s, int n) {
	for (int i = 0; i < n; i++) {
		printf("Nume student: ");
		getchar();
		fgets(s[i].nume, 50, stdin);
		printf("Nr matricol: ");
		scanf("%d", &s[i].nrm);
	}
}

void afisare(stud* s, int n) {
	for (int i = 0; i < n; i++)
		printf("Nume student: %s Nr matricol: %d\n", s[i].nume, s[i].nrm);
}

void sortA(stud* s, int n) {
	stud aux;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(s[i].nume, s[j].nume) > 0) {
				aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
}

void sortNr(stud* s, int n) {
	stud aux;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i].nrm > s[j].nrm) {
				aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
}

int caut_nume(stud* s, char name[], int n) {
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(s[i].nume, name) == 0) {
			printf("Studentul se afla pe pozitia: %d", i);
			return;
		}
	if (i == n)
		printf("Nu exista numele citit.");
}

void caut_nr(stud* s, int nrmat, int n) {
	int i;
	for (i = 0; i < n; i++)
		if (s[i].nrm == nrmat) {
			printf("Studentul se afla pe pozitia: %d", i);
			return;
		}
	if (i == n)
		printf("Nu exista nr matricol citit.");
}

int main() {
	stud* s;
	int n, opt, nrmat;
	char name[50];
	printf("Cati studenti sunt?\n");
	scanf("%d", &n);
	s = (stud*)malloc(n * sizeof(stud*));
	do {
		printf("Cititi optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt) {
		case 1: 
			citire(s, n);
			break;
		case 2:
			afisare(s, n);
			break;
		case 3:
			sortA(s, n);
			break;
		case 4:
			sortNr(s, n);
			break;
		case 5:
			sortA(s, n);
			getchar();
			fgets(name, 50, stdin);
			caut_nume(s, name, n);
			break;
		case 6:
			sortNr(s, n);
			scanf("%d", &nrmat);
			caut_nr(s, nrmat, n);
			break;
		case 0: exit(0);
			break;
		default: printf("Nu exista aceasta optiune!\n");
			break;
		}
	} while (1);
	free(s);
	return 0;
}