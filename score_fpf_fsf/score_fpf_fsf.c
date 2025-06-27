#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp = NULL;
	char fname[100];
	int number, count = 0;
	char name[20];
	float score, total = 0.0;

	printf("성적 파일 이름을 입력하시오: ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "w")) == NULL) {
		fprintf(stderr, "성적 파일 %s를 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (1) {
		printf("학번, 이름, 성적을 입력하시오: (음수이면 종료) ");
		scanf("%d", &number);
		if (number < 0) break;
		scanf("%s %f", name, &score);
		fprintf(fp, " %d %s %f", number, name, score);
	}
	fclose(fp);

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "성적 파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}

	while (!feof(fp)) {
		fscanf(fp, "%d %s %f", &number, name, &score);
		total += score;
		count++;
	}
	printf("평균 = %.2f\n", total / count);
	fclose(fp);

	return 0;
}


// 형식화된 입력은 형식화된 출력으로 만든 파일로만 되나?
// 아니라면 어떻게 파일로부터 자료형을 구분해서 변수에 입력하지