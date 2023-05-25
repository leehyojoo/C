#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <math.h>

double area(int a, int b, int c) {
	double A = (double)a;
	double B = (double)b;
	double C = (double)c;
	double s = (A + B + C) / 2;
	s = s * (s - A) * (s - B) * (s - C);
	double result = sqrt(s);
	return result;
}

int main() {
	int a, b, c;
	printf("Enter the length of the triangle's three sides(integer) :\n");
	scanf("%d %d %d", &a, &b, &c);
	if (a < 0 || b < 0 || c < 0)
		printf("No satisfy triangle conditions");
	else if (a + b <= c || b + c <= a || c + a <= b)
		printf("No satisfy triangle conditions");
	else {
		double result = area(a, b, c);
		printf("The area of a triangle is %.2lf\n", result);
	}
	return 0;
}