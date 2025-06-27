#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 30

int main() {
	int i, j = 0;
	char ch_del;
	char src[SIZE] = "";
	char dst[SIZE] = "";
	char getcharacter = '\0';
	printf("문자열을 입력하시오: ");
	for (i = 0; i < SIZE - 1 && (getcharacter = getchar()) != '\n' && getcharacter != EOF; i++) {
		src[i] = (char)getcharacter;
	}
	src[i] = '\0';
	if (getcharacter != '\n' && getcharacter != EOF)
		while (getchar() != '\n');

	printf("제거할 문자: ");
	ch_del = _getche();
	printf("\n");

	for (i = 0; i < strlen(src);i++) {
		if (src[i] == ch_del)
			continue;
		else {
			dst[j] = src[i];
			j++;
		}
	}

	printf("결과 문자열: %s\n", dst);

	return 0;
}
/*
2025/02/07 16:30~16:40	10분
*/