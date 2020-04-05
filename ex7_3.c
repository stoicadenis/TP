#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(){
  char *sir1, *sir2, *sirf;
  sir1=(char*)malloc(100*sizeof(char*));
  sir2=(char*)malloc(100*sizeof(char*));
  sirf=(char*)malloc(201*sizeof(char*));
  scanf("%s", sir1);
  scanf("%s", sir2);
  strcat(sirf, sir1);
  strcat(sirf, " ");
  strcat(sirf, sir2);
  printf("%s", sirf);
  return 0;
}
