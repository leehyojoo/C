#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int sum = 0;
	int count = 0;
	double aver;

	while (1) {
		printf("Enter int num between 1 and 100 : ");
		scanf("%d", &n);
		if (n <= 0)
			break;
		sum += n;
		count++;
		if (n > 100 || (n<=100 && n % 2 != 0)) {
			sum -= n;
			count--;
		}
	}

	if (count == 0)
		aver = 0.0;
	else
		aver = (double)sum / (double)count;

	printf("**************************\n");
	printf("The number of even data between 1 and 100 : %d\n", count);
	printf("Sum : %d and Average : %.2lf\n", sum, aver);
}