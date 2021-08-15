/*���ʹ�: ���� ������ �˻� ����� ���̴� ���
���̵��: �̸� key ���� �迭�� ���� ���� �߰� �س��´�.
��, ������ �� + 1�� �迭�� �����Ѵ�.
Ű ���� �� ���̸� -1 ���. �� ���� �ƴϸ� �ش� �ε����� ����Ѵ�.*/

#include <stdio.h>
#include <stdlib.h>

//���ʹ� ���� �˻� �Լ�
int search(int key, int array[], int index) {

	int i = 0;

	array[index] = key;   //���� �߰�(�迭�� ���� key ���� �̸� �߰�)

	while (1) {
		
		if (array[i] == key)
			break;
		
		i++;
	}

	return i == index ? -1 : i;
	/*return ���� ���� �����ڸ� Ȱ���� ����. (���ǽ�) ? x : y;
	���ǽ��� ���̸� x�� ���, �����̸� y�� ���.

	��, �˻� ����� �� ���̸� �˻� ������ -1�� ��ȯ. �׷��� ������ �˻� ����� �ε����� ��ȯ.*/
	
}


int main(void) {
	int n, *data, key;

	printf("���� �˻�(���ʹ�, sentinal method)\n");
	printf("������ ��: ");
	scanf("%d", &n);

	data = (int*)calloc(n + 1, sizeof(int));
	//���� �Ҵ� ��, index+1 ũ���� �迭 ����

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", data + i);
	}

	printf("�˻� ��:");
	scanf("%d", &key);
	
	int result = search(key, data, n);

	if (result == -1)
		printf("�˻��� �����߽��ϴ�.");
	
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.", key, search(key, data, n));

	free(data);
	return 0;
}