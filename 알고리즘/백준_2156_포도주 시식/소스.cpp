// 포도주 시식
#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2);
int main() {
	int n, i, input, max_value;
	int sum1[10001], sum2[10001];

	scanf_s("%d", &n);

	for (i = 1; i < n + 1; i++) { 
		scanf_s("%d", &input);
		if (i == 1) { sum1[i] = sum2[i] = input; max_value = input; }
		else { 
			sum1[i] = sum2[i - 1] + input;
			sum2[i] = input + max(sum2[i - 2], sum1[i - 2]); 
			max_value = max(max_value, max(sum1[i], sum2[i]));
		}
	}

	printf("%d", max_value);

	return 0;
}
int max(int num1, int num2) {
	if (num1 >= num2) return num1;
	else return num2;
}