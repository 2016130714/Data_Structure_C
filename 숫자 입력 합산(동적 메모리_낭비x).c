#include <stdio.h>
#include<malloc.h>

int main(void) {
	int limit = 0, count = 0, sum = 0;
	printf("�Է��Ϸ��� ������ ����: ");
	scanf("%d", &limit);
	int* num_list = (int*)malloc(sizeof(int) * limit);

	while (count < limit) {
		printf("���ڸ� �Է� (9999 �Է� �� ����): ");
		scanf("%d", &num_list[count]);
		if (num_list[count] == 9999) break;
		count++;
	}
	for (int i = 0; i < count; i++)
		sum += num_list[i];

	printf("result: %d", sum);
	free(num_list);   //�� �������� ����� �Ѵ�!

}