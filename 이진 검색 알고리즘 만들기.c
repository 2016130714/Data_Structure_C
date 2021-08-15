/*���� �˻�: ���� �˻��� ���� ������. (log(n)�� ���⵵)
�ٸ� �迭�� sorted �Ǿ� �־�� ��� �����ϴ�. �������� or ������������*/

#include <stdio.h>
#include <stdlib.h>


int bin_search(int key, int* array, int n) {

	int start = 0;
	int end = n - 1;
	int middle;
	//int middle = (start / end) / 2
	// ���⼭ middle�� �����ϸ�, Ž���� ����� ���� middle�� ���� �ٲ��� �ʴ´�.

	while (start <= end) {
		middle = (start + end) / 2;

		if (array[middle] == key)
			return middle;

		else if (array[middle] < key)
			start = middle + 1;

		else if (array[middle] > key)
			end = middle - 1;
	}
}
/*�� start = middle; end = middle;�� �ƴ϶�, middle + 1; middle -1�� �ұ�?
middle�� �ش��ϴ� ���� ù ��° if ������ �ɸ��� ������, ���� �ٽ� Ž���� �ʿ� ����.
middle + 1; middle - 1�� �ϴ� ���� �����̶� ���⵵�� �Ƴ��� ���.*/

int main(void) {
	int n, *array, key;

	printf("���� �˻�\n");
	printf("������ ��: ");

	scanf("%d", &n);
	array = (int*)calloc(n, sizeof(int));

	printf("������������ �迭�� �Է��ϼ���.\n");

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("�˻� ��: ");
	scanf("%d", &key);

	printf("%d��(��) x[%d]�� �ֽ��ϴ�.", key, bin_search(key, array, n));

	free(array);
	return 0;
}