/*���̵��: �迭 ������ minimum�� ã�´�. minimum�� array[0]�� swap�Ѵ�.
array[1]...array[n - 1]���� min, array[2]....array[n -1]...���� min ã��... ������ �ݺ��Ѵ�.*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) {type temp = x; x = y; y = temp;} while(0)


/*���� int min = array[i]�� �����ϴ� �ڵ带 ��µ�, ����� ������� �ʾҴ�.
������ ����غ���!*/
void selection(int array[], int n) {
	

	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;

		for (j = n - 1; j > i; j--)
			if (array[j] < array[min])
				min = j;
		swap(int, array[i], array[min]);
	}
}

void insertion(int array[], int n) {

	int i, j;
	for (i = 1; i < n; i++) {
		int temp = array[i];
		for (j = i - 1; j > 0 && array[j] > temp; j--) 
			array[j + 1] = array[j];     //���⼭ temp�� ���� �����ؾ� �ϹǷ�, temp�� �ƴ� j + 1�� ǥ���ؾ� ��.
		array[j] = temp;		
	}

}

int main(void) {

	int n, * array;

	printf("�ܼ� ���� ����\n");
	printf("������ �� �Է�: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("������������ �����߽��ϴ�.\n");
	insertion(array, n);

	for (int i = 0; i < n; i++) {
		printf("x[%d]: %d\n", i, array[i]);
	}

	return 0;
}