/*�� ����: ���� ���� ���� �˰��� �� �ϳ���.
���̵��: pivot����(ó���� ���). pivot�� �߽����� ������ pl, �������� pr�� ����.
pl�� pr�� ���� ���ذ���, pivot ������ ���� ��������, �̻��� ���� ���������� �̵�.

partition�Լ�: pivot���� ���� ���� pl��, ū ���� pr�� ������ �Լ�. pl++, pr--�� �ذ��� ��Ұ��� ��.
pl < pivot < pr �̷� ���� ���, ������ pivot < pl < pr  / pl < pr < pivot -> �̷��� ����.
pivot < pl < pr�̸�, pr--�� �ؾ��ϰ�, pl < pr < pivot�̸� pl++�� �ؾ��Ѵ�. (�˸��� ��ġ�� �ִ� �ε����� ++ or --)
�׸��� pl < pivot < pr�� ���� ��쿡�� swap�ؾ���. ��������� pl�� pr�� ������ �޶����� ������ ����.*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type temp = x; x = y; y = temp;} while(0)


void partition(int array[], int n) {
	
	int i;
	int pivot = array[n / 2];
	int pl = 0;
	int pr = n - 1;

	while(pl <= pr) {
		while (array[pl] < pivot) pl++;
		
		while (array[pr] > pivot) pr--;  //��ġ �̵��� �ʿ� ���� ���, �ܼ��� pl++, pr--�Ѵ�.
		//�̷��� ��찡 �������� ���� �� �ֱ⿡, if���� �ƴ� while���� ��� ��.

		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
		
	} 

	putchar('\n');

	printf("�ǹ�: %d\n", pivot);

	printf("�ǹ� ������ �׷�\n");


	//while������ swap�� ��ģ ��, pl++, pr--�� �� �� �� �����ϱ� ������, ���󺸴� +-1�� ��ġ�� �ݺ����� ����
	//�� pl - 1�� pr + 1
	for (i = 0; i <= pl - 1; i++)
		printf("%2d", array[i]);

	putchar('\n');
	
	printf("�ǹ� �̻��� �׷�\n");

	for (i = pr + 1; i < n; i++) {
		printf("%2d", array[i]);
	}
}


int main(void) {

	int* array, n;

	printf("������ ��: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	partition(array, n);


	return 0;
}