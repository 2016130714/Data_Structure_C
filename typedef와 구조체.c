/*typedef: �� �̸��� �ڷ���, �迭, �����Ϳ� ���� ������ ª�� �������ϴ� ����
typedef unsigned short int US;
US data         // unsigned short int data�� ������ �Ͱ� ����.

typedef int MY_DATA[5];
MY_DATA *p           // int (*p)[5]�� ������ �Ͱ� ����.
����: ���� �Լ����� ���� �� ����� ������ �ڷ����� �ٲ� �� ȿ�����̴�. 
typedef�� �̸� ����ٸ�, �ϳ��ϳ� �ٲ��� �ʰ� typedef �κи� �ٲٸ� �Ǳ� ����.*/

/*�迭: ���� ������ �����͸� �׷�ȭ. ex)���� ����, Ű ����, ������ ����...
����ü: ���� �ٸ� ������ �����͸� �׷�ȭ. ex) ���� ���� ����+Ű+������
����: �ٸ� �ڷ����� �޸� ������ ����� ������ struct ���ϸ� �ٿ��� ��.
�ذ��: typedef struct {...} person;�� ���� ���� person�� ���� ��.(����ȭ ����)*/


#include <stdio.h>

typedef struct {
	char name[10];    //���ڿ� �ڿ� ������ �ʿ�, �ѱ����� �ڸ��� ���� �ϳ��� �Է�.
	//3���� �̸� ���� 10ĭ�� �ʿ��� ��.
	unsigned short int age;     //������ ������ ����Ͽ� �޸� ����        
	float height;
	float weight;
} Person;

int main(void) {
	Person data;       //����ü ���� �� �Լ� �� ���������� ���� ���� �ʿ�

	printf("������� ������ �Է��ϼ���\n�̸�: ");
	scanf("%s", data.name);
	
	printf("����: ");
	scanf("%hu", &data.age);
	//unsigned short int�� ����: %hu       unsigned int�� ����: %u

	printf("Ű: ");
	scanf("%f", &data.height);

	printf("������: ");
	scanf("%f", &data.weight);

	printf("�Է��� ������ ������ �����ϴ�.\n");
	printf("%s, %d, %.1fcm, %.1fkg", data.name, data.age, data.height, data.weight);
	
}

