//*(a+i) == a[i]; &a[0] == &*a == a
//������ ������ int���̱⿡, ������ ����+1�� �ڵ����� +4byte ��޵�.
#include<stdio.h>

int main(void) {
	int data1[] = { 1, 2, 3 };
	char data2[] = { 'a', 'b', 'c' };
	long long data3[] = { 1, 2, 3 };

	int * p = data1;
	char * p2 = data2;
	long long * p3 = data3;
	printf("%d %d\n", p, p+1); //���: 1899900 1899904
	printf("%d %d\n", p2, p2 + 1); //��� x x+1
	printf("%d %d\n", p3, p3 + 1); //��� y y+8
	//�ּ��� ��ü�� ���� ������ ������ �ٲ�.
	//������ ������ ����� �ڷ����� ���� +1�� ũ�Ⱑ �˾Ƽ� ����(1, 4, 8����Ʈ...)
}