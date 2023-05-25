#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)

{
	float a, b, c;

	printf("Enter three real number : ");
	scanf("%f %f %f", &a, &b, &c);

	float sum = a + b + c;
	printf("%.2f + %.2f + %.2f = %.2f\n", a, b, c, sum);


	return 0;
}