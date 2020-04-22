#include <stdio.h>
int main() {
	int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
	printf("sizeof(arr[0]) : %d\n", sizeof(arr[0]));
	printf("sizeof(arr[0][0]) : %d\n", sizeof(arr[0][0]));
	return 0;
}