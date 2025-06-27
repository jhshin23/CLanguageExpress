#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char* pfname = "image";
	char* pextention = ".jpg";
	char fullname_file[10][15] = {"","", "", "", "", "", "", "", "", ""};
	for (int i = 0; i < 10; i++) {
		sprintf(fullname_file[i], "%s%d%s", pfname, i, pextention);
		printf("%s\n", fullname_file[i]);
	}

	return 0;
}