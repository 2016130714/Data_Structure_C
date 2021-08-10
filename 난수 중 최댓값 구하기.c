/*������ ����:
���: #include<time.h>
seed �ʱ�ȭ: srand(time(NULL))
���� ����: rand()
rand �Լ��� �����Ǵ� ������ 0 �̻� RAND_MAX���ϴ�.
RAND_MAX�� ��ǻ�� ȯ�濡 ���� �ٸ���, �⺻������ �ּ� 32767 �̻��̴�.
������ �Ը� �����ϱ� ���� rand() % 90�� ���� ����� ����.
(ex. ������ 90���� ���� ������)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MaxOfN(int* array, int index) {
	int max = *array;

	for (int i = 1; i < index; i++) {
		if (array[i] > max)
			max = array[i];
	}

	return max;
}


int main(void) {
	int* array, index;

	printf("��� ��: ");
	scanf("%d", &index);

	array = (int*)calloc(index, sizeof(int));

	srand(time(NULL));
	printf("\n�������� %d���� Ű ���� �����մϴ�.\n", index);

	for (int i = 0; i < index; i++) {
		int temp = 100 + rand() % 90;
		printf("%d\n", temp);
		//������ Ű�� �����ϴ� ���̵��

		*(array + i) = temp;

	}

	printf("\n�ִ��� %d�Դϴ�", MaxOfN(array, index));

	free(array);
}

//��� �� n�� �Է��ϸ�, n���� Ű�� ���� ����. �� �� �ִ��� ���Ѵ�.