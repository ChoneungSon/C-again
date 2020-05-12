// 파이프 옮기기 1 백준
#include <stdio.h>
#include <stdlib.h>
int main() {
	int i, j, n; int **arr, **move_p, **move_h, **move_d;

	scanf_s("%d", &n);

	arr = (int**)malloc(sizeof(int*) * n);
	move_p = (int**)malloc(sizeof(int*) * n);
	move_h = (int**)malloc(sizeof(int*) * n);
	move_d = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			arr[i] = (int*)malloc(sizeof(int) * n);
			move_p[i] = (int*)malloc(sizeof(int) * n);
			move_h[i] = (int*)malloc(sizeof(int) * n);
			move_d[i] = (int*)malloc(sizeof(int) * n);
		}
	}

}