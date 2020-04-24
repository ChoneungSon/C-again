// 대입한 값에 4를 더한 값을 반환하는 함수
#include <stdio.h>
int magicbox(int n) {
	return n + 4;
}
int main() {
	int num;
	printf("대입할 값을 선택하시오. : ");
	scanf_s("%d", &num);
	printf("%d에 4를 더한 값은 %d입니다.", num, magicbox(num));
	return 0;
}