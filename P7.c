#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char nume[100];
	int k, i, j, q, x=4;
	FILE* f;
	fgets(nume, 100, stdin);
	nume[strlen(nume) - 1] = 0;
	f = fopen(nume, "w");
	if (!f)
	{
		perror("Eroare la deschiderea fisierului!\n");
		exit(0);
	}
	for (i = 0; i < strlen(nume) - x; i++)
	{
		k = 1;
		for (j = i + 1; j < strlen(nume) - x; j++)
		{
			if (nume[i] == nume[j])
			{
				k++;
				for (q = j; q < strlen(nume) - 1; q++) nume[q] = nume[q + 1];
				j--;
				x++;
				fputc(nume[i], f);
				fprintf(f, " %d\n", k);
			}
		}
		if(k==1) fprintf(f, "%c %d\n", nume[i], k);
	}
	fclose(f);
	return 0;
}