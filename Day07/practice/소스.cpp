// ¿¬½À
#include <stdio.h>
int main() {
	int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int (*parr)[3] = arr;
	int* pparr = parr[1];
	int i;

	for (i = 0; i < 3; i++) {
		printf("%d", pparr[i]);
	}
	return 0;

}