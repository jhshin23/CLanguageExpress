#include <stdio.h>

//================================== struct book, typedef BOOK ========================//
struct book {
	char title;
	enum colors { white, red = 3, blue, green, black = 9 } color; //0, 3, 4, 5, 9
	//교수님: c는 자료형 확인이 느슨하다. 변수에 기호상수만 대입하도록 특별히 조심해야한다.
	//입력 예외처리.
};

typedef struct book BOOK;

//================================== typedef CONTACT ========================//
typedef struct contact {
	char email_address[30];
	enum check_cellphone_010 { NO, YES } check_010;
	int cellphone;
} CONTACT;

//================================== print typedef CONTACT ========================//
void print_typedef(CONTACT student);
void print_typedef_p(const CONTACT *pstudent);

void print_typedef(CONTACT student) {  //모두 값으로 받는다.
	printf("%s\n", student.email_address); //배열 email_addres도 구조체의 일부라서 복사본이다.
	printf("%d\n", student.check_010);
	printf("%d\n", student.cellphone);
}

void print_typedef_p(const CONTACT *pstudent) {
	printf("%s\n", (*pstudent).email_address);
	printf("%d\n", pstudent->check_010);
	printf("%d\n", pstudent->cellphone);
}

int main() {

	//================================== CONTACT ========================//
	CONTACT student = { "sdafs@hmail.com", YES, 12345678 };
	CONTACT *pstudent = &student;

	print_typedef(student);
	print_typedef_p(&student);


	//================================== book, BOOK ========================//
	BOOK cheak = { 'k', blue };
	BOOK* pcheak = &cheak;
	printf("%c %d\n", pcheak->title, pcheak->color);

	struct book b = { 'c', red };
	struct book* abook = &b;
	printf("%c %d\n", b.title, b.color);

	abook = &b;

	abook->title = 'b';
	(*abook).color = white;
	printf("%c %d\n", abook->title, abook->color);

	(*abook).title = 'a';
	(*abook).color = black;
	printf("%c %d\n", abook->title, abook->color);

	switch (abook->color) {
	case white:
		printf("하얗다");
		break;
	case red:
		printf("빨갛다");
		break;
	case blue:
		printf("파랗다");
		break;
	case green:
		printf("푸르다");
		break;
	case black:
		printf("검다");
		break;
	default:		
		printf("표현할 수 없는 색입니다.");
		break;
	}
}