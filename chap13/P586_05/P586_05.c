#include <stdio.h>

struct point {
	int x;
	int y;
} p1 = { 1, 2 }, p2 = { 3, 5 }, p3 = { 1, 2 }, p4 = { 3, 5 };


int equal(struct point p1, struct point p2);
void print_result(int isequal, struct point p1, struct point p2);

int equal(struct point p1, struct point p2) {
	if(p1.x == p2.x && p1.y == p2.y)
		return 1;
	else
		return 0;
}
void print_result(int isequal, struct point p1, struct point p2) {

	switch (isequal) {
	case 0:
		printf("(%d, %d) != (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
		break;
	case 1:
		printf("(%d, %d) == (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
		break;
	default:
		printf("equal()의 반환값에 오류\n");
		break;
	}
}
int main() {
	int isequal;

	isequal = equal(p1, p2);

	print_result(isequal, p1, p2);

	isequal = equal(p1, p3);

	print_result(isequal, p1, p3);

	isequal = equal(p4, p2);

	print_result(isequal, p4, p2);

	isequal = equal(p3, p4);

	print_result(isequal, p3, p4);

	return 0;
}

/*
프로그램 작성에 어려워하는 부분

발생한 오류의 원인

맞는 레벨이었는지?

푸는 시간
	2025/02/10 15:15~15:30 15분
*/