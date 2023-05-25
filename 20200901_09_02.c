#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int** cls;
	int i = 0, tmp, num;
	printf("Enter number of class : ");
	scanf("%d", &num);
	cls = (int**)calloc(num, sizeof(int*));
	if (cls == NULL)
	{
		exit(1);
	}
	for (int i = 0; i < num; i++) {
		printf("*** Inputing %d class scores ***\n", i + 1);
		int j = 0, max = 1;
		cls[i] = (int*)calloc(max, sizeof(int));
		if (cls[i] == NULL) {
			exit(1);
		}
		while (1) {
			printf("Enter the score %d : ", j+1);
			tmp = scanf("%d", (cls[i] + j));
			if (*(cls[i] + j) < 0)
				break;
			j++;
			if (j >= max) {
				max = max + 1;
				cls[i]=(int*)realloc(cls[i], max * sizeof(int));
				if (cls[i] == NULL) {
					exit(1);
				}
			}
		}
		printf("\n");
	}

	for (int i = 0; i < num; i++) {
		printf("*** %d class scores ***\n", i + 1);
		int j = 0;
		while(1){
			if (*(cls[i] + j) < 0)
				break;
			printf("%5d", *(cls[i] + j));
			j++;
		}
		printf("\n");
		free(cls[i]);
	}
	free(cls);
}