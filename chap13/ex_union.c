#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int a[3] = { 0, 1, 2 };
	char ch[3] = "ab";
	printf("%d %c\n\n", a[3], ch[3]); // int�����Ⱚ char�����Ⱚ('?') ���

	union ic {
		int x;
		char ch;
		char ca[4];
	};

	union ic xc = { 'Q' };//x, ca, ch ��� �ʱ�ȭ?
	printf("%d %c %s\n", xc.x, xc.ch, xc.ca); //81 'Q' 'Q' ���

	xc.x = 65;
	printf("%d %c %s\n", xc.x, xc.ch, xc.ca);  // 65 'A' 'A' ���

	strcpy(xc.ca, "QQQ");
	printf("%d %s\n", xc.x, xc.ca); // 5329233 "QQQ" ���

	xc.x = 80000;
	printf("%d %c %s\n", xc.x, xc.ch, xc.ca);  // 80000  8

	xc.ch = 'A';
	printf("%d %c %s\n", xc.x, xc.ch, xc.ca);  // 79937 A A8

	strcpy(xc.ca, "SSS");
	printf("%d %c %s\n", xc.x, xc.ch, xc.ca);  // 5460819 S SSS

	printf("%u", sizeof(xc));  // 4byte

}
/*	���߿� ����
	2025/01/22 11:50
*/
