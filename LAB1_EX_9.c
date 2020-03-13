#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void min_max(int v[], int n)
{
	int imax = 0, imin = 0, min, max, i;
	min = 32657;
	max = 0;
	for (i = 0; i < n; i++)
	{
		if (v[i] > max)
		{
			max = v[i];
			imax = i;
		}
		if (v[i] < min)
		{
			min = v[i];
			imin = i;
		}

	}
	printf("Min: %d Max: %d", imin, imax);
}
int main()
{
	int v[10], i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);
	min_max(v, n);
	system("pause");
	return 0;
}
