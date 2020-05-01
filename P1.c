#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n, i, j;
	FILE* f = fopen("nr.txt", "w");
	if (!f)
	{
		printf("Eroare la deschiderea fisierului!\n");
		exit(0);
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (i > j) fputc('+', f);
			else if (i == j) fputc('0', f);
			else fputc('-', f);
		fprintf(f, "\n");
	}
	fclose(f);
}