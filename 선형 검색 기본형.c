/*�˻��� ����: �������� "�Ϻ�"�� �ָ��Ͽ�, �װ��� key ���� ��ġ�ϴ���, ������ ���ϴ���, ������� �Ǵ�.
�迭 �˻�, ���� ����Ʈ �˻�, ���� �˻� Ʈ��, ���ڿ� �˻� ���� �ִ�.
���⼭�� �迭���� �˻��ϱ⸦ �ٷ��.

���� �˻�(linear search): ���� ����� �迭���� key ���� ������ ��ġ ���θ� ����.
Ű ���� ���� ���Ҹ� �߰��ϸ� �˻� ����. �߰����� ���ϰ� �迭�� ���� �����ϸ� �˻� ����.
�� �׻� �˻� ������ �˻� ���� �� �� �����ؾ� ��.*/


#include <stdio.h>
#include <stdlib.h>


//�˻� ���� �� �ε��� ��ȯ. ���� �� -1�� ��ȯ�Ѵ�.
int search(int key, int array[], int index) {

	for (int i = 0; i < index; i++) {

		if (array[i] == key)
			return i;
	}

	return -1;
}



int main(void) {
	int n, key;
	int* data;

	printf("���� �˻�\n");
	printf("������ ����: ");
	scanf("%d", &n);

	data = (int*)calloc(n, sizeof(int));
	//�迭�� ũ�⸦ ���س��� �� �ƴ϶�, �ε����� �Է� �����Ƿ�, �Է� �� ���� �Ҵ� �ʼ�!


	for (int i = 0; i < n; i++) {

		printf("\nx[%d]: ", i);
		scanf("%d", data + i);
	}

	printf("\nã������ Ű ��: ");
	scanf("%d", &key);

	printf("%d��(��) x[%d]�� �ֽ��ϴ�.", key, search(key, data, n));

	free(data);
	return 0;
}