#define _CRT_SECURE_NO_WARNINGS
#define pi 3.14

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void rotatie(float*v, float **a) {
	int i, j;
	float s;
	for (i = 0; i < 2; i++) {
		s = 0;
		for (j = 0; j < 2; j++) {
			s += v[j] * a[j][i];
		}
		v[i] = s;
	}
}

int main(void) {
	float* v, ** a, unghi = 90 * pi / 180;
	v = malloc(2 * sizeof(float*));
	a = malloc(2 * sizeof(float*));
	for (int i = 0; i < 2; i++)
		a[i] = malloc(2 * sizeof(float*));
	a[0][0] = cos(unghi);
	a[0][1] = -sin(unghi);
	a[1][0] = sin(unghi);
	a[1][1] = cos(unghi);
	scanf("%f", &v[0]);
	scanf("%f", &v[1]);
	printf("Original: %.2f %.2f\n", v[0], v[1]);
	rotatie(v, a);
	printf("Dupa rotatie: %.2f %.2f\n", v[0], v[1]);
}