#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nr_c(char* s) {
	int i=0;
	while (s[i] != '\0')
		i++;
	return i;
}

int nr_c_sir(char* s, char c) {
	int i = 0, k = 0;
	while (s[i] != '\0') {
		if (s[i] == c)k++;
		i++;
	}
	return k;
}

int sir_cmp(char* s1, char* s2) {
	int x = *(int*)s1 - *(int*)s2;
	if (!x) return 0;
	if (x > 0) return 1;
	return -1;
}

int subsir(char* s, char* sub) {
	int i = 0, x = 0;
	while (s[i] != '\0') {
		if (sub[x] == s[i]) x++;
		else x = 0;
		if (sub[x] == '\0') return i;
		i++;
	}
	return -1;
}

int main() {
	char* s, * s2, * sub;
	s = s2 = sub = malloc(10 * sizeof(char*));
	gets(s);
	gets(s2);
	gets(sub);
	printf("Nr caract. sir: %d\n Nr aparitii litera: %d\n Compararea a doua siruri: %d\n Pozitia subsirului sub in s: %d\n", nr_c(s), nr_c_sir(s, 'a'), sir_cmp(s, s2), subsir(s, sub));
	free(s);
	free(s2);
	free(sub);
	system("pause");
	return 0;
}