/*20�� 4��, 30�� 2�� 40�� 3���� ����� 2���� �迭�� ����
�ִ� �ο��� �ִ� 20���� 4�� ���� �ּ� [3][4] ũ���� �迭 �ʿ�
���� ����Ű�Ⱑ 1�п� 200�� �Ѵ� �� �Ұ����ϱ⿡ 0-255�� unsigned char�� ���
�� �ο��� 9���ε� �迭�� [3][4]�̹Ƿ�, 3����Ʈ ���� �߻�*/

#include <stdio.h>
//limit_table�� �������� ������ [3][4] �迭 12ĭ ��ü�� �� ���ۿ� ����.


int main(void) {
	unsigned char limit_table[3] = { 4, 2, 3 };
	unsigned char everyone[3][4];
	int age, person, temp;
	int sum = 0;

	for (age = 0; age < 3; age++) {
		printf("%d0���� ���� ����Ű�� Ƚ��: \n", age + 2);

		for (person = 0; person < limit_table[age]; person++) {
			scanf("%d", &temp);
			//scanf�� �ڷ����� �����ϱ� ������, ������ �ٷ� unsigned char�� ���� �� ����.(print�� �޸�)
			//���� int���� temp�� ���� scanf�� �� ��, ���� ����.
			everyone[age][person] = temp;
		}
		//scanf�ڿ� ������ print���� ���� �ʿ� ����. ������ �ߺ� ��µ�.
		}
	printf("���ɺ� ���\n");

	for (age = 0; age < 3; age++) {
		for (person = 0; person < limit_table[age]; person++) 
			sum += everyone[age][person];

		printf("%d0��: %5.2f\n", age + 2, (double)sum / limit_table[age]);
		//�Ҽ� �� ° �ڸ����� ����ϱ� ���� %5.2f(5ĭ ���, �Ҽ��� �Ʒ� 2�ڸ�) ���.
		//�̿� �����ϰ� sum�� �ڷ����� double�� ����.

		sum = 0; // sum�� �ʱ�ȭ���� ������ �����Ǳ� ������ ����!
	}

	
}