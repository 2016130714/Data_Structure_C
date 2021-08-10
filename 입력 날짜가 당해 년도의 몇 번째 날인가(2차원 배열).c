/*���� ���ϴ� ���: 4�� ��� ��� 100�� ����� �����ϰ�, �ٽ� 400�� ����� ����*/

#include <stdio.h>

int MthDays[2][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } }; // �������� ����. ����� �ƴ� �� ������ 2���� �迭


//�������� �Ǵ��ϴ� �Լ�
int IsLeap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	/*0�� 1�� �Ǵ��� �ʿ��� �Լ��� ���� if���� ���� �ʾƵ� �̷��� ����ȭ ����.
	return ���ϰ� ���̸� 1�� ��ȯ�� ���̰�, �����̸� 0�� ��ȯ�� ���̱� ����.
	(���� �����ڸ� Ȱ���߱⿡ �������� �Ǵ��Ѵ�.)
	�� 4�� ����̰ų� 400�� ����� 1�� ��ȯ, ���ÿ� 100�� ����� �ƴϸ� 1�� ��ȯ -> MthDays[1][12] ��ȸ
	�ش���� �ʴ� �Ϲ� ������ ��� 0�� ��ȯ -> MthDays[0][12] ��ȸ*/
	
}



int DayOfYear(int year, int month, int date) {
	int sum = 0;
	
	//���� ���� ���� ��Ȯ�� �Ǵ�. (2������ MthDays�� ���ؾ� �Ѵ�. 1���� ������ �ʰ�)
	for (int i = 1; i < month; i++)
		sum += MthDays[IsLeap(year)][i - 1];

	sum += date;
	return sum;
}

int main(void) {
	int year, month, date;
	printf("��: ");
	scanf("%d", &year);
	printf("��: ");
	scanf("%d", &month);
	printf("��: ");
	scanf("%d", &date);

	printf("%\n%d���� %d��° ���Դϴ�.", year, DayOfYear(year, month, date));




	return 0;
}