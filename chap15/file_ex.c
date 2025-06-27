#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE *fp = NULL;
	fp = fopen("sample1.txt", "w");
	if (fp == NULL)
		printf("열기 실패\n");
	else 
		printf("열기 성공\n");
	fclose(fp);

	return 0;
}