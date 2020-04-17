#include <stdio.h>
int main() {
	float num, i;
	printf("실수를 입력하세요. : ");
	scanf_s("%f", &num);
	i = (num - (int)num) * 100;
	printf("%d", (int)i);
}