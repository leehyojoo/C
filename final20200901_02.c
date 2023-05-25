#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char* str;
}DATA;

int main() {
	DATA t;
	DATA* T;
	char tmp[101];
	char tmp2[101];
	char f_word[5], r_word[5];
	int count; 
	char* tok;
	
	printf("********************************************************\n");
	printf("Enter word to find in the string : ");
	gets_s(f_word, sizeof(f_word));
	printf("Enter word to replace in the string : ");
	gets_s(r_word, sizeof(r_word));

	if (strlen(f_word) != strlen(r_word)) {
		printf("Eroor! The length of the two words is different.");
		return 1;
	}
	printf(": %s will be changed to %s! in the string if exists\n\n", f_word, r_word);

	T = (DATA*)malloc(sizeof(t) * 3);
	if (T == NULL) {
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		int count = 0; 

		printf("%d : Enter a string : ", i + 1);
		gets_s(tmp, sizeof(tmp));
		T[i].str = (char*)malloc(strlen(tmp) + 1);
		if (T[i].str = NULL) {
			return 1;
		}

		tok = strtok(tmp, " ");
		while (tok != NULL) {
			if (tok == f_word) {
				strcat(T[i].str, r_word);
				count++;
			}	
			else if (tok != f_word)
				strcat(T[i].str, tok);
			strcat(T[i].str, " ");

			tok = strtok(NULL, " ");
		}
		strcat(T[i].str, '\0');
		T[i].num = count;
	}

	for (int i = 0; i < 3; i++) {

		if (T[i].num = 0) {
			printf("%s word does not appear in the string(%s)\n", f_word, T[i].str);
		}
		else {
			printf("%s word appears %d times in the string(%s)\n", f_word, T[i].num, T[i].str);
		}

		free(T[i].str);
	}

	free(T);
}