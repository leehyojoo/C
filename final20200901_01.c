#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <time.h>

int sum_Factor(int* A) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		int count = 0, sum = 0;
		for (int j = 1; j <= A[i]; j++) {
			if (A[i] % j == 0) {
				count++;
				sum += j;
			}
		}
		if (count != 2) {
			result += sum;
		}
	}
	return result;
}

int find_Second(int *A) {
	int max = 0, result = 0, k;
	for (int i = 0; i < 10; i++) {
		if (A[i] > max) {
			max = A[i];
			k = i;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i == k)
			continue;
		if (A[i] > result) {
			result = A[i];
		}
	}
	return result;
}

int main() {
	int num[10];
	int result, result2;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		num[i] = rand() % 31 + 2;
		for (int j = 0; j < i; j++) {
			if (num[i] == num[j])
				i--;
		}
	}

	printf("** Random integers (not allow duplication) **\n");
	for (int i = 0; i < 10; i++) {
		printf("%5d", num[i]);
		if (i == 4 || i==9)
			printf("\n");
	}
	printf("\n");
	result = find_Second(num);
	printf("The second largest number : %d\n", result);

	result2 = sum_Factor(num);
	printf("The sum of divisors( except prime number) : %d\n", result2);
}