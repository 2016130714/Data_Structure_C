/*Queue: ���ð� ���������� �����͸� �Ͻ������� �״� �ڷᱸ��
FIFO(���Լ���, First In First Out)�̶�� ���� ���ð��� ������.
������ ���: push, pop, bottom, top
ť�� ���: enqueue, dequeue, front, rear

ring buffer(�� ����): 
���� ť�� �Ѱ�: dequeue�� �� q[0]���� �ϴµ�, ���� �����͸� ���� ������ �� ĭ�� ���� ���� �߻�(O(n)�� ���⵵)
�ذ��: �� ���� ������ ť: �迭�� ó���� ���� ����� �ڷᱸ��.
front�� rear�� �������� ù, ������ ���Ҹ� �ĺ��ϱ� ���� ����.*/

#ifndef ___INTQUEUE
#define ___INTQUEUE

typedef struct {
	int max;      //�뷮
	int num;      //���� ������ ��(���� ptr�� ����)
	int front;    // front (dequeue�� �� front++)
	int rear;     // rear  (enqueue�� �� rear++)
	int* que;     // queue ���� �迭 ������
} INTQUEUE;

int Initialize(INTQUEUE* q, int max);

int Enque(INTQUEUE* q, int x);

int Deque(INTQUEUE* q, int* x);

int Peek(INTQUEUE* q, int* x);

void Clear(INTQUEUE* q);

int Capacity(const INTQUEUE* q);

int Size(const INTQUEUE* q);

int IsEmpty(const INTQUEUE* q);

int IsFull(const INTQUEUE* q);

int Search(const INTQUEUE* q, int x);

void Print(const INTQUEUE *q);

void Terminate(INTQUEUE* q);

#endif