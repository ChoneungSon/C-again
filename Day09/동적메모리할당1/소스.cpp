// 동적메모리할당
#include <stdio.h>
#include <stdlib.h>

int main() {
	int student, i, input;
	int sum = 0; int* score;

	printf("학생의 수는? : ");
	scanf_s("%d", &student);

	score = (int*)malloc(student * sizeof(int));

	for (i = 0; i < student; i++) {
		printf("학생 %d의 점수 : ", i+1);
		scanf_s("%d", &input);
		score[i] = input;
		sum += input;
	}

	free(score);
	printf("전체 학생의 평균 점수 : %d\n", sum);

	return 0;
}