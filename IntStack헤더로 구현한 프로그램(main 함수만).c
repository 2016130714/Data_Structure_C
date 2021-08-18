/* switch ���ǹ��� Ȱ���Ͽ� ���� ����
������ ��: initialize, push, pop, peek�� ���� �׻� if���� ���� ���� ���ɼ��� ���Խ��Ѿ� �Ѵ�.
(��� �ڵ忡�� int������ �����Ͽ� return -1�� return 0�� ��츦 ���� �Լ���)
�� if(Push(&s, data) == -1) printf("�����߽��ϴ�.)         //�̷� ������   */

#include <stdio.h>
#include "IntStack.h"

int main(void) {

	INTSTACK s;

	//���� ����
	if (Initialize(&s, 64) == -1) {
		printf("���� ���� ����");
		return 1;
	
	}

	while (1) {

		int menu, data;

		printf("���� ������ ��: %d/%d\n", Size(&s), Capacity(&s));

		printf("(1) Ǫ��  (2) ��  (3) ��ũ  (4) ���  (0) ����: ");
		scanf("%d", &menu);

		if (menu == 0) break;

		switch (menu) {

		case 1:  //push

			printf("������: ");
			scanf("%d", &data);

			if (Push(&s, data) == -1)
				printf("push�� �����߽��ϴ�.");

			break;

		
		case 2:    //pop
			
			if (Pop(&s, &data) == -1)
				printf("pop�� �����߽��ϴ�.");

			else
				printf("pop �����ʹ� %d�Դϴ�.\n", data);


			break;


		case 3:   //peek

			if (Peek(&s, &data) == -1)
				printf("peek�� �����߽��ϴ�.");

			else
				printf("peek�����ʹ� %d�Դϴ�.\n", data);

			break;


		case 4:    //print

			Print(&s);
			break;

		}           //switch�� ����
	}        //while�� ����

	Terminate(&s);

	return 0;
}