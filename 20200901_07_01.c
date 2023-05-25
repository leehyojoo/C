#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N[10], ans_count=0;
	int Ans[10] = { 0, };
	for (int i = 1; i <= 10; i++) {
		printf("%d : Enter positive int data ( > 1) : ", i);
		scanf("%d", &N[i-1]);
	}
	for (int i = 0; i < 10; i++) {
		int n = N[i];
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (n % j == 0)
				count++;
		}
		if (count == 2) {
			Ans[i] = n;
			ans_count++;
		}
	}
	printf("********** %d prime numbers ***********\n", ans_count);
	for (int i = 0; i < 10; i++) {
		if (Ans[i] != 0)
			printf("%4d", Ans[i]);
	}

}