/*�� ���� partition ���: pl, prĿ���� �� �� pivot ��ó�� ���� ���̴�.

�� ���� ���̵��: pr�� Ŀ���� 0���� ������, pl�� Ŀ���� n - 1���� ������ �����Ѵ�.
��, partition(array, 0, pr)�� partition(array, pl, n - 1)�� �ݺ��ϴ� �˰����� �����.
�� ��� ���ĵ� ���̴�.*/


#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)



void qsort(int array[], int left, int right) {

	int pl = left;
	int pr = right;
	int pivot = array[(pl + pr) / 2];

	//while�� ������ if(pl <= pr)�� �ʼ��� ����: ���� while(array[pl] < pivot)�� �����
	//pl, pr�� �� �ڰ� �ٲ���� ��, ��ü while�� �� ���� pl <= pr�� �ɸ��� �ʰ� swap�� ����� �� �ִ�.
	//�װ��� ���� ���� ���ο����� pl <= pr�� ������ �� �� �� �ɾ��� ��.
	while(pl <=pr) {
		while (array[pl] < pivot) pl++;

		while (array[pr] > pivot) pr--;

		
		if (pl <= pr) {    
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;

		}
	} 
	
	if (left < pr) qsort(array, left, pr);

	if (pl < right) qsort(array, pl, right);
}

int main(void) {

	int* array, n, i;

	printf("�� ����\n");
	printf("������ ��: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	qsort(array, 0, n - 1);

	printf("������������ �����߽��ϴ�.\n");

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, array[i]);

	return 0;
}