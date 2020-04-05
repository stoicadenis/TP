#define citire(a) scanf("%d", &a)

#include <stdio.h>
#include <stdlib.h>

int citire_v(int n){
  int *v;
  v=(int*)malloc(n*sizeof(int*));
  for(int i=0;i<n;i++){
    citire(v[i]);
  }
  return v;
}

void same_nr(int *a, int *b, int m, int n){
  for(int i=0;i<m;i++)
  for(int j=0;j<n;j++){
    if(a[i]==b[j])
        printf("%d ", a[i]);
  }
}

int main(void){
  int m, n, *a, *b;
  citire(m);
  a=(int *)malloc(m*sizeof(int*));
  a=citire_v(m);
  for(int i=0;i<m;i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  citire(n);
  b=(int *)malloc(n*sizeof(int *));
  b=citire_v(n);
  for(int i=0;i<n;i++){
    printf("%d ", b[i]);
  }
  printf("\n");
  same_nr(a,b,m,n);
}
