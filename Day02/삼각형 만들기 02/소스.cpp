#include <stdio.h>
int main() {
	int N, i, j;
	printf("�ﰢ���� ���̸� �Է��Ͻÿ�. : ");
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