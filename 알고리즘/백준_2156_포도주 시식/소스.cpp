// 포도주 시식
#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2);
int main() {
	int n, i, input, max_value = 0;
	int arr[10001], sum[10001];

	scanf_s("%d", &n);

	for (i = 1; i < n + 1; i++) { 
		scanf_s("%d", &input); arr[i] = input;
		if (i == 1) { sum[i] = input; }
		else if (i == 2) { sum[i] = arr[i - 1] + input; }
		else { 
			sum[i] = max(arr[i] + arr[i - 1] + sum[i - 3], max(sum[i-1], sum[i - 2] + arr[i]));
		}
	}

	printf("%d", sum[n]);

	return 0;
}
int max(int num1, int num2) {
	if (num1 >= num2) return num1;
	else return num2;
}