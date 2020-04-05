#include<stdlib.h>
#include<stdio.h>

int main() {
	int k = 0;
	while (malloc(10240)) k++;
	printf("Aproximativ: %d KB", k);
	return 0;
}
