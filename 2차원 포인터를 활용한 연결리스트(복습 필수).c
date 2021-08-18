/*����ü�� ������ ������ ������ �� �ִ�.
typedef struct {
char name int age....
} person;

person *p;
(*p).age = 23;       //�̶� �̿� ���� �� �����Ϳ� () �Ұ�ȣ�� �ٿ��� ��.
�׷��� �̰��� �����Ͽ� p->age = 23;���ε� ǥ�� ����. (*p).age = 23;�� ������ ���.*/

/*����ü�� ũ��� �����Ϸ��� ��� ����ü ���� ����(1, 2, 4, 8����Ʈ ����)�� ��������
���� �޶��� �� �ִ�. ���� �������� ���� ȥ���� �޸� ���� ������ ����
����ü�� ��Ҵ� ���� ũ��, ������ ũ���� �ڷ������� ����ִ� �� ����.
���� �ڷ����� �� �ʿ�, ū �ڷ����� �� �ʿ� ���� ��ġ�ϴ� �� ����.
struct Test {
char a; char b; short c; double d; } */

/*���Ḯ��Ʈ: ������ ��� ���� �Ҵ�����, ����ڿ��� ���� �޸𸮸� ���� ����� ������ �ʼ�����.
���Ḯ��Ʈ�� Ȱ���ϸ�, ���α׷��� �޸� ��뿡 �°� �ڵ����� ���� �Ҵ��ϰ� ����.
���̵��: node == target ���ڿ� �����͸� �ϳ��� ���� ����ü
head pointer(node1�� �ּ�) -> node1(node2�� �ּ�) -> node2.......->NULL
NULL�� ���� ��尡 ������ ��Ÿ����.*/

#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int number;
	int* p_next;
} NODE;


// NODE **pp_tail = &p_tail;   *pp_tail == p_tail  (2���� �����Ϳ� 1���� �������� �ּҸ� �޾ұ� ������)
// *�� �ϳ��� ���� �����ؾ� �Ѵ�.
//p_tail�� �������� node�� �߰��ϴ� ������, node�� ������ �߰����� �� p_tail�� �ᱹ �� �� node�� �ּҰ� ����� ���̱� ����
//p_head�� �������� node�� �߰��ϸ�, p_head�� ����� �ּҰ� �� ������ �и� ���̱� ������ �������� �ʴ�.
void AddNODE(NODE **pp_head, NODE **pp_tail, int data) {
	

	if (NULL != *pp_head) {

		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE)); //���� ����� ���� Ȯ��
		*pp_tail = (*pp_tail)->p_next; //���� ���� �ּ� �ű�.
	} 
	
	
	else { 	
		//ó������ p_head = NULL�̹Ƿ� ���⸦ ���� �����Ͽ�, ù ��带 p_head�� �����.
		//p_head�� ����, p_head�� �ּҸ� p_tail�� �޾� �ڷ� �� ĭ�� �����δ�.

		*pp_head = (NODE*)malloc(sizeof(NODE));
		*pp_tail = *pp_head;
	}

	//���� ��Ȳ: p_tail�� ���� ����� �ּ�(p_next) �����. 
	//�� *pp_tail�� ����ϸ�, p_next�� ���� �ٲ� �� ����
	(*pp_tail)->number = data;
	(*pp_tail)->p_next = NULL; 

}

int main(void) {

	NODE* p_head = NULL, * p_tail = NULL, * p;
	//ó������ ���, ���� �����͸� NULL�� �����ϰ�, AddNODE �Լ� ������ ��带 �߰��Ѵ�.
	int temp, sum;

	while (1) {
		printf("���ڸ� �Է��ϼ���(9999�� ������ ����): ");
		scanf("%d", &temp);

		if (9999 == temp) break;

		AddNODE(&p_head, &p_tail, temp);
		//���⼭ pp_head = &p_head; pp_tail = &p_tail; �� 2���� �����Ϳ� 1���� �������� �ּҸ� ����.
		//�� *pp_head = p_head; *pp_tail = p_tail; 
		//AddNODE �Լ� ������ *�� �ϳ��� ���ּ� �����ؾ� �Ѵ�!
	}


	p = p_head;       //�� ó���� �ּҸ� ����

	while (NULL != p) { //���� �ּҰ� �����ϸ�,
		if (p != p_head) printf(" + "); //ó���� p == p_head�̹Ƿ� ������� �ʰ�, 2��°���� ����ȴ�.

		printf("%d", p->number);
		sum += p->number;
		p = p->p_next;
	}

	printf(" = %d", sum);


	//�޸� �Ҵ� ����
	while (NULL != p_head) {
		p = p_head; //���� ������ �ּҴ� 0�ε�, ������ ���� p_head ����.
		p_head = p_head->p_next;
		free(p); //p_head���� ����, p_next����....
	}

	p_tail = p_head; //������ ���� p_tail���� ������ �����ؾ� �Ѵ�.

	return 0;
}