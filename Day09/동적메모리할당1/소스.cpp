// �����޸��Ҵ�
#include <stdio.h>
#include <stdlib.h>

int main() {
	int student, i, input;
	int sum = 0; int* score;

	printf("�л��� ����? : ");
	scanf_s("%d", &student);

	score = (int*)malloc(student * sizeof(int));

	for (i = 0; i < student; i++) {
		printf("�л� %d�� ���� : ", i+1);
		scanf_s("%d", &input);
		score[i] = input;
		sum += input;
	}

	free(score);
	printf("��ü �л��� ��� ���� : %d\n", sum);

	return 0;
}