/*�ִ� ���̵��: int max = a
if���� ���� �� ū ���� max�� �����Ѵ�. return max;�Ѵ�. 
�߾Ӱ� ���̵��: �� ������ ��� ����, ����� ���� 13�̴�.
i) �� ���� �� �ٸ� ���: 6  ii) �� ���� ���� ���: 6   iii) �� ���� ���� ���: 1*/
#include <stdio.h>

int Max3(int a, int b, int c) {
	int max = a;
	
	if (b > a) max = b;
	if (c > b) max = c;

	return max;
}


int Med3(int a, int b, int c) {
	int med = a;

	if ((a <= b && b <= c) || (c <= b && b <= a)) med = b;
	if ((a <= c && c < b) || (b <= c && c <= a)) med = c;
	//a <= b <= c�� ���·� ���� �ȵ�. a <= b && b <= c�� �����!!

	return med;
}


//�߾Ӱ� ���ϱ� �ٸ� �˰���
int Med_else(int a, int b, int c) {
	int med = a;

	if (b >= a) if (b <= c) med = b;
	if (a <= c) if (c <= b) med = c;

	return med;
}


int main(void) {
	int a, b, c, max, med, med2;
	printf("���� 3�� �Է�: ");
	scanf("%d %d %d", &a, &b, &c);
	max = Max3(a, b, c);
	med = Med3(a, b, c);
	med2 = Med_else(a, b, c);
	printf("�ִ�: %d\n", max);
	printf("�߾Ӱ�: %d\n", med);
	printf("�߾Ӱ�: %d", med2);

	return 0;
}