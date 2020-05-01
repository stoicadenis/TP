#define _CRT_SECURE_NO_WARNINGS
#define MAX_L 50
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE* f = fopen("in.txt", "r");
	FILE* g = fopen("out.txt", "w");
	float x[MAX_L], y[MAX_L], aux;
	int i, j, n = 0;
	if (!f || !g)
	{
		perror("Eroare la deschiderea fisierului!\n");
		exit(0);
	}
	while (fscanf(f, "%f", &x[n]) != EOF && fscanf(f, "%f", &y[n]) != EOF)
	{
		n++;
	}
	fclose(f);
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (x[i] > x[j] || y[i] > y[j])
			{
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
				aux = y[i];
				y[i] = y[j];
				y[j] = aux;
			}
		}
	for (i = 0; i < n; i++) fprintf(g, "%f %f\n", x[i], y[i]);
	fclose(g);
}