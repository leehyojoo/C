#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num_length(long long n) {
	int k = n;
	int count = 0;
	while (k > 0) {
		k = k / 10;
		count++;
	}
	if (n == 0)
		count = 1;
	return count;
}

int main() {
	long long num = 1;
	int d, t, k, ans;
	while (1) {
		printf("Enter integer number : ");
		scanf("%lld", &num);
		if (num < 0) {
			printf("End program***\n");
			break;
		}
		d = num_length(num);
		printf("%lld is %d digits number.\n", num, d);
		
		printf("Enter digit value to find the number of digit(ex, a digit value of 3 from 532 is 10) : ");
		scanf("%d", &k);
		ans = (num / k) % 10;
		printf("The number of %d digit value from %lld is %d\n", k, num, ans);
		printf("*************************************************\n");
	}
	
}