#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* f = fopen("nr.txt", "r");
	float x, y, xpos, ypos;
	if (!f)
	{
		perror("Eroare la deschiderea fisierului!\n");
		exit(0);
	}
	fscanf(f, "%f", &x);
	fscanf(f, "%f", &y);
	while (fscanf(f, "%f", &xpos) != EOF && fscanf(f, "%f", &ypos) != EOF)
	{
		if (xpos <= x)
		{
			if (ypos < y)
			{
				x = xpos;
				y = ypos;
			}
		}
	}
	printf("%f %f", x, y);
	fclose(f);
}