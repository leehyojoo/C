#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	printf("Enter a five-digit integer : ");
	scanf("%d", &n);

	int a, b, c, d, e;
	a = n / 10000;
	b = (n % 10000) / 1000;
	c = (n % 1000) / 100;
	d = (n % 100) / 10;
	e = (n % 10) / 1;

	int num = a * b * c * d * e;
	printf("%d : %d * %d * %d * %d * %d = %d\n", n, a, b, c, d, e, num);
	return 0;
}