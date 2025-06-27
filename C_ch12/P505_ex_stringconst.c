#include <stdio.h>

int main() {

	char* p = "HelloWorld";
	printf("%s \n", p);

	p = "Welcome to C World";
	printf("%s \n", p);

	p = "Goodbye";
	printf("%s \n", p);

	//p[0] = 'a' //오류

	return 0;
}