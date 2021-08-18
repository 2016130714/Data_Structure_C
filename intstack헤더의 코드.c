#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//������ �ױ� ����, max��ŭ�� �޸� ���� Ȯ��, �غ� �۾�.
//ptr = 0 ����. max�� �Է¹��� �� ����.
//����: max��ŭ�� �޸� ���� Ȯ�� return 0   //����: max�� 0 ����. return -1
int Initialize(INTSTACK *s, int max) {
	
	s->ptr = 0;

	//�Է¹��� max * sizeof(int)��ŭ�� �޸� �Ҵ� �õ�(max: ���� �ִ� �뷮)
	//max��ŭ�� �޸� �Ҵ翡 �����ϸ� max�� 0�� �����ϰ� return -1�Ѵ�.
	if ((s->stk = malloc(max * sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}

	//�޸� �Ҵ��� �����ϸ�, ������ ���� max���� stk�� ����� �غ��۾�
	//stk[0], stk[1],.....stk[max-1]
	s->max = max;
	return 0;
}


/*int ptr�� ����: 1. ptr�̶�� �̸��� �޸� ������ ������ �ƴ϶� �Ϲ� ������.
2. *stk, �� ���ÿ� int x�� �����͸� ���� ������ ptr���� 1�� ������Ų��. (ptr++)
3. initialize �� ptr = 0���� �����ϸ�, push�Լ��� ���� ptr == max�̸� ������ ���� �� �� �̻� push�� �� ����.
4. (s->ptr >= s-> max) �� ptr ���� max �̻��̸�, ������ ���� á�ٴ� �ǹ̷� return -1�Ѵ�. 
�׷��� ������, (s->stk[s->ptr++] = x). �� stk[0]���� �����͸� �����Ѵ�.*/
int Push(INTSTACK* s, int x) {
	
	if (s->ptr >= s->max)
		return -1;
	
	s->stk[s->ptr++] = x;
	return 0;
}


//push�� �ݴ��� ����. LIFO�� ���信 ���� str[ptr]���� �����͸� pop��. �����͸� int *x�� ����.
//å�� �ڵ尡 �߸��� �� ���� �ణ ��������.
int Pop(INTSTACK* s, int* x) {
	
	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr - 1];
	s->ptr = s->ptr--;

	return 0;

}

//���� ������� �����͸� peek(������) �Լ�. 
//�����, ������� �����ʹ� stk[ptr-1]�� ����Ǿ� �ִ�. push�� �� stk[ptr++]�ϱ� ����.
//��, ptr = 0�� ���¿��� stk[0] = x�� �����ϰ�, ptr == 1�� ����� ���� ����.
//�ᱹ �����Ͱ� �� �ִ� �� stk[ptr-1]������, stk[ptr]�� ���� �����͸� ����(����� ����ִ�) ��ġ��.
int Peek(const INTSTACK* s, int* x) {

	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr - 1];
	return 0;
	
}

//������ ���� �Լ�. ������ ��� push�� pop�� ptr�� ������� �̷����� ������, ���� *stk�� �ǵ��� �ʰ�,
// ptr = 0�� �������൵ ������ ��� �� �ִ�.
void Clear(INTSTACK* s) {

	s->ptr = 0;
}

//������ �뷮(max�� ��)�� ��ȯ
int Capacity(const INTSTACK* s) {

	return s->max;
}


//���� ���ÿ� ���� �������� ����(ptr ���� ����) ��ȯ
int Size(const INTSTACK* s) {

	return s->ptr;
}


//������ ��� �ִ°�? ptr <= 0 �̸� ���迬�꿡 ���� ��� ������ 1, �� ���� ������ 0 ���.
int IsEmpty(const INTSTACK* s) {

	return s->ptr <= 0;
}


//������ ���� á�°�? ptr >= max�� Ȯ���ϸ� �ȴ�.(���迬���� ���̸� 1, �����̸� 0�� ����� ��.)
int IsFull(const INTSTACK* s) {

	return s->ptr >= s->max;
}


//Ư�� ������(x)�� ��� index�� ��ġ�ϴ��� �˻�. �̶� stk[ptr - 1] �� �������� stk[0] �ٴ��� ������ �˻���.
int Search(const INTSTACK* s, int x) {

	for (int i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i;
	}

	return -1;

}


//������ ��� �����͸� ���. �ٴ�->����� ������ ���. "%d "�� ���·� �� ĭ �� ���� ���.
void Print(const INTSTACK* s) {
	
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);

	putchar('\n');

}


//���ÿ� �����Ͱ� �Ҵ�Ǿ� ������, free�Լ��� ���� �����Ѵ�.
//max�� ptr ���� 0���� �ٲ۴�.
void Terminate(INTSTACK *s) {

	if (s->stk != NULL)
		free(s->stk);

	s->max = s->ptr = 0;

}


