#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/***************���������Ʈ���� �������� ������ ���� �� ���� �˾�*******************/
int main() {
	FILE* fp = NULL;
	int c;
	fp = fopen("sample.txt", "r");
	if (fp == NULL)
		printf("����");
	else
		printf("����");
	while ((c = fgetc(fp)) != EOF) {
		putchar(c);
	}
	fclose(fp);
	printf("\n");
	return 0;
}