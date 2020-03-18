#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct
{
	int a, b;
}rational;

int cmmdc(int x, int y)
{
	if (x == y) return x;
	else
		if (x > y) return cmmdc(x - y, y);
		else
			return cmmdc(x, y - x);
}

void ireductibil(int *a, int *b)
{
	if (*b < 0)
	{
		*a = -*a;
		*b = -*b;
	}
	if (!*a)
		*b = 1;
	else
		if (abs(*a) != 1 && abs(*b) != 1)
		{
			int d = cmmdc(abs(*a), abs(*b));
			*a = *a / d;
			*b = *b / d;
		}
}

void citire(rational* x, char c)
{
	printf("Dati numarul rational %c:\n", c);
	printf("\tnumaratorul: ");
	scanf("%d", &x->a);
	int n;
	do
	{
		printf("\tnumitorul: ");
		scanf("%d", &n);
	} while (n == 0);
	x->b = n;
	ireductibil(&x->a, &x->b);
}

void afisare(rational x, char c[])
{
	printf("Numarul rational %s: %d/%d\n", c, x.a, x.b);
}

rational adunare(rational x, rational y)
{
	rational r;
	r.a = (x.a) * (y.b) + (x.b) * (y.a);
	r.b = x.b * y.b;
	ireductibil(&r.a, &r.b);
	return r;
}

rational inmultire(rational x, rational y)
{
	rational r;
	r.a = x.a * y.a;
	r.b = x.b * y.b;
	ireductibil(&r.a,&r.b);
	return r;
}

int main()
{
	rational x, y;

	citire(&x, 'x');
	citire(&y, 'y');

	afisare(x, "x");
	afisare(y, "y");

	rational s;
	s = adunare(x, y);
	afisare(s, "x+y");

	rational p;
	p = inmultire(x, y);
	afisare(p, "x*y");
	return 0;
}