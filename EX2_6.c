#define citire(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{scazut, mediu, mare}periculozitate;
typedef enum{nu, da}reteta;
typedef struct{
  unsigned char varsta_min[1];
}medicament;
periculozitate p;
reteta r;

void citire_medicament(medicament *m){
  printf("\tGrad de periculozitate (0 - scazut, 1 - mediu, 2 - mare): ");
  scanf("%d", &p);
  printf("\tSe elibereaza pe baza de reteta ( 0 - NU / 1 - DA)? R: ");
  scanf("%d", &r);
  printf("\tVarsta minima de administrare este: ");
  getchar();
  scanf("%s", m->varsta_min);
}

void afisare(medicament *m){
    printf("\tGrad de periculozitate (0 - scazut, 1 - mediu, 2 - mare): %d\n", p);
    printf("\tSe elibereaza pe baza de reteta: %d\n", r);
    printf("\tVarsta minima de administrare: %s\n", m->varsta_min);

  }


int main() {
  medicament m;
  int opt;
  printf("%d\n", sizeof(medicament));
  do{
    citire(opt);
    switch(opt){
      case 1:
      citire_medicament(&m);
      break;
      case 2:
      afisare(&m);
      break;
      case 0:
        exit(0);
        break;
    }
  }while(1);
  return 0;
}
