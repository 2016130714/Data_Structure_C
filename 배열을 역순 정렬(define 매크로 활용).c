/*���̵��: ���Ұ� n���� �迭�� array����
array[0]�� array[n-1]�� ��ȯ�Ѵ�.
�������� array[1]�� array[n-2]�� ��ȯ�Ѵ�.
�� ������ n/2�� �Ѵ�. for loopȰ��.
���Ұ� Ȧ�� ���̸� ���� ����� ���Ҹ� ��ȯ�� �ʿ�� ����.

swap�� �⺻ ����: x�� y�� swamp�� ��, x y �� �ϳ��� ���� temp�� �����Ѵ�.

��ũ�� Ȱ��: #define�� ��ũ�θ� �����س���, �̸� Ȱ���Ѵ�. ��ũ�ο� Ȱ��Ǵ� do ���� ������ �� �������.

do���� ����: do{...;...;..;} while(���� ����)
���⼭ while(0)�� ���� �� �� ���� �����ϰ� Ȱ�� �����ϴ�!*/

#include <stdio.h>
#include<stdlib.h>

//��ũ��: type���� x�� y�� swap. ������ ��Ȯ�� �������.
#define swap(x, y, type) do {type temp = x; x = y; y = temp;} while(0)
//


void SwapArray(int* array, int index) {

	for (int i = 0; i < index / 2; i++) 
		swap(array[i], array[index - 1 - i], int);
	}

int main(void) {
	int* array, index, i;

	printf("�迭 ������ ����: ");
	scanf("%d", &index);

	array = (int*)calloc(index, sizeof(int));

	printf("\n%d���� ������ �Է��ϼ���.\n", index);

	for (i = 0; i < index; i++) {
		printf("����[%d]: ", i);
		scanf("%d", array + i);

	}
	printf("\n���� ������ ������ �����ϴ�.\n");
	SwapArray(array, index);

	for (i = 0; i < index; i++)
		printf("����[%d]: %d\n", i, array[i]);

	free(array);
}