#include <stdio.h>
#include <stdlib.h>

typedef enum{gram, metru, litru}TipUnitate;
typedef enum{deca=10, hecto=100, kilo= 1000, mega=10000, giga=100000}multiplicator;

typedef struct{
  unsigned short masuratoare;
  TipUnitate u;
  multiplicator mu;
}masurat;

void citire_convert(masurat *m, int *n){
  unsigned val, p=1;
  TipUnitate unit;
  scanf("%d", &val);
  scanf("%d", &unit);
  while(val%10==0){
    p *= 10;
    val /=10;
  }
  if(val>65535){
    printf("Numarul introdus este prea mare si nu se poate prelucra!\n");
  }
  else{
    (*n)++;
    m[*n].masuratoare=val;
    m[*n].mu=p;
    m[*n].u=unit;
  }
}

void afisare(masurat *m, int n){
  for(int i=0;i<=n;i++){
    switch(m[i].u){
      case gram:
          switch(m[i].mu){
            case deca:
            printf("%d, unitate: decagram\n", m[i].masuratoare);
            break;
            case hecto:
            printf("%d, unitate: hectogram\n", m[i].masuratoare);
            break;
            case kilo:
            printf("%d, unitate: kilogram\n", m[i].masuratoare);
            break;
            case mega:
            printf("%d, unitate: megagram\n", m[i].masuratoare);
            break;
            case giga:
            printf("%d, unitate: gigagram\n", m[i].masuratoare);
            break;
          }
          break;
      case metru:
          switch(m[i].mu){
            case deca:
            printf("%d, unitate: decametru\n", m[i].masuratoare);
            break;
            case hecto:
            printf("%d, unitate: hectometru\n", m[i].masuratoare);
            break;
            case kilo:
            printf("%d, unitate: kilometru\n", m[i].masuratoare);
            break;
            case mega:
            printf("%d, unitate: megametru\n", m[i].masuratoare);
            break;
            case giga:
            printf("%d, unitate: gigametru\n", m[i].masuratoare);
            break;
          }
          break;
       case litru:
           switch(m[i].mu){
            case deca:
            printf("%d, unitate: decalitru\n", m[i].masuratoare);
            break;
            case hecto:
            printf("%d, unitate: hectolitru\n", m[i].masuratoare);
            break;
            case kilo:
            printf("%d, unitate: kilolitru\n", m[i].masuratoare);
            break;
            case mega:
            printf("%d, unitate: megalitru\n", m[i].masuratoare);
            break;
            case giga:
            printf("%d, unitate: gigalitru\n", m[i].masuratoare);
            break;
          }
          break;
    }
  }

}

int main(){
  masurat m[10];
  int n=-1;
  printf("Structura are %d octeti!\n", sizeof(masurat));
  citire_convert(m, &n);
  afisare(m,n);
  return 0;
}
