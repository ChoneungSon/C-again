// 도서 관리 프로그램
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
		printf("사용할 기능을 선택하세요.\n");
		printf("1: 신규도서 추가, 2: 도서 검색, 3: 도서 대여, 4: 도서 반납, 5: 끝내기 >> ");
		scanf_s("%d", &method);
		if (method == 1) add(name_arr, author_arr, publish_arr);
		else if (method == 2) {
			printf("어떤 항목을 검색할 지를 선택하세요.\n");
			printf("1: 제목, 2: 작가, 3: 출판사 >> ");
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
		printf("도서 제목을 입력하세요. : ");
		scanf_s("%s", name_arr[i], sizeof(name_arr[i]));
		printf("도서 저자를 입력하세요. : ");
		scanf_s("%s", author_arr[i], sizeof(name_arr[i]));
		printf("도서 출판사를 입력하세요. : ");
		scanf_s("%s", publish_arr[i], sizeof(name_arr[i]));
		printf("도서를 추가하였습니다. \n");
	}
	else {
		printf("도서를 추가할 수 없습니다. \n");
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
	printf("검색 단어를 입력하세요. : ");
	scanf_s("%s", &word, sizeof(word));
	//if (method == 1) temp = name_arr;
	//else if (method == 2) temp = author_arr;
	//else temp = publish_arr;
	while (same(name_arr[i], &word) && i < 100) {
		printf("%d \n", i);
		i++;
	}
	if (i >= 100) printf("도서를 찾을 수 없습니다.\n");
	else printf("도서번호: %d, 제목 : %s, 작가 : %s, 출판사 : %s\n", i, name_arr[i], author_arr[i], publish_arr[i]);
	return 0;
}
int borrow(int* visited) {
	int i;
	printf("빌리려는 도서 번호를 입력하세요. : ");
	scanf_s("%d", &i);
	if (visited[i] == 0) {
		visited[i] = 1; printf("도서 대여가 완료되었습니다.\n");
	}
	else printf("원하는 도서가 대여상태입니다.\n");
	return 0;
}
int Return(int *visited) {
	int i;
	printf("반납하려는 도서 번호를 입력하세요. : ");
	scanf_s("%d", &i);
	if (visited[i] == 1) {
		visited[i] = 0; printf("도서 반납이 완료되었습니다.\n");
	}
	else printf("반납을 원하는 도서가 반납상태입니다.\n");
	return 0;
}