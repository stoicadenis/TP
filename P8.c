#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* f = fopen("in.txt", "r");
	FILE* g = fopen("out.txt", "w");
	char text[100]="", text1[100];
	if (!f || !g)
	{
		perror("Fisierele nu au putut fi deschise!\n");
		exit(0);
	}
	strcat(text, "\"");
	while (fscanf(f,"%s", text1)!=EOF)
	{
		strcat(text, text1);
		if (strchr(text1, '.'))
		{
			strcat(text, "\"");
			fprintf(g, "%s\n", text);
			strcpy(text, "\"");
		}	
		else strcat(text, " ");
	}
	fclose(f);
	fclose(g);
}