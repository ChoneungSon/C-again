// 포인터 연습
#include <stdio.h>
int main() {
	int a = 4;
	const int* p = &a;
	printf("p: %p, *p: %d, a: %d\n", p, *p, a);
	a = 3;
	printf("p: %p, *p: %d, a: %d", p, *p, a);
	return 0;
}