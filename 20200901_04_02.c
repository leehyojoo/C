#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	double rand1, rand2;

	srand((unsigned)time(NULL));
	rand1 = (double)(rand() % 20 + 1);
	rand2 = (double)(rand() % 20 + 1);
	
	printf("x = %.2lf, y = %.2lf\n", rand1, rand2);

	double a = pow(rand1, 2) + pow(rand2, 2);
	double b = pow(rand1 + rand2, 2);
	double c = sqrt(a);

	printf("Result of experession 1 is %.2lf\n", a);
	printf("Result of experession 1 is %.2lf\n", b);
	printf("Result of experession 3 is %.2lf\n", c);

	return 0;
}