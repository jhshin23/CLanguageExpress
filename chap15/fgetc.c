#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/***************명령프롬프트에서 실행하지 않으면 실패 후 오류 팝업*******************/
int main() {
	FILE* fp = NULL;
	int c;
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
		printf("실패");
	else
		printf("성공");
	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}
	fclose(fp);
	printf("\n");
	return 0;
}