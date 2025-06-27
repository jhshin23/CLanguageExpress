#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double get_distance(struct point p1, struct point p2);

struct point {
	int x;
	int y;
};

double get_distance(struct point p1, struct point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
int main() {
	struct point p1, p2;
	
	printf("점의 좌표를 입력하시오(x y): ");
	scanf("%d %d", &p1.x, &p1.y);
	printf("점의 좌표를 입력하시오(x y): ");
	scanf("%d %d", &p2.x, &p2.y);

	////함수포인터 연습
	//double (*pget_dst)(struct point, struct point);
	//pget_dst = get_distance;
	//printf("거리는 %f입니다.\n", pget_dst(p1, p2));

	printf("거리는 %f입니다.\n", get_distance(p1, p2));


	return 0;
}