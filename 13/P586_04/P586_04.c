#include <stdio.h>

struct complex {
	double real;
	double imag;
};

struct complex complex_add(struct complex c1, struct complex c2);
void print_complex_expression(struct complex c1, struct complex c2, struct complex result);
struct complex complex_add(struct complex c1, struct complex c2) {
	struct complex result;

	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;

	return result;
}

void print_complex_expression(struct complex c1, struct complex c2, struct complex result) {
	printf("%.2f+%.2fi + %.2f+%.2fi = %.2f+%.2fi\n", c1.real, c1.imag, c2.real, c2.imag, result.real, result.imag);
}

int main() {
	struct complex c1 = { 1, 2 };
	struct complex c2 = { 2, 3 };

	print_complex_expression(c1, c2, complex_add(c1, c2));
	return 0;
}


/*
프로그램 작성에 어려워하는 부분

발생한 오류의 원인

맞는 레벨이었는지?

푸는 시간
 2025/02/10 14:55~15:10 15분
*/