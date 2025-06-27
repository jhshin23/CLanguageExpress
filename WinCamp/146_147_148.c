#define _CRT_SECURE_NO_WARNINGS
#define N 12
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_min(int n[]);
int get_min_index(int n[], int mini);

int get_min(int n[]) {
	int mini = n[0];
	for (int i = 0;i < N;i++) {
		if (mini > n[i]) {
			mini = n[i];
		}
	}

	return mini;
}

int get_min_index(int n[], int mini) {
	for (int i = 0;i < N;i++) {
		if (n[i] == mini)
			return i;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int n[N];
	for (int i = 0;i < N;i++) {
		n[i] = rand();
		printf("%d ", n[i]);
	}
	printf("\n");
	printf("%d\n", get_min(n));
	printf("%d", get_min_index(n, get_min(n)));

	return 0;
}