	#define NINE 9
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>


	void init_inning(int inning[]);
	void save_score(int inning[], int *total_score);
	void print_score(int inning[], int team0_score[], int team1_score[], int total_score_team0, int total_score_team1);

	void init_inning(int inning[]) {
		for (int i = 0; i < NINE; i++) {
			inning[i] = i + 1;
		}
	}

	void save_score(int inning[], int *total_score) {
		for (int i = 0; i < NINE; i++) {
			inning[i] = rand() % 4;
			*total_score += inning[i];
		}

	}

	void print_score(int inning[], int team0_score[], int team1_score[], int total_score_team0, int total_score_team1) {
		printf("야구 스코어\n\n");

		printf("회\t");
		for (int i = 0; i < NINE; i++) {
			printf("%2d ", inning[i]);
		}
		printf("Run\n");

		printf("Korea\t");
		for (int i = 0; i < NINE; i++) {
			printf("%2d ", team0_score[i]);
		}
		printf("%2d\n", total_score_team0);

		printf("Japan\t");
		for (int i = 0; i < NINE; i++) {
			printf("%2d ", team1_score[i]);
		}
		printf("%2d\n", total_score_team1);

	}

	int main() {
		srand((unsigned int)time(NULL));
		int inning[NINE] = { 0 };
		int team_0_inning[NINE] = { 0 };
		int team_1_inning[NINE] = { 0 };
		int total_score_team0 = 0, total_score_team1 = 0;

		init_inning(inning);
		save_score(team_0_inning, &total_score_team0);
		save_score(team_1_inning, &total_score_team1);
		print_score(inning, team_0_inning, team_1_inning, total_score_team0, total_score_team1);

		return 0;
	}