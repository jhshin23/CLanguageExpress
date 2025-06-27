#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fp = NULL;
	fp = fopen("sample.txt", "w");
	if (fp == NULL)
		printf("실패");
	else
		printf("성공");
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fclose(fp);
	return 0;
}

