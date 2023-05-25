#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

int main() {
	int a, b, c, s, max, min, m;
	printf("Enter three int numbers : ");
	scanf("%d %d %d", &a, &b, &c);

	printf("******** Instrunction List ****************\n");
	printf("1. Max number\n");
	printf("2. Min number\n");
	printf("3. Sorting numbers(ascending order)\n");
	printf("*******************************************\n");
	
	printf("Enter instruction number ? ");
	scanf("%d", &s);

	if (a >= b && a >= c) {
		max = a;
		if (b >= c) {
			min = c; m = b;
		}	
		else {
			min = b; m = c;
		}
	}
	else if (b >= c && b >= a) {
		max = b;
		if (c >= a) {
			min = a; m = c;
		}
		else {
			min = c; m = a;
		}
	}
	else {
		max = c;
		if (a >= b) {
			min = b; m = a;
		}
		else {
			min = a; m = b;
		}
	}

	switch (s) {
	case 1:
		printf("The max number is %d\n", max);
		break;
	case 2:
		printf("The min number is %d\n", min);
		break;
	case 3:
		printf("Sorting numbers(ascending order) : %d %d %d\n", min, m, max);
		break;
	default:
		printf("Worng number!");
	}
}