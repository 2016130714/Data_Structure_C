/*stdlib �����Լ� qsort �Լ�
����: void qsort(array, num, sizeof(), compare)*/


#include <stdio.h>
#include <stdlib.h>

int int_cmp(const* a, const* b) {

	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main(void) {

	int* array, n, i;

	printf("qsort�� ���� ����\n");
	printf("������ ��: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	qsort(array, n, sizeof(int), int_cmp);

	printf("������������ �����߽��ϴ�.\n");

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, array[i]);

	return 0;
}