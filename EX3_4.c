#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int main()
{
	int v[10];
	int* end, * p, nr=0;
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
		if (*p < 0) nr = nr + 1;
	printf("In vector sunt %d nr negative", nr);
	return 0;
}