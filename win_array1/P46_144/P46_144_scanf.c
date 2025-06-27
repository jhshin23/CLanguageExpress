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
	//char birth[7];
	int birth_int = 0, yy = 0, mm = 0, dd = 0;
	while (1) {
		printf("생년월일을 6자리로 입력해주세요.: ");

		//gets_s(birth, 7);
		//scanf(birth, "%d", &birth_int);
		scanf("%d", &birth_int);

		yy = birth_int / 10000;
		mm = (birth_int / 100) % 100;
		dd = birth_int % 100;

		switch (mm) {

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:

			if (dd >= 1 && dd <= 31)
				print_birth(yy, mm, dd);
			break;

		case 4:
		case 6:
		case 9:
		case 11:

			if (dd >= 1 && dd <= 30)
				print_birth(yy, mm, dd);
			break;
		case 2:
			if (dd >= 1 && dd <= 29)
				print_birth(yy, mm, dd);
		default:
			printf("%d라는 생년월일을 달력에서 찾을 수 없습니다. 날짜를 확인해주세요. \n", birth_int);
		}

	}


	return 0;
}