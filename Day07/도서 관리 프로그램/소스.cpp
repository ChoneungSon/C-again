// ���� ���� ���α׷�
#include <stdio.h>
int add(char (*name_arr)[30], char (*author_arr)[30], char (*publish_arr)[30]);
int find(char(*name_arr)[30], char(*author_arr)[30], char(*publish_arr)[30], int method);
int borrow(int *visited);
int Return(int* visited);
int same(char* word, char* find_word);
int main() {
	int method;
	char name_arr[100][30] = { {'\0',}, };
	char author_arr[100][30] = { {'\0',}, };
	char publish_arr[100][30] = { {'\0',}, };
	int visited[100] = { 0, };
	while (1) {
		printf("����� ����� �����ϼ���.\n");
		printf("1: �űԵ��� �߰�, 2: ���� �˻�, 3: ���� �뿩, 4: ���� �ݳ�, 5: ������ >> ");
		scanf_s("%d", &method);
		if (method == 1) add(name_arr, author_arr, publish_arr);
		else if (method == 2) {
			printf("� �׸��� �˻��� ���� �����ϼ���.\n");
			printf("1: ����, 2: �۰�, 3: ���ǻ� >> ");
			scanf_s("%d", &method);
			find(name_arr, author_arr, publish_arr, method);
		}
		else if (method == 3) borrow(visited);
		else if (method == 4) Return(visited);
		else break;
	}
	return 0;
}
int add(char (*name_arr)[30], char (*author_arr)[30], char (*publish_arr)[30]) {
	int i = 0;
	while (*(name_arr[i])) {
		i++;
	}
	if (i < 100) {
		printf("���� ������ �Է��ϼ���. : ");
		scanf_s("%s", name_arr[i], sizeof(name_arr[i]));
		printf("���� ���ڸ� �Է��ϼ���. : ");
		scanf_s("%s", author_arr[i], sizeof(name_arr[i]));
		printf("���� ���ǻ縦 �Է��ϼ���. : ");
		scanf_s("%s", publish_arr[i], sizeof(name_arr[i]));
		printf("������ �߰��Ͽ����ϴ�. \n");
	}
	else {
		printf("������ �߰��� �� �����ϴ�. \n");
	}
	return 0;
}
int same(char* word, char* find_word) {
	printf("%c %c\n", *word, *find_word);
	while (*word) {
		if (*word != *find_word) return 1;
		word++; find_word++;
	}
	if (*find_word == '\0') return 1;
	return 0;
}
int find(char(*name_arr)[30], char(*author_arr)[30], char(*publish_arr)[30], int method) {
	char (*temp)[30]; int i=0; char word;
	printf("�˻� �ܾ �Է��ϼ���. : ");
	scanf_s("%s", &word, sizeof(word));
	//if (method == 1) temp = name_arr;
	//else if (method == 2) temp = author_arr;
	//else temp = publish_arr;
	while (same(name_arr[i], &word) && i < 100) {
		printf("%d \n", i);
		i++;
	}
	if (i >= 100) printf("������ ã�� �� �����ϴ�.\n");
	else printf("������ȣ: %d, ���� : %s, �۰� : %s, ���ǻ� : %s\n", i, name_arr[i], author_arr[i], publish_arr[i]);
	return 0;
}
int borrow(int* visited) {
	int i;
	printf("�������� ���� ��ȣ�� �Է��ϼ���. : ");
	scanf_s("%d", &i);
	if (visited[i] == 0) {
		visited[i] = 1; printf("���� �뿩�� �Ϸ�Ǿ����ϴ�.\n");
	}
	else printf("���ϴ� ������ �뿩�����Դϴ�.\n");
	return 0;
}
int Return(int *visited) {
	int i;
	printf("�ݳ��Ϸ��� ���� ��ȣ�� �Է��ϼ���. : ");
	scanf_s("%d", &i);
	if (visited[i] == 1) {
		visited[i] = 0; printf("���� �ݳ��� �Ϸ�Ǿ����ϴ�.\n");
	}
	else printf("�ݳ��� ���ϴ� ������ �ݳ������Դϴ�.\n");
	return 0;
}