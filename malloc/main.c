#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main() {
	char* p = malloc(1024*1024*1024);
	scanf("%c", p);
}