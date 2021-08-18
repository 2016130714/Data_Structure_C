/*����: �����͸� �ӽ÷� �����ϱ� ���� �ڷᱸ��. LIFO(���Լ���)�� ������ push and pop.
���� ����: push(main->x->y->z...) -> pop(z->y->x->main)
�� main �Լ��� ���� ���� push�ǰ�, �ٸ� ��� �Լ��� pop�Ǳ� ������ main���� ���ư��� �ʴ´�.

��� �����: ����: #ifndef(if not defined) #define......#endif�� ����
�ߺ� ������ ���� ���� ifndef�� ���� ��.
��� ��� �� define ������ ___IntStack���� ȣ���ϴ� ���� �ƴ϶�, ���ϸ� IntStack.h�� ȣ���Ѵ�.*/


#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;     //���� �뷮
	int ptr;     //���� ������
	int* stk;    //������ ���� �迭
} INTSTACK;

int Initialize(INTSTACK* s, int max);

int Push(INTSTACK* s, int x);

int Pop(INTSTACK* s, int* x);

int Peek(const INTSTACK* s, int* x);

void Clear(INTSTACK* s);

int Capacity(const INTSTACK* s);

int Size(const INTSTACK* s);

int IsEmpty(const INTSTACK* s);

int IsFull(const INTSTACK* s);

int Search(const INTSTACK* s, int x);

void Print(const INTSTACK* s);

void Terminate(INTSTACK* s);



#endif
