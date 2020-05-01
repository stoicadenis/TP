#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	FILE* f = fopen("in.txt", "r");
	FILE* g = fopen("indexate.txt", "w");
	float x;
	if (!f || !g)
	{
		perror("Eroare la deschiderea fisierului!");
		exit(0);
	}
	while (fscanf(f, "%f", &x) != EOF)
	{
		if (x <= 1000) 
			fprintf(g,"%f\n", x + x * 15 / 100);
		else
			fprintf(g, "%f\n", x);
	}
	fclose(f);
	fclose(g);
}