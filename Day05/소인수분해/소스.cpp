// ���μ� ����
#include <stdio.h>
int soinsu(int num) {
	int i = 2;
	if (num <= 2) {
		printf("%d", num);
		return 0;
	}
	while (num != 1) {
		if (num % i == 0) {
			printf("%d ", i);
			num /= i;
			if (num != 1) {
				printf("X ");
			}
			else { return 0; }
		}
		else {
			i++;
		}
	}
	return 0;
}
int main() {
	int N;
	printf("���μ� ���ظ� ���ϴ� ���� �Է��Ͻÿ�. : ");
	scanf_s("%d", &N);
	soinsu(N);
	return 0;
}