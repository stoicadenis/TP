#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int cod_angajat;
	float sal_incadrare;
	char nume[30], prenume[30];
	struct {
		int zi, luna, an;
	}data_angajarii;	
}ang;

int main() {
	ang a;
	a.cod_angajat = 1021;
	strcpy(a.nume, "Popescu");
	strcpy(a.prenume, "Ioan");
	a.data_angajarii.an = 2002;
	a.data_angajarii.luna = 9;
	a.data_angajarii.zi = 10;
	a.sal_incadrare = 1250;

	printf("Cod angajat: %d", a.cod_angajat);
	printf("Angajat: %s %s\n", a.nume, a.prenume);
	printf("Data angajarii: %d.%d.%d\n", a.data_angajarii.zi, a.data_angajarii.luna, a.data_angajarii.an);
	printf("Salariu incadrare: %.2f", a.sal_incadrare);

}