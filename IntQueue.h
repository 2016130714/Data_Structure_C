/*Queue: 스택과 마찬가지로 데이터를 일시적으로 쌓는 자료구조
FIFO(선입선출, First In First Out)이라는 점이 스택과의 차이점.
스택의 용어: push, pop, bottom, top
큐의 용어: enqueue, dequeue, front, rear

ring buffer(링 버퍼): 
선형 큐의 한계: dequeue할 때 q[0]부터 하는데, 남은 데이터를 전부 앞으로 한 칸씩 당기는 낭비 발생(O(n)의 복잡도)
해결법: 링 버퍼 구조의 큐: 배열의 처음과 끝이 연결된 자료구조.
front와 rear는 논리적으로 첫, 마지막 원소를 식별하기 위한 변수.*/

#ifndef ___INTQUEUE
#define ___INTQUEUE

typedef struct {
	int max;      //용량
	int num;      //현재 원소의 수(스택 ptr의 역할)
	int front;    // front (dequeue할 때 front++)
	int rear;     // rear  (enqueue할 때 rear++)
	int* que;     // queue 저장 배열 포인터
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