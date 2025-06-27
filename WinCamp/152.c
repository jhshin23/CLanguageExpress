#include <stdio.h>

int main() {
	int a[3][3] = { {2, 4, 6}, {8, 10, 12}, {14, 16, 18} };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%2d ", a[j][i]);
		}
		printf("\n");
	}
	return 0;
}