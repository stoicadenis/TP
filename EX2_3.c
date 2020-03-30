#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{numar, caracter, sir}tip_var;
typedef struct {
	char nume_var[10];
	tip_var t;
	union {
		char sir[50];
		char caract[1];
		double valoare;
	}tip_val;
}linie;

void afisare(linie l) {
	switch (l.t) {
	case numar:
		printf("%s=%f", l.nume_var, l.tip_val.valoare);
		break;
	case caracter:
		printf("%s=%s", l.nume_var, l.tip_val.caract);
		break;
	case sir:
		printf("%s=%s", l.nume_var, l.tip_val.sir);
		break;
	}
}

int main() {
	linie l;
	char liniet[100];
	fgets(liniet, 100, stdin);
	if (liniet[0] >= 'a' && liniet[0] <= 'z' || liniet[0] >= 'A' && liniet[0] <= 'Z') {
		if (strchr(liniet, '=')) {
			char* p, a[50];
			int k = 0, ok = 0, n, x, y;
			p = strtok(liniet, "=");
			while (p != NULL) {
                if(k==0) strcpy(l.nume_var, p);
				else strcpy(a, p);
				k++;
				p= strtok(NULL, "=");
			}
			n=strlen(a)-2;
			x=a[0];
			y=a[n];
			if (x == 34 && y == 34) {
				ok = 1;
				l.t = 2;
                strcpy(l.tip_val.sir, a);
			}
			else if (x==39 && y==39) {
				ok = 1;
				l.t = 1;
				strcpy(l.tip_val.caract, a);
			}
			else {
				ok = 1;
				for (int i = 0; i < strlen(a); i++) {
					if (strchr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", a[i])) {
						ok = 0;
					}
				}
				if (ok == 1) {
					l.t = 0;
					l.tip_val.valoare = atof(a);
				}
			}
			if (ok == 0)
				printf("Valoare invalida!\n");
			else
				afisare(l);
		}
		else
			printf("Lipseste semnul egal!\n");
	}
	else
		printf("Numele variabilei nu incepe cu o litera!\n");
	return 0;
}
