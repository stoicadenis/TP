#include "stdio.h"
#include "stdlib.h"

int main(){
  int n=0, *v=NULL, *buf;
  for(;;){
    n++;
    if((buf=(int*)realloc(v,n))==NULL){
      free(buf);
      printf("memorie insuficienta!");
      exit(EXIT_FAILURE);
    }
    v=buf;
    scanf("%d", &v[n-1]);
    if(v[n-1]==0) break;
  }
  for(int i=n-2;i>=0;i--){
    printf("%d ", v[i]);
  }
  free(v);
  return 0;
}
