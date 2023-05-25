#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

void main() {
	int num, n;
	char tmp[21];
	char** F;
	printf("Number of input data? ");
	scanf("%d", &num);

	F = (char**)malloc(sizeof(char*) * num);
	if (F == NULL)
		exit(1);

	for (int i = 0; i < num; i++) {
		printf("%d : Enter number and fruit name? ", i + 1);
		scanf("%d", &n);
		scanf("%s", &tmp);
		if (n <= 0) {
			printf("Number of fruit is greater than 0!\n");
			i--;
			continue;
		}
		F[i] = (char*)malloc(n * strlen(tmp) + 1);
		if (F[i] == NULL)
			exit(1);

		int count = 0;
		strcpy(F[i], tmp);
		while (count < n-1) {
			strcat(F[i], tmp);
			count++;
		}
	}

	printf("******** %d fruit strings *********\n", num);
	for (int i = num - 1; i >= 0; i--) {
		printf("%s\n", *(F + i));
		free(F[i]);
	}
	free(F);
}