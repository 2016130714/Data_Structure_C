/*c���� �� ���ڿ��� ���迬���ڷ� ���� �� ����. 
��, "abc" == "abc"�� ���� �񱳰� �Ұ���. ���ڿ��� ����� �ּҰ� �ٸ��� ����.

�ذ��: strcmp(string compare)�Լ� ���.
���: #include<string.h>
����: int strcmp(const char *str1, const char *str2)
��ȯ��: ���� ������ ������.
���� ������ str1 < str2�� -1, str1 == str2�� 0, str1 > str2�� 1 ��ȯ.
��, ��ȯ�ϴ� ������ bsearch�� int(*compar)�� �䱸�ϴ� ���¿� �����ϴ�.
strcmp, bsearch�� Ȱ���Ͽ� ���ڿ��� ����Ž���� �����ϴ�.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int str_cmpr(const Person* a, const Person* b) {
	return strcmp(a->name, b->name);
	//����ü �迭 (*a).name ��ſ� a->name�� Ȱ������.
}


int main(void) {

	Person list[] = {
		{"�迵��", 179, 79},
		{"������", 172, 63},
		{"�̼���", 176, 52},
		{"������", 165, 51},
		{"������", 181, 73},
		{"ȫ����", 172, 84}
	};
	
	Person temp; // target data�� Person list�� ������, �Է� ������ ���� �ް� Ȱ���ϱ� ����
	//������ ����ü Person temp�� ����.

	int index = sizeof(list) / sizeof(list[0]); // ����ü �ε��� �� ���!

	Person* result; // bsearch�� ����� �����ϱ� ���� ����. bsearch�� ����� �ش� �����͸� ��ȯ�Ѵ�.
	//����ü�� ���� Ž���ϹǷ�, ����ü�� �����͸� ��ȯ�� ��. �׷��� Person�� ������ ����.

	int retry; //��˻� ���θ� �Ǻ��ϱ� ���� ����


	
	//bsearch ����/���з� �з�. ���� 126��ó�� �������� while�� �Ŀ� �����ϴ� do while���� �� ���ۿ� ����.
	//����, ���п� ���� ���� "�ٽ� �˻��ұ��?" ���.
	do {

		printf("�̸����� �˻��մϴ�.\n�̸�: ");

		scanf("%s", &temp.name);
		result = bsearch(&temp.name, list, index, sizeof(Person), str_cmpr);

		if (result != NULL) {
			printf("�˻� ����!! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.\n");
			printf("list[%d]: %s %4dcm %3dkg\n", result - list, result->name, result->height, result->weight);
		}
		
		else
			printf("�˻��� �����߽��ϴ�");

		printf("�ٽ� �˻��ұ��? (1) �� / (0) �ƴϿ� : ");
		scanf("%d", &retry);       //�̷��� �ٽ� �˻� ���θ� 0�� 1�� �Է� �ް�, do while���� ���� ��˻� ��� ����.
	} while (retry == 1);
}