#define citire(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  unsigned int periculos:2;
  unsigned int nr_pic:10;
  unsigned int varsta:11;
  char abreviere[8];
  float greutate;
}animal;

void citire_animal(animal *a){
  int aux;
  printf("Cititi abrevierea animalului (max 8 caractere): ");
  fgets(a->abreviere, 8, stdin);
  printf("Numarul de picioare ( Min: 0 = sarpe / Max: 1000 = miriapod): ");
  citire(aux);
  a->nr_pic=aux;
  printf("Este periculos pentru om (0 - NU / 1 - DA)? R: ");
  citire(aux);
  a->periculos=aux;
  printf("Varsta maxima: ");
  citire(aux);
  a->varsta=aux;
  printf("Care este greutatea animalului? R:");
  scanf("%f", &a->greutate);
}

void afisare(animal a){
  printf("Abrevierea animalului: %s\n", a.abreviere);
  printf("Numarul picioarelor: %d\n", a.nr_pic);
  printf("Varsta: %d\n", a.varsta);
  if(a.periculos==0)
  printf("Periculos pentru om: NU\n");
  else
  printf("Periculos pentru om: DA\n");
  printf("Greutate: %.2f\n", a.greutate);
}

int main(){
  animal a;
  printf("Spatiul ocupat de structure este de %d\n", sizeof(animal));
  citire_animal(&a);
  afisare(a);
  return 0;
}
