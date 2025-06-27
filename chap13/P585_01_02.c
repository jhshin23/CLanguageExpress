#include <stdio.h>
#include <string.h>

//열거형: 장르 이름 배열에서 인덱스로 사용함. 제일 큰 마지막 기호상수 ARR_SIZE를 배열 크기용으로 끼워넣음
typedef enum genre { COSMIC, SF, DOCU, DRAMA, ARR_SIZE }GENRE;

void print_book_info(char *genre_str[], const struct book *pbook);
int equal_author(struct book b1, struct book b2);

struct book {
	char title[100]; //b0.title = 바람과 함께 사라지다
	char author[100]; //b0.author = 마가렛 미첼
	GENRE type; //b0.type = DRAMA = 3
};

void print_book_info(char *genre_str[], const struct book *pbook) {
	printf("%s, %s, %s\n", (*pbook).title, pbook->author, genre_str[pbook->type]); 
}

int equal_author(struct book b1, struct book b2) {
	if(strcmp(b1.author, b2.author))
		return 0;
	else
		return 1;
}

int main() {
	//=============== 01 ===============
	//문자 포인터 배열: 장르 이름 배열 출력용
	char *genre_str[ARR_SIZE] = { "COSMIC", "SF", "DOCU", "DRAMA" };
	//구조체 변수 초기화
	struct book b0 = { "바람과 함께 사라지다", "마가렛 미첼", DRAMA };
	//구조체 출력 함수. 인수는 문자 포인터 배열, 구조체 변수 주소
	print_book_info(genre_str, &b0);

	//=============== 02 ===============
	struct book b1 = { "노인과 바다", "헤밍웨이", DRAMA };
	struct book b2 = { "누구를 위하여 종을 울리나", "헤밍웨이", DRAMA };

	printf("equal_author의 반환값: %d\n", equal_author(b1, b2));
	printf("equal_author의 반환값: %d\n", equal_author(b0, b2));

	return 0;
}

/*
프로그램 작성에 어려워하는 부분
	1. 열거형 기호상수를 문자열과 연결시키는 방법을 생각하는 것이 오래 걸렸다.
	2. 문자 포인터 배열
발생한 오류의 원인
	문자 포인터 배열을 함수에 전달하는 법, 출력하는 법을 몰랐다. 
	매개변수에는 *genre_str가 맞다. 그러나 함수 몸체에서는 그냥 genre_str이다. 
	양쪽 다 별을 붙여서 오류가 났다.
	genre_str 문자열 포인터의	genre_str[3]가 "DRAMA"를 가리킨다면? 
				=>				*genre_str[3]는 텍스트 세그먼트의 "DRAMA"의 주소가 가리키는 'D'이다.
				// printf(" %c", *genre_str[3]);  // 'D'
맞는 레벨이었는지?
	맞았다. 그러나
	문자 포인터 배열은 교재에서 별로 비중이 없어서 학습이 부족했는데 괜히 자습으로 시도해서 어려워졌다. 
푸는 시간
	1번 문제: 1시간 30분
	2025/01/22 14:00~15:30
	2번 문제: 20분
	2025/01/22 15:50~16:10

*/