#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_birth(int yy, int mm, int dd);

void print_birth(int yy, int mm, int dd) {
	if (yy < 10)
		printf("190%d년 %d월 %d일생입니다.\n", yy, mm, dd);
	else
		printf("19%d년 %d월 %d일생입니다.\n", yy, mm, dd);
}

int main() {
	char birth[7];
	int birth_int = 0, yy = 0, mm = 0, dd = 0;
	int mm31[7] = { 1, 3, 5, 7, 8, 10, 12 };
	int mm30[4] = { 4, 6, 9, 11 };
	while (1) {
		printf("생년월일을 6자리로 입력해주세요.: ");

		gets_s(birth, 7);
		sscanf(birth, "%d", &birth_int);

		yy = birth_int / 10000;
		mm = (birth_int / 100) % 100;
		dd = birth_int % 100;

		if (1 <= mm && mm >= 12) {
			for (int i = 0;i < 7;i++) {
				if (mm == mm31[i] && dd >= 1 && dd <= 31)
					print_birth(yy, mm, dd);
				else if (mm == mm30[i] && dd >= 1 && dd <= 30)
					print_birth(yy, mm, dd);
				else if (mm == 2 && dd >= 1 && dd <= 29)
					print_birth(yy, mm, dd);
				else
					printf("%d라는 생년월일을 달력에서 찾을 수 없습니다. 날짜를 확인해주세요. \n", birth_int);
			}
		}
		else
			printf("%d라는 생년월일을 달력에서 찾을 수 없습니다. 날짜를 확인해주세요. \n", birth_int);

	}


	return 0;
}