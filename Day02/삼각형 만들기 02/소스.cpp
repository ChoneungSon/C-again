#include <stdio.h>
int main() {
	int N, i, j;
	printf("삼각형의 높이를 입력하시오. : ");
	scanf_s("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * (N - i) - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}