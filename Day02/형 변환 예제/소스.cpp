#include <stdio.h>
int main() {
	float num, i;
	printf("�Ǽ��� �Է��ϼ���. : ");
	scanf_s("%f", &num);
	i = (num - (int)num) * 100;
	printf("%d", (int)i);
}