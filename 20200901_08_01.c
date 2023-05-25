#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int Evaluating(double a, double b, double c, double*px1, double*px2) {
	double D = pow(b, 2.0);
	D = D - 4*a*c;
	double D2 = sqrt(D);
	a = 2*a;
	if (fabs(D) <= 1.0e-8) {
		D = 0;
		*px1 = -(b / a);
		return 1;
	}

	if (D < 0) {
		return 0;
	}
	else if (D == 0) {
		*px1 = -(b / a);
		return 1;
	}
	else {
		*px1 = (-b + D2) / a;
		*px2 = (-b - D2) / a;
	}
}

int main() {
	double a, b, c, x1, x2;
	int ans;
	double* px1 = &x1;
	double* px2 = &x2;
	printf("Enter three real number for root formula : ");
	scanf("%lf %lf %lf", &a, &b, &c);
	ans = Evaluating(a, b, c, &x1, &x2);
	if (ans == 1) {
		printf("Equal root x1 and x2 = %.2lf\n", *px1);
	}
	else if (ans == 0) {
		printf("No root exists!\n");
	}
	else {
		printf("x1 = %.2lf\n", *px1);
		printf("x2 = %.2lf\n", *px2);
	}
}