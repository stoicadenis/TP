#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	int v[10];
	int* end, * p, *j, aux;
	end = v;
	for (;;)
	{
		printf("v[%d]= ", end - v);
		scanf("%d", end);
		if (*end == 0) break;
		end++;
	}
	for (p = v; p < end; p++)
	{
		printf("%d ", *p);
	}
	for (p = v; p < end; p++)
		for (j = v + 1; j < end; j++)
			if (*p < *j) {
				aux = *p;
				*p = *j;
				*j = aux;
			}
	printf("\n");
	for (p = v; p < end; p++)
	{
		printf("%d ", *p);
	}
	return 0;
}