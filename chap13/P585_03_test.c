#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct test_form {
	char* test1;
	char* test2;
};

void testinput(char** str) {
	*str = getchar();

}

void testrun(struct test_form* pform) {
	printf("�׽�Ʈ1: \n");
	testinput(&(pform->test1));
	printf("�׽�Ʈ2: \n");
	testinput(&(pform->test2));
}

int main() {
	struct test_form hello;

	testrun(&hello);
}
