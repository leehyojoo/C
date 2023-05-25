#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long powerOFTwo(int n); 

int main(void) {
	int n;
	printf("Enter a integer(0<num<60) : ");
	scanf("%d", &n);

	long long number = powerOFTwo(n);

	printf("2 to %d times : %lld\n", n, number);
	return 0;
}

long long powerOFTwo(int n) {
	long long number = (long long)1 << n;
	return number;
}