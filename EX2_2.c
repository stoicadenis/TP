#define _CRT_SECURE_NO_WARNINGS
#define citire(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {mamifer, insecta, peste, pasare}TipAnimal;
const char* Animal[] = { "mamifer", "insecta", "peste", "pasare" };

typedef struct {
	TipAnimal t;
	unsigned int medie_v : 8;
	union {
		struct {
			unsigned int p_gest : 5, nr_pui;
		}mamifer;
		struct {
			unsigned int nr_pic : 16, peric : 2;
			unsigned int zboara : 2;
		}insecta;
		struct {
			unsigned int anvergura : 8, alt:10, viteza:8;
		}pasare;
		struct {
			unsigned int viteza : 8;
			char tip_apa[7];
			float adancime;
		}peste;
	}tip;
}animale;

void citire_animale(animale* a, unsigned int n) {
	unsigned int aux;
	for (int i = 0; i < n; i++) {
		printf("Animalul nr.%d\n", i + 1);
		printf("\tCe tip de animal este (0 - mamifer, 1 - insecta, 2 - peste, 3 - pasare): ");
		citire(a[i].t);
		printf("\tCare este durata medie de viata? R: ");
		citire(aux);
		a[i].medie_v = aux;
		if (a[i].t == 0) {
			printf("\tPerioada de gestatie: ");
			citire(aux);
			a[i].tip.mamifer.p_gest = aux;
			printf("\tNumarul mediu de pui nascuti: ");
			citire(aux);
			a[i].tip.mamifer.nr_pui = aux;
		}
		else if (a[i].t == 1) {
			printf("\tNumarul de picioare: ");
			citire(aux);
			a[i].tip.insecta.nr_pic = aux;
			printf("\tZboara (0 - NU / 1 - DA): ");
			citire(aux);
			a[i].tip.insecta.zboara = aux;
			printf("\tEste periculoasa pentru om? (0 - NU / 1 - DA) R: ");
			citire(aux);
			a[i].tip.insecta.peric = aux;
		}
		else if (a[i].t == 2) {
			printf("\tTipul de apa ( dulce/ sarata): ");
			getchar();
			scanf("%s", &a[i].tip.peste.tip_apa);
			printf("\tAdancime maxima unde se poate intalni: ");
			scanf("%f", &a[i].tip.peste.adancime);
			printf("\tViteza maxima de inot: ");
			citire(aux);
			a[i].tip.peste.viteza = aux;
		}
		else {
			printf("\tAnvergura aripilor: ");
			citire(aux);
			a[i].tip.pasare.anvergura = aux;
			printf("\tAltitudinea maxima de zbor: ");
			citire(aux);
			a[i].tip.pasare.alt = aux;
			printf("\tViteza maxima de zbor: ");
			citire(aux);
			a[i].tip.pasare.viteza = aux;
		}
	}
}

void afisare(animale* a, unsigned int n) {
	for (int i = 0; i < n; i++) {
		printf("Animalul %d\n", i + 1);
		printf("\tTip animal: %s\n", Animal[a[i].t]);
		switch (a[i].t) {
		case mamifer:
			printf("\tDurata medie de viata: %d\n", a[i].medie_v);
			printf("\tPerioada de gestatie: %d\n", a[i].tip.mamifer.p_gest);
			printf("\tNumarul mediu de pui nascuti: %d\n", a[i].tip.mamifer.nr_pui);
			break;
		case insecta:
			printf("\tNumarul de picioare: %d", a[i].tip.insecta.nr_pic);
			if(a[i].tip.insecta.zboara == 0)
				printf("\tZboara: NU\n");
			else
				printf("\tZboara: DA\n");
			if(a[i].tip.insecta.peric == 0)
				printf("\tPericuloasa pentru om: NU\n");
			else 
				printf("\tPericuloasa pentru om: DA\n");
			break;
		case peste:
			printf("\tTipul de apa: %s\n", a[i].tip.peste.tip_apa);
			printf("\tAdancime maxima unde se poate intalni: %.2f\n", a[i].tip.peste.adancime);
			printf("\tViteza maxima de inot: %d\n", a[i].tip.peste.viteza);
			break;
		case pasare:
			printf("\tAnvergura aripilor: %d\n", a[i].tip.pasare.anvergura);
			printf("\tAltitudinea maxima de zbor: %d\n", a[i].tip.pasare.alt);
			printf("\tViteza maxima de zbor: %d\n", a[i].tip.pasare.viteza);
			break;
		}
	}
}

int main() {
	animale a[10];
	unsigned int n;
	printf("Numarul de octeti folositi pentru exercitiu este: %d\n", sizeof(a));
	printf("Cate animale se vor citii? (n<=10): ");
	citire(n);
	citire_animale(a, n);
	afisare(a, n);
	return 0;
}