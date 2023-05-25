#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void) {
	FILE* f_1 = fopen("in_20200901.txt", "w");
	if (f_1 == NULL) {
		fprintf(stderr, "file open error\n");
		return 1;
	}
	int i = 1;
	srand(time(NULL));
	while (i < 11) {
		int rand1 = rand() % 100 + 1;
		int rand2 = rand() % 100 + 1;
		fprintf(f_1, "%4d%4d\n", rand1, rand2);
		i++;
	}
	fclose(f_1);

	FILE* f_2 = fopen("in_20200901.txt", "r");
	FILE* f_3 = fopen("out_20200901.txt", "w");
	if ((f_2 == NULL) || (f_3 == NULL)) {
		fprintf(stderr, "file open error\n");
		return 1;
	}
	int num1, num2, a_sum=0, j = 1;
	fputs("********** Score List *************\n", f_3);

	while (fscanf(f_2, "%4d%4d\n", &num1, &num2) != EOF) {
		int sum = num1 + num2;
		double aver = (double)(num1 + num2) / 2.0;
		fprintf(f_3, "%2d : %4d%4d%4d  %.2f\n", j, num1, num2, sum, aver);
		a_sum += sum;
		j++;
	}
	double a_aver = (double)a_sum / 10.0;
	fprintf(f_3, "All students scores (total) :  %d\n", a_sum);
	fprintf(f_3, "All students scores (average) :  %.2f\n", a_aver);

	fclose(f_2);
	fclose(f_3);
	return 0;
}

