#include <stdio.h>
#include <stdlib.h>

int main() {
	int* pi;
	double* pd;
	char* pc;

	pi = (int*)(malloc(sizeof(int)));
	pd = (double*)(malloc(sizeof(double)));
	pc = (char*)(malloc(sizeof(char)));

	if (pi == NULL || pd == NULL || pc == NULL) {
		printf("동적 메모리 할당 오류");
		exit(1);
	}

	printf("%d\n", pi[0]);
	printf("%f\n", pd[0]);
	printf("%c\n", pc[0]);

	*pi = 100;
	*pd = 3.14;
	*pc = 'a';

	printf("%d\n", pi[0]);
	printf("%f\n", pd[0]);
	printf("%c\n", pc[0]);

	free(pi);
	free(pd);
	free(pc);


	printf("%d\n", pi[0]);
	printf("%f\n", pd[0]);
	printf("%c\n", pc[0]);

	int* list;
	int size = 3;
	list = (int*)malloc(sizeof(int)* size);
	if (list == NULL) {
		printf("동적 메모리 할당 오류");
		exit(1);
	}

	list[0] = 99;
	list[1] = 55;
	list[2] = 11;
	printf("%d\n", list[0]);
	printf("%d\n", list[1]);
	printf("%d\n", list[2]);

	free(list);
	return 0;
}