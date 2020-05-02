// 유클리드 호제법 최대공약수 구하기
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
	printf("두 수를 입력하시오. : ");
	scanf_s("%d %d", &m, &n);
	printf("두 수의 최대공약수는 %d 입니다.", max_same(m, n));
	return 0;
}