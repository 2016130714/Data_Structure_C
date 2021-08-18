#include <stdio.h>
#include "IntQueue.h"

int main(void) {

	INTQUEUE que;

	if (Initialize(&que, 64) == -1) {
		printf("ť ���� ����");
	}

	while (1) {

		int act, x;

		printf("���� ������ ��: %d/%d\n", Size(&que), Capacity(&que));
		printf("(1) ��ť (2) ��ť (3) ��ũ (4) ��� (0) ����: ");
		scanf("%d", &act);


		if (act == 0) break;


		switch (act) {

		case 1:
			printf("������: ");
			scanf("%d", &x);

			if (Enque(&que, x) == -1)
				printf("��ť�� �����߽��ϴ�.");

			break;


		case 2:
			if (Deque(&que, &x) == -1)
				printf("��ť�� �����߽��ϴ�.");

			else
				printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);

			break;


		case 3:
			if (Peek(&que, &x) == -1)
				printf("��ũ�� �����߽��ϴ�.");

			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);

			break;


		case 4:
			Print(&que);
			break;
		}
	}

	Terminate(&que);
	return 0;
}