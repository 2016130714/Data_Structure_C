/*�Լ� ������: Ư�� �Լ��� ���� ��ɾ��� ��ġ�� ����Ű�� ������. ���� ���� �Լ��� ����Ű�� ������.
����: int (*p)(int, int)     ->         (��ȯ��)(������ ����)(�ڷ���, �ڷ���...)
p = &Sum       -> &�� ���� �ʰ� Sum�� �ᵵ ���� ���.

����� �Լ� �׷�ȭ: ��ȯ��, �μ��� ���� �Լ����� �Լ� ������ �迭�� �����Ͽ� �׷�ȭ ����.
int (*p[4])(int, int) = {&Sum, &Sub, &Mul, &Div};*/

#include <stdio.h>

int Sum(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	return a / b;
}





int main(void) {
	int a, b;

	int(*p[4])(int, int) = { Sum, Sub, Mul, Div };
	//���� ���� �Լ� ������ �迭�� Ȱ���� �� �ִ�.
	int op_table[] = { '+', '-', '*', '/' };

	for (int i = 0; i < 4; i++)
		printf("%d %c %d = %d\n", 8, op_table[i], 2, (*p[i])(8, 2));

	return 0;
}