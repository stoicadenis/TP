#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	int v[10];
	int* end, * p, * j;
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
		if (*p % 2 == 0) {
			for (j = p + 1; j < end; j++)
				*(j - 1) = *j;
			end--;
		}
			
	printf("\n");
	for (p = v; p < end; p++)
	{
		printf("%d ", *p);
	}
	return 0;
}