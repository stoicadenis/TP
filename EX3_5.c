#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	int v[10], min;
	int* end, * p;
	end = v;
	for (;;)
	{
		printf("v[%d]= ", end - v);
		scanf("%d", end);
		if (*end == 0) break;
		end++;
	}
	min = *v;
	for (p = v; p < end; p++)
	{
		printf("%d ", *p);
	}
	for (p = v; p < end; p++)
		if (*p < min) min = *p;
	printf("Minimul este %d", min);
	return 0;
}