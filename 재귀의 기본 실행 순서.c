/*��� ���� ����: �Ӹ� ������ �����ϱ� �����Ͽ�, Ʈ���� �׷����� �� ����.
recur_2(5)�� ��� - r(4)	-r(3)	-r(2)	 -r(1)	-r(0)
					p5		 p4		 p3		  p2	 p1
					r(3)	 r(2)	 r(1)	  r(0)	 r(-1)
					r(2)	 r(1)	 r(0)	  r(-1)  r(-2)

�뷫 ���� ���� Ʈ���� ����ȴ�.
�������ǿ� �ٴٸ��� ������, �� ����(���� ������) ��͸� DFS �������� �켱 �����Ѵ�.
�� ���� ���� recur(1) - printf(1)���� ��µȴ�.
�� 123141215123112�� ������ ��µȴ�.

���ð� goto���� Ȱ���� ����Լ��� ��ü �����ϴ�.*/


#include <stdio.h>

void recur(int n) {

	if (n > 0) {

		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

void recur_2(int n) {

	if (n > 0) {

		recur_2(n - 1);
		printf("%d\n", n);
		recur_2(n - 2);
		recur_2(n - 3);
	}
}

void recur_3(int n) {
TOP:
	if (n > 0) {
		recur_3(n - 1);
		printf("%d\n", n);
		n = n - 2;
		goto TOP;
		n = n - 3;
		goto TOP;
	}
}

int main(void) {

	int n;
	printf("������ �Է��ϼ���.: ");
	scanf("%d", &n);


	recur_3(n);

	return 0;
}