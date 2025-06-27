#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
enum form_length {TITLE=100, SENDER=50, RECEIVE=50, CONTENT=3000, DATE=11}SIZE;
enum pri { FIRST = 1, SECOND, THIRD } PRI;

void fill_5_form(struct email_form* pform);
void fill_PRI(struct email_form* pform);
void init_charr(char str[], enum form_length SIZE);
void print_6_form(const struct email_form* pform);

struct email_form {
	char title[TITLE];
	char receiver[RECEIVE];
	char sender[SENDER];
	char content[CONTENT];
	char date[DATE];
	enum PRI pri;
};
void fill_5_form(struct email_form * pform) {
	printf("제목: \n");
	init_charr(pform->title, TITLE);
	printf("수신자: \n");
	init_charr(pform->receiver, RECEIVE);
	printf("발신자: \n");
	init_charr(pform->sender, SENDER);
	printf("내용: \n");
	init_charr(pform->content, CONTENT);
	printf("날짜: \n");
	init_charr(pform->date, DATE);
}

void fill_PRI(struct email_form* pform) {
	while (pform->pri > 3 || pform->pri < 1) {
		printf("우선순위: 1, 2, 3\n");
		scanf(" %d", &pform->pri);
		while (getchar() != '\n') { 
			getchar(); 
		}
		switch (pform->pri)
		{
			case FIRST:
			case SECOND:
			case THIRD:
				break;

			default:
				printf("우선순위를 1, 2, 3 중 하나로 입력해주세요.\n");
				break;
		}
	}
}

void init_charr(char str[], enum form_length SIZE) {
//	 구조체 email_form에 char * title 선언, 인수는 (&pform), 매개변수는 (char **str)
//	*str = getchar(); // 9:21에 이렇게 해봤으나 첫 호출에서 제목 입력만 한 번 실행되고 다음 호출에는 건너뛰어버림. 
//						->	02 / 10 : 이렇게 못한다고 교재 p562~3에 나와있다. getchar사용법을 이제라도 배워서 다행이다

	gets_s(str, SIZE);
}

void print_6_form(const struct email_form * pform) {
	printf("제목: %s\n", pform->title);
	printf("수신자: %s\n", pform->receiver);
	printf("발신자: %s\n", pform->sender);
	printf("내용: %s\n", pform->content);
	printf("날짜: %s\n", pform->date);
	printf("우선순위: %d\n", pform->pri);
}


int main() {
	struct email_form hello;

	fill_5_form(&hello);
	fill_PRI(&hello);
	print_6_form(&hello);

	return 0;
}

/*
프로그램 작성에 어려워하는 부분
	문자열 입력
	문자열 포인터에는 입력을 못하나?
	 ->02/10 : 그렇다. 못한다고 교재 p562~3에 나와있다

	enum으로 오류가 잘 걸러지지 않는 것 같음
발생한 오류의 원인
	문자열 포인터에 입력하려고 했다가 오류
		=>배열 문자열로 바꿔서 실행되도록 함.
맞는 레벨이었는지?
	포인터를 쓰라고 하면 못 품.
	배열로 하면 쉬움. 그러나
		=>사이즈용 기호상수를 잔뜩 만들어야 해서 아쉬움
푸는 시간
	2025/01/23 9:00~10:50	1시간 50분
	2025/02/10 교재 p562~3을 다시 읽고 오류의 원인을 확실히 알았음

*/