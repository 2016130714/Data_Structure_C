#include <stdio.h>
#define MAX_COUNT 5

int main(void) {
	int num[MAX_COUNT], count = 0, sum = 0;

	while (count < MAX_COUNT) {
		//MAX_COUNT�� ���� ������ �����ϱ� ���� �ݺ���
		printf("���ڸ� �Է�(9999�� �Է��ϸ� ����): ");
		scanf("%d", &num[count]);
		if (num[count] == 9999) break;
		count++;
	
	}

	for (int i = 0; i < count; i++) 
		//i <= count�� ���� �ʰ� ����
		sum += num[i];


	printf("result: %d", sum);

}



