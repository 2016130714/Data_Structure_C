#include <stdio.h>
//�迭�� �̸� = �迭�� �ּ�(������ ����)
// int a[10];���� a�� �迭�� �ּ�; *a == a[0]; *(a+i) = a[i]
void main() {
	int array[10];
	int i, result;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &array[i]);  //scanf�� �̷��� for ���� �ȿ��� Ȱ�� ����
	//&array[i] == &(array+i)
	result = calculate_sum(array);
	printf("%d", result);
	return 0;
}

int calculate_sum(int* array) { //�Ű������� int array []���� �� ���� �ִ�. 
	int sum = 0, i;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];
	return sum;
}