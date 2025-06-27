#define _CRT_SECURE_NO_WARNINGS
#define TEN 10
#include <stdio.h>

int get_min_to_max(int a[]);
void scan_num(int a[]);

int get_min_to_max(int a[]) {
	int min = a[0], max = a[0];
	for (int i = 0; i < TEN; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	return max - min;
}

void scan_num(int a[]) {
	for (int i = 0; i < TEN; i++) {
		scanf("%d", &a[i]);
	}
}


int main() {
	int a[10] = { 0 };
	
	scan_num(a);
	printf("\nmax-min = %d\n", get_min_to_max(a));
	return 0;
}