#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	if (remove("sample1.txt") == -1)
		printf("삭제 실패");
	else
		printf("삭제 성공");

	return 0;
}