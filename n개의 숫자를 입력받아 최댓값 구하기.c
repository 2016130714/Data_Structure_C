/*���� �޸� �Ҵ�: int *p = calloc(����, sizeof(�ڷ���))
int *p = (int *)malloc(sizeof(�ڷ���)*����)
���: #include<stdlib.h>*/

#include <stdio.h>
#include <stdlib.h>

//n���� ���� �� �ִ��� ���ϴ� �˰���
int MaxOfN(int *num, int n) {
	int max = *num;

	for (int i = 1; i < n; i++) {
		if (num[i] > max) max = num[i];
	}

	return max;
}



int main(void) {
	int* height, number;

	printf("��� ��: ");
	scanf("%d", &number);

	height = (int*)calloc(number, sizeof(int));

	printf("\n%d ���� Ű�� �Է��ϼ���.\n", number);

	for (int i = 0; i < number; i++)
		scanf("%d", &height[i]);

	printf("\n�ִ��� %d�Դϴ�.", MaxOfN(height, number));

	free(height);


}