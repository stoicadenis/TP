#include "stdio.h"
#include "stdlib.h"

int main(){
  int n, *v;
  scanf("%d", &n);
  v=(int*)malloc(n*sizeof(int*));
  for(int i=0;i<n;i++){
    scanf("%d", &v[i]);
  }
  for(int i=n-1;i>=0;i--){
    printf("%d ", v[i]);
  }
  free(v);
  return 0;
}
