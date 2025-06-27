#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LONG_MONTH 7
#define SHORT_MONTH 4

void print_birth(int yy, int mm, int dd);
int isValidBirthday(int mm31[], int mm30[], int birth_int, int *yy, int* mm, int* dd);
int isNum(char birth[]);

void print_birth(int yy, int mm, int dd) {
	if (yy < 10)
		printf("190%d년 %d월 %d일생입니다.\n", yy, mm, dd);
	else
		printf("19%d년 %d월 %d일생입니다.\n", yy, mm, dd);
}

int isValidBirthday(int mm31[], int mm30[], int birth_int, int* yy, int* mm, int* dd){
	*yy = birth_int / 10000;
	*mm = (birth_int / 100) % 100;
	*dd = birth_int % 100;
	for (int i = 0;i < LONG_MONTH;i++) {
		if (*mm == mm31[i] && *dd >= 1 && *dd <= 31) {
			return 1;
		}
	}
	for (int j = 0; j < SHORT_MONTH; j++) {
		if (*mm == mm30[j] && *dd >= 1 && *dd <= 30) {
			return 1;
		}
	}
	if (((*yy+1900) % 4 == 0 && (*yy + 1900) % 100 != 0) || (*yy + 1900) % 400 == 0) {
		if (*mm == 2 && *dd >= 1 && *dd <= 29) 
			return 1;
		else
			return 0;
	}
	else if (*mm == 2 && *dd >= 1 && *dd <= 28)
		return 1;
	else
		return 0;
}

int isNum(char birth[]) {
	for (int i = 0; i < 6; i++) {
		if (birth[i] <= '9' && birth[i] >= '0') {
			continue;
		}
		else
			return 0;
	}
	return 1;
}

int main() {
	char birth[15] = "";
	int birth_int = 0, yy = 0, mm = 0, dd = 0;
	int mm31[LONG_MONTH] = { 1, 3, 5, 7, 8, 10, 12 };
	int mm30[SHORT_MONTH] = { 4, 6, 9, 11 };

	while (1) {
		yy = 0, mm = 0, dd = 0;
		printf("생년월일을 6자리로 입력해주세요.: ");
		scanf("%s", birth);
		if (strlen(birth) != 6)
			continue;

		if (isNum(birth)) {
			sscanf(birth, "%d", &birth_int);
			if (isValidBirthday(mm31, mm30, birth_int, &yy, &mm, &dd))
				print_birth(yy, mm, dd);
			else
				printf("%d라는 생년월일을 달력에서 찾을 수 없습니다. 날짜를 확인해주세요. \n", birth_int);
		}
		else
			printf("숫자만 입력해주세요.\n");
	}

	return 0;
}