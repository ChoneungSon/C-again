// ��Ŭ���� ȣ���� �ִ����� ���ϱ�
#include <stdio.h>
int max_same(int m, int n) {
	int temp;
	if (m == n) { return m; }
	else if (m < n) {
		temp = m;
		m = n; n = temp;
	}
	if (m % n == 0) { return n; }
	else { return max_same(m % n, n); }
}
int main() {
	int m, n;
	printf("�� ���� �Է��Ͻÿ�. : ");
	scanf_s("%d %d", &m, &n);
	printf("�� ���� �ִ������� %d �Դϴ�.", max_same(m, n));
	return 0;
}