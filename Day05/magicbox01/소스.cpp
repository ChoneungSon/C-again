// ������ ���� 4�� ���� ���� ��ȯ�ϴ� �Լ�
#include <stdio.h>
int magicbox(int n) {
	return n + 4;
}
int main() {
	int num;
	printf("������ ���� �����Ͻÿ�. : ");
	scanf_s("%d", &num);
	printf("%d�� 4�� ���� ���� %d�Դϴ�.", num, magicbox(num));
	return 0;
}