#define _CRT_SECURE_NO_WARNINGS
#define PERSON 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_min(int score[]);
int index_of_min(int score[], int mini);
void print_score(int score[]);
double get_average(int score[]);


int get_min(int score[]) {
	int mini = score[0];
	for (int i = 0;i < PERSON;i++) {
		if (mini > score[i]) {
			mini = score[i];
		}
	}
	return mini;
}

int index_of_min(int score[], int mini) {
	for (int i = 0;i < PERSON;i++) {
		if (score[i] == mini)
			return i;
	}
}

void print_score(int score[]) {
	printf("최소 점수 %d,  평균 점수 %.2f\n", score[index_of_min(score, get_min(score))], get_average(score));
}

double get_average(int score[]) {
	int sum = 0;
	double avg = 0;
	for (int i = 0;i < PERSON;i++) {
		sum += score[i];
	}
	avg = (double)sum / (double)PERSON;
	return avg;
}

int main() {
	int score[PERSON] = { 15, 4, 8, 9, 13, 12, 10, 9, 11, 6 };
	print_score(score);
	return 0;
}