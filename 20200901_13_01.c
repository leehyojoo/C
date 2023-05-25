#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DATA_NUM_PER_LINE 5

int MAX_DATA_VALUE, DATA_NUM;

void GenerateData(int* pArr) { // 1번 메뉴 함수 구현
	srand((unsigned)time(NULL));

	for (int i = 0; i < DATA_NUM; i++) {	
		pArr[i] = (rand() % MAX_DATA_VALUE) + 1;
		for (int j = 0; j < i; j++) {
			if (pArr[i] == pArr[j]) // 중복일 경우 i--로 다시
				i--;
		}
	}
}

void BubbleSort(int* pArr) { // 2번 메뉴 함수 구현
	int i, j, tmp;

	for (int i = 0; i < DATA_NUM - 1; i++)
	{
		for (int j = 0; j < DATA_NUM - 1 - i; j++)
		{
			if (pArr[j] > pArr[j + 1])
			{
				tmp = pArr[j];
				pArr[j] = pArr[j + 1];
				pArr[j + 1] = tmp;
			}
		}
	}
}

int BinarySearch(int* pArr, int data) { // 3번 메뉴 함수 구현
	int mid, start = 0;
	int end = DATA_NUM - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (data == pArr[mid])
			return mid;
		else if (data < pArr[mid])
			end = mid - 1;
		else if (data > pArr[mid])
			start = mid + 1;
	}
	return -1;
}

void printData(int* pArr) { // 4번 메뉴 함수 구현
	int count = 0;
	for (int i = 0; i < DATA_NUM; i++) {
		printf("%5d", *(pArr+i));
		count++;
		if (count % 5 == 0)
			printf("\n");
	}
	if(count % 5 != 0)
		printf("\n");
}

int main() {
	int menu, sort = 0, find_num, binary_result;
	int* Dataset = NULL;

	while (1) {
		printf("*************************************\n");
		printf("   1: Generate Input Data\n");
		printf("   2: Bubble Sort\n");
		printf("   3: Binary Search\n");
		printf("   4: Print Data\n");
		printf("   0: Program Exit\n");
		printf("*************************************\n");
		
		printf("Choose menu muber : ");
		scanf("%d", &menu);

		if (menu == 0) {
			printf("End of Program\n");
			break;
		}
		if (menu == 2 || menu == 3 || menu == 4) {
			if (Dataset == NULL) {
				printf("No input data!\n");
				continue;
			}
		}

		switch (menu) 
		{case 1:
			printf("Enter the number of data : ");
			scanf("%d", &DATA_NUM);
			printf("Enter the maximum possible value of data : ");
			scanf("%d", &MAX_DATA_VALUE);
			if (DATA_NUM > MAX_DATA_VALUE) {
				printf("Number of data is greater than maximum possible value!\n");
				break;
			}
			Dataset = (int*)malloc(sizeof(int) * DATA_NUM);
			if (Dataset == NULL) {
				printf("Memory Failed!!\n");
				return 1;
			}
			GenerateData(Dataset);
			sort = 0;
			printf("Generating input data is done!\n");
			break;
		case 2:
			BubbleSort(Dataset);
			printf("Bubble Sorting is done!!\n");
			sort = 1;
			break;
		case 3:
			if (sort == 1) {
				printf("Enter data to find : ");
				scanf("%d", &find_num);
				binary_result = BinarySearch(Dataset, find_num);
				if (binary_result == -1) {
					printf("%d was not found\n", find_num);
				}
				else
					printf("%d was found at %d index\n", find_num, binary_result);
				break;
			}
			else {
				printf("Must Sorting before Binary search!!\n");
				break;
			}
		case 4:
			printf("Input Data : %d elements\n", DATA_NUM);
			printData(Dataset);
			break;
		default:
			printf("Worng number!\n");
			break;
		}
	}
	free(Dataset);
}