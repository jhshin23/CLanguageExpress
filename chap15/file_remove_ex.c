#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	if (remove("sample1.txt") == -1)
		printf("���� ����");
	else
		printf("���� ����");

	return 0;
}