#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************���������Ʈ ����****************/
int main() {
	FILE* fp;
	char fname[128], buffer[256], word[256];
	int line_num = 0;

	printf("�Է� ���� �̸��� �Է��Ͻÿ�: ");
	scanf("%s", fname);

	printf("Ž���� �ܾ �Է��Ͻÿ�: ");
	scanf("%s", word);

	if ((fp = fopen(fname, "r")) == NULL) {
		fprintf(stderr, "���� %s�� �� �� �����ϴ�", fname);
		exit(1);
	}

	while (fgets(buffer, 256, fp)) {
		line_num++;
		if (strstr(buffer, word))
			printf("%s: %d %s\n", fname, line_num, buffer);
	}
	fclose(fp);
	return 0;
}
