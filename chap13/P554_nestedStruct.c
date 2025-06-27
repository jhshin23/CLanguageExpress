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
	printf("�簢���� ������ 1���� ��ǥ�� �Է����ּ���: ");
	scanf("%d %d", &rect.p1.x, &rect.p1.y);
	printf("�밢�� �ݴ��� �������� ��ǥ�� �Է����ּ���: ");
	scanf("%d %d", &rect.p2.x, &rect.p2.y);

	printf("������ %d�̰� ", get_area_rect(&rect));
	printf("�ѷ��� %d�Դϴ�.\n", get_circumference_rect(&rect));

	return 0;
}
/*
���α׷� �ۼ��� ������ϴ� �κ�
	��ø����ü�� �޴� �Լ��� �Ű����� �����ϴٰ� �Ű������� ���� ��
�߻��� ������ ����
	��
�´� �����̾�����?
	����ü �Լ� ������ ���� ���� ���� ���� �ڿ� �־���. �������� �䱸���� �ʾҰ� �������� ���� �ڽ��̾���. 
	����� ���� �Լ����� ����ü ������ �����ؼ� �ٸ� ������ ��������.
	�Լ� �и��� �ϰ�;����� ���� Ǯ��ó�� ����ü �ٱ��� ������ �������� ��.
Ǫ�� �ð�
	2025/01/21 17:10~18:00 50��
				20:17~20:22	5��	����ü �����ͷ� �Լ��� �����ϱ�
*/
