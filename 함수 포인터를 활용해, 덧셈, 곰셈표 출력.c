/*������ printf�� ���� ������ ������!
%d, %s, %c �� Ű���尡 �ʿ����� ����, �ܼ� ���ڿ� ��¿����� putchar, puts�Լ��� Ȱ������.
putchar(''): ���� ���� ���. \n�� ���� �� ������ ���� ���. �׿� �°� ���� ����ǥ Ȱ��.
puts(""): ���ڿ� ���. ���ڿ��̱� ������ ū ����ǥ Ȱ��.
printf(""): Ű���� Ȱ�� ����. ���� ���ڵ� ��� ����. but �׻� "" ū ����ǥ�� ����� ��!*/


#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

void Chart(int calc(int, int)) {
	//��Ģ������ �Լ� ������ ���� �� int (*calc)�� ���� �ؾ� ������, ���ǻ� int calc(int, int) �̷��� �ᵵ ��.


	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++)
			printf("%3d", calc(i, j));
		putchar('\n');
	}
	
}

int main(void) {

	puts("����ǥ\n");
	Chart(sum);
	puts("����ǥ\n");
	Chart(mul);
	return 0;
}