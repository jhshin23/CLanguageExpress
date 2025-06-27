#define FIVE 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int ten_num[FIVE] = { 0 };
	int sum = 0, avg = 0;
	for (int i = 0; i < FIVE; i++) {
		scanf("%d", &ten_num[i]);
		sum += ten_num[i];
	}
	avg = sum / FIVE;
	printf("%d, %d", sum, avg);
	return 0;
}