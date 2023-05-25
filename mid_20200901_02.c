#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand((unsigned)time(NULL));
	int num, max;
	int A[21] = { 0 };

	while (1) {
		num = rand() % 21 + 0;
		if (num == 0) {
			break;
		}
		printf("Random int number is %d\n", num);
		A[num] += 1;
		if (A[num] > 1) {
			printf("Already generated!\n");
		}
	}
	printf("**************************************\n");
	max = 0;
	for (int i = 0; i < 21; i++) {
		if (A[i] >= 1) {
			max = i;
		}
	}
	printf("The maximum number is %d\n", max);
}