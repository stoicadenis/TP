#define citire(a) scanf("%d", &a)

#include "stdio.h"
#include "stdlib.h"

typedef struct{
  char nume[100];
  int nr_mat;
}stud;

void citire_s(stud *s, int n){
  for(int i=0;i<n;i++){
    printf("Studentul nr.%d\n", i);
    printf("\tNumele: ");
    getchar();
    scanf("%s", s[i].nume);
    printf("\tNr. matricol: ");
    scanf("%d", &s[i].nr_mat);
  }
}

void afisare(stud *s, int n){
  for(int i=0;i<n;i++)
       printf("%d. Nume: %s, Nr. matricol: %d\n", i, s[i].nume, s[i].nr_mat);
}

void sort_alfa(stud *s, int n){
  stud aux;
  for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++){
        if(strcmp(s[i].nume, s[j].nume)>0){
          aux=s[i];
          s[i]=s[j];
          s[j]=aux;
        }
      }
}

void sort_nrmat(stud *s, int n){
  stud aux;
  for(int i=0;i<n-1;i++)
      for(int j=i+1;j<n;j++){
        if(s[i].nr_mat > s[j].nr_mat){
          aux=s[i];
          s[i]=s[j];
          s[j]=aux;
        }
      }
}

void caut_nume(stud *s, int n, char *nume){
  for(int i=0;i<n;i++)
       if(strcmp(s[i].nume, nume)==0){
         printf("Studentul se afla pe pozitia %d\n", i);
         break;
       }
}

void caut_nrmat(stud *s, int n, int nrmat){
  for(int i=0;i<n;i++)
       if(s[i].nr_mat == nrmat){
         printf("Studentul se afla pe pozitia %d\n", i);
         break;
       }
}

int main(){
  stud *s;
  int n, opt, nrmat;
  char nume[100];
  do{
    citire(opt);
    switch(opt){
      case 1:
         printf("Cati studenti sunt: ");
         citire(n);
         s=(stud*)malloc(n*sizeof(stud*));
         citire_s(s, n);
         break;
      case 2:
         afisare(s, n);
         break;
      case 3:
         sort_alfa(s, n);
         break;
      case 4:
         sort_nrmat(s, n);
         break;
      case 5:
         printf("Numele pe care doriti sa-l cautati: ");
         getchar();
         scanf("%s", nume);
         sort_alfa(s, n);
         caut_nume(s, n, nume);
         break;
      case 6:
         printf("Cititi numarul matricol: ");
         citire(nrmat);
         sort_nrmat(s, n);
         caut_nrmat(s, n, nrmat);
         break;
      case 0:
         exit(0);
         break;
      default:
          printf("Optiune invalida.\n");
          break;
    }
  }while(1);
}
