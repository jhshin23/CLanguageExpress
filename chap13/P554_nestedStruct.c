#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int get_circumference_rect(const struct point_opposite *rect);
int get_area_rect(const struct point_opposite *rect);

struct point {
	int x;
	int y;
};

struct point_opposite {
	struct point p1;
	struct point p2;
};

int get_area_rect(const struct point_opposite *rect) {
	int a = (rect->p1.x - rect->p2.x) * (rect->p1.y - rect->p2.y);
	return (int)sqrt(a * a);
}

int get_circumference_rect(const struct point_opposite *rect) {
	int c = ((rect->p1.x - rect->p2.x) + (rect->p1.y - rect->p2.y)) * 2;
	return (int)sqrt(c * c);
}
int main() {
	struct point_opposite rect;
	printf("사각형의 꼭지점 1개의 좌표를 입력해주세요: ");
	scanf("%d %d", &rect.p1.x, &rect.p1.y);
	printf("대각선 반대쪽 꼭지점의 좌표를 입력해주세요: ");
	scanf("%d %d", &rect.p2.x, &rect.p2.y);

	printf("면적은 %d이고 ", get_area_rect(&rect));
	printf("둘레는 %d입니다.\n", get_circumference_rect(&rect));

	return 0;
}
/*
프로그램 작성에 어려워하는 부분
	중첩구조체를 받는 함수의 매개변수 선언하다가 매개변수에 빨간 줄
발생한 오류의 원인
	모름
맞는 레벨이었는지?
	구조체 함수 전달은 교재 복습 진도 보다 뒤에 있었음. 문제에서 요구하지 않았고 적절하지 않은 자습이었다. 
	교재는 메인 함수에서 구조체 변수를 연산해서 다른 변수로 저장했음.
	함수 분리를 하고싶었으면 교재 풀이처럼 구조체 바깥에 변수를 만들었어야 함.
푸는 시간
	2025/01/21 17:10~18:00 50분
				20:17~20:22	5분	구조체 포인터로 함수로 전달하기
*/
