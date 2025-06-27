#include <stdio.h>
#include <string.h>

//������: �帣 �̸� �迭���� �ε����� �����. ���� ū ������ ��ȣ��� ARR_SIZE�� �迭 ũ������� ��������
typedef enum genre { COSMIC, SF, DOCU, DRAMA, ARR_SIZE }GENRE;

void print_book_info(char *genre_str[], const struct book *pbook);
int equal_author(struct book b1, struct book b2);

struct book {
	char title[100]; //b0.title = �ٶ��� �Բ� �������
	char author[100]; //b0.author = ������ ��ÿ
	GENRE type; //b0.type = DRAMA = 3
};

void print_book_info(char *genre_str[], const struct book *pbook) {
	printf("%s, %s, %s\n", (*pbook).title, pbook->author, genre_str[pbook->type]); 
}

int equal_author(struct book b1, struct book b2) {
	if(strcmp(b1.author, b2.author))
		return 0;
	else
		return 1;
}

int main() {
	//=============== 01 ===============
	//���� ������ �迭: �帣 �̸� �迭 ��¿�
	char *genre_str[ARR_SIZE] = { "COSMIC", "SF", "DOCU", "DRAMA" };
	//����ü ���� �ʱ�ȭ
	struct book b0 = { "�ٶ��� �Բ� �������", "������ ��ÿ", DRAMA };
	//����ü ��� �Լ�. �μ��� ���� ������ �迭, ����ü ���� �ּ�
	print_book_info(genre_str, &b0);

	//=============== 02 ===============
	struct book b1 = { "���ΰ� �ٴ�", "��ֿ���", DRAMA };
	struct book b2 = { "������ ���Ͽ� ���� �︮��", "��ֿ���", DRAMA };

	printf("equal_author�� ��ȯ��: %d\n", equal_author(b1, b2));
	printf("equal_author�� ��ȯ��: %d\n", equal_author(b0, b2));

	return 0;
}

/*
���α׷� �ۼ��� ������ϴ� �κ�
	1. ������ ��ȣ����� ���ڿ��� �����Ű�� ����� �����ϴ� ���� ���� �ɷȴ�.
	2. ���� ������ �迭
�߻��� ������ ����
	���� ������ �迭�� �Լ��� �����ϴ� ��, ����ϴ� ���� ������. 
	�Ű��������� *genre_str�� �´�. �׷��� �Լ� ��ü������ �׳� genre_str�̴�. 
	���� �� ���� �ٿ��� ������ ����.
	genre_str ���ڿ� ��������	genre_str[3]�� "DRAMA"�� ����Ų�ٸ�? 
				=>				*genre_str[3]�� �ؽ�Ʈ ���׸�Ʈ�� "DRAMA"�� �ּҰ� ����Ű�� 'D'�̴�.
				// printf(" %c", *genre_str[3]);  // 'D'
�´� �����̾�����?
	�¾Ҵ�. �׷���
	���� ������ �迭�� ���翡�� ���� ������ ��� �н��� �����ߴµ� ���� �ڽ����� �õ��ؼ� ���������. 
Ǫ�� �ð�
	1�� ����: 1�ð� 30��
	2025/01/22 14:00~15:30
	2�� ����: 20��
	2025/01/22 15:50~16:10

*/