// �����޸��Ҵ�2
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, input, sum = 0;
	int subjects, students;
	int** arr;

	printf("���� �� : ");
	scanf_s("%d", &subjects);

	printf("�л� �� : ");
	scanf_s("%d", &students);
	printf("\n");

	arr = (int**)malloc(students * sizeof(int*));
	for (i = 0; i < students; i++) {
		arr[i] = (int*)malloc(subjects * sizeof(int));
	}

	for (i = 0; i < students; i++) {
		printf("�л� %d�� ����\n", i+1); sum = 0;
		for (j = 0; j < subjects; j++) {
			printf("%d ���� ���� : ", j+1);
			scanf_s("%d", &input);
			arr[i][j] = input; sum += input;
		}
		printf("��� : %f\n", double(sum / subjects));
		printf("__________________\n");
	}
	free(arr);

	return 0;
}