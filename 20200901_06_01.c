#include <stdio.h>

int SumofDivisor(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int num, sum;
	srand((unsigned)time(NULL));
	num = rand() % 100 + 1;
	sum = SumofDivisor(num);

	printf("The random number is %d\n", num);
	printf("*******************************************\n");
	printf("The sum of the divisor(%d) is %d\n", num, sum);
}