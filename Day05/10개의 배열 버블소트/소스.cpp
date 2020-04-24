// 버블소트 구성하기
#include <stdio.h>
int sort(int* parr) {
	int i, j, idx, temp;

	for (i = 0; i < 9; i++) {
		idx = i;
		for (j = i+1; j < 10; j++) {
			if (parr[idx] > parr[j]) {
				idx = j;
			}
		}
		temp = parr[idx];
		parr[idx] = parr[i];
		parr[i] = temp;
	}
	return 0;
}
int main() {
	int arr[10]; int i;
	int* parr = arr;
	printf("정렬할 수 10개를 입력하시오. : \n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &arr[i]);
	}
	sort(parr);
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}