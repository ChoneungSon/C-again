// 동적메모리할당2
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, input, sum = 0;
	int subjects, students;
	int** arr;

	printf("과목 수 : ");
	scanf_s("%d", &subjects);

	printf("학생 수 : ");
	scanf_s("%d", &students);
	printf("\n");

	arr = (int**)malloc(students * sizeof(int*));
	for (i = 0; i < students; i++) {
		arr[i] = (int*)malloc(subjects * sizeof(int));
	}

	for (i = 0; i < students; i++) {
		printf("학생 %d의 점수\n", i+1); sum = 0;
		for (j = 0; j < subjects; j++) {
			printf("%d 과목 점수 : ", j+1);
			scanf_s("%d", &input);
			arr[i][j] = input; sum += input;
		}
		printf("평균 : %f\n", double(sum / subjects));
		printf("__________________\n");
	}
	free(arr);

	return 0;
}