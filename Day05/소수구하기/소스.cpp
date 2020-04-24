// 소수 구하는 함수 구현
#include <stdio.h>
int find_sosu(int num) {
	int i;
	if (num <= 2) { return 1; }
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int N; int i; int j = 0; int arr[100]; int cnt = 0;
	printf("원하는 범위를 입력해주세요. : ");
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++) {
		if (find_sosu(i) == 1) { arr[j++] = i; }
	}
	for (i = 0; i < 100; i++) {
		if (arr[i] > 0) { printf("%d ", arr[i]); cnt++; }
		else { break; }
	}
	int sosu
	return 0;
}