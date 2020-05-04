// 단어찾기
#include <stdio.h>
int find_word(char *word, char* str);
int main() {
	char word[30];
	char str[] = "I_am_a_boy";
	printf("찾을 단어를 입력하시오. : ");
	scanf_s("%s", word, sizeof(word));
	printf("%d", find_word(word, str));
	return 0;
}
int find_word(char *word, char *str) {
	int cnt = 1; int flag = 0; char* temp = word;
	while (*str) {
		if (*str=='_') {
			cnt++; word = temp;
		}
		else if (*str == *word) {
			str++; word++;
			while (*word) {
				if (*word != *str) word = temp; flag = 1; break;
				word++; str++;
			}
			if (flag) return cnt;
			flag = 0;
		}
		str++;
	}
	return -1;
}