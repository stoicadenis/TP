#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **linii=NULL;
int nrLinii=0;

void eliberare()
{
    int i;
    for(i=0;i<nrLinii;i++)free(linii[i]);
    free(linii);
}

char *linie()
{
    char buf[201];
    char *p;
    size_t n;
    fgets(buf,201,stdin);
    buf[strcspn(buf,"\n")]='\0';
    n=strlen(buf)+1;
    if((p=(char*)malloc(n*sizeof(char)))==NULL){
        eliberare();
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
        }
    strcpy(p,buf);
    return p;
}

int main()
{
    char **linii2;
    char *aux, *p;
    int i;
    for(;;){
        p=linie();
        if(strlen(p)==0){
            free(p);
            break;
            }
        nrLinii++;
        if((linii2=(char**)realloc(linii,nrLinii*sizeof(char*)))==NULL){
            eliberare();
            printf("memorie insuficienta\n");
            exit(EXIT_FAILURE);
            }
        linii=linii2;
        linii[nrLinii-1]=p;
        }
    for(i=0;i<nrLinii;i++)
    for(int j=0;j<nrLinii;j++){
        if(strcmp(linii[i],linii[j])>0)
        aux=linii[i];
        linii[i]=linii[j];
        linii[j]=aux;
        }
    for(i=0;i<nrLinii;i++){
      printf("%c ", linii[i]);
    }
    free(aux);
    eliberare();
    return 0;
}
