#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

//ť�� num, front, rear�� ���� 0���� �ʱ�ȭ.
//max��ŭ�� �޸� �Ҵ翡 �����ϸ� max�� �Է� �� ���� �� * que�� �ش� �޸� �Ҵ�
int Initialize(INTQUEUE* q, int max) {

	q->num = q->front = q->rear = 0;

	if ((q->que = malloc(max * sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}

	q->max = max;
	return 0;

}


/*��ť �Լ�: num++, rear++�� �ϸ� �Է� ������ x�� que[rear]�� �����Ѵ�.
rear�� num�� ����: num�� ���� �������� ��, rear�� �� ������ �ε�����. (�������� ���̰� ������, �� ���ۿ��� ���̰� �ִ�.)

1) �� ���� ��ť���� ���� �ڷ�: front == 0�̹Ƿ�, que[0]...que[rear-1]������ �ڷᰡ ������ ���̴�.(���� ������ ����)
�� ��� rear == num

2) �� ���̶� ��ť�� �ڷ�: ��ť �������� front++, num--�� ��. �ݸ� rear--�� ���� ����.
�� ��� que[0], que[1]...���� �ڸ��� ��µ�, rear�� rear == max�� �����ϴ� ��Ȳ�� �߻�.
�׶� rear = 0���� �ʱ�ȭ�Ͽ�, que[0]���� �ڷḦ ä���� �Ѵ�.

��ť �Լ����� num�� ������ num++�ؾ��ϴ� �ݸ�, rear�� rear == max�̸� 0���� �ʱ�ȭ�ؾ� �Ѵ�.*/
int Enque(INTQUEUE* q, int x) {

	if (q->num >= q->max)
		return -1;

	else {
		q->num++;
		q->que[q->rear++] = x;

		if (q->rear >= q->max)
			q->rear = 0;

		return 0;
	}

}


//num�� 1 �̻��� ��쿡�� ���� ����. num-- que[front++] �ϸ�,
//*x�� que[front]�� ���� �����Ѵ�. (�� *x = q->que[q->front++])
//�̶�, ��ť�� ���� �����ߴٸ� front == max�� ��Ȳ�� ���� �� �����Ƿ�, �� ��� q->front = 0���� �ʱ�ȭ�Ѵ�.
int Deque(INTQUEUE* q, int* x) {

	if (q->num <= 0)
		return -1;

	else {
		q->num--;
		*x = q->que[q->front++];

		if (q->front == q->max)
			q->front = 0;

		return 0;
		
	}
}



//����, ť���� peek�� �ǹ�: pop, dequeue�ϸ� ���� �ڷḦ �����ٴ� �ǹ�(�ڷ��� ������ ���� �ʰ�)
//���� ������ peek�� stk[ptr-1]�� �ڷḦ ����, ť�� peek�� que[front]�� �ڷḦ ����.
//q->num <= 0 �̸� �����Ѵ�.
int Peek(INTQUEUE* q, int* x) {

	if (q->num <= 0)
		return -1;

	*x = q->que[q->front];
	return 0;
}


//������ clear�� ptr�� �ʱ�ȭ�ϸ� ������, ť������ initialize�� ���������� num, front, rear�� ���� �ʱ�ȭ.
void Clear(INTQUEUE* q) {

	q->num = q->front = q->rear = 0;
}


int Capacity(const INTQUEUE* q) {

	return q->max;
}

int Size(const INTQUEUE* q) {

	return q->num;
}


int IsEmpty(const INTQUEUE* q) {

	return q->num <= 0;
}

int IsFull(const INTQUEUE* q) {

	return q->num >= q->max;
}



/*search��: �Է� ������ int x�� �ε����� ã�� ��.
������ search: i = ptr-1���� i = 0���� ���� ���� �˻��ϸ� ��.
ť�� search: front����, front + num���� ���� �˻�. �ٸ� ������ front + num�� ���� max�� �Ѿ�� �ʱ�ȭ�ؾ� ��.
�ʱ�ȭ�� �� �ִ� ���� ���̵� �ٷ�: (i + front) % max�̴�. ��, �������� ���ϸ�, �ʱ�ȭ�� �����ϴ�!*/
int Search(const INTQUEUE* q, int x) {

	int i, index;

	for (i = 0; i < q->num; i++) {

		if (q->que[index = (i + q->front) % q->max] == x)
			return index;
	}

	return -1;

}



//search�� ���� ���̵�� (i + front) % q->max�� ����Ͽ�, printf �Լ��� ���
void Print(const INTQUEUE* q) {

	for (int i = 0; i < q->num; i++) 

		printf("%d ", q->que[(i + q->front) % q->max]);
	
	putchar('\n');
	
}


//q->que�� NULL�� �ƴ϶��, free�Լ� ����. max, num, front, rear�� ���� 0���� �ʱ�ȭ.
void Terminate(INTQUEUE* q) {

	if (q->que != NULL)
		free(q->que);

	q->max = q->num = q->front = q->rear = 0;
}