#include <stdio.h>
int main() {
	int N, i, j;
	printf("�ﰢ���� ���̸� �Է��ϼ���. : ");
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++) {
		for (j = 0; j < N-i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2*i-1; j++) {
			printf("*");
		}
		printf("\n");
	}
}