#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

//큐의 num, front, rear을 전부 0으로 초기화.
//max만큼의 메모리 할당에 성공하면 max에 입력 값 대입 및 * que에 해당 메모리 할당
int Initialize(INTQUEUE* q, int max) {

	q->num = q->front = q->rear = 0;

	if ((q->que = malloc(max * sizeof(int))) == NULL) {
		q->max = 0;
		return -1;
	}

	q->max = max;
	return 0;

}


/*인큐 함수: num++, rear++을 하며 입력 데이터 x를 que[rear]에 저장한다.
rear과 num의 차이: num은 현재 데이터의 수, rear은 링 버퍼의 인덱스다. (선형에선 차이가 없으나, 링 버퍼에선 차이가 있다.)

1) 한 번도 디큐하지 않은 자료: front == 0이므로, que[0]...que[rear-1]까지의 자료가 차있을 것이다.(선형 구조와 동일)
이 경우 rear == num

2) 한 번이라도 디큐한 자료: 디큐 과정에서 front++, num--할 것. 반면 rear--는 하지 않음.
그 결과 que[0], que[1]...부터 자리가 비는데, rear는 rear == max에 도달하는 상황이 발생.
그때 rear = 0으로 초기화하여, que[0]부터 자료를 채워야 한다.

인큐 함수에서 num은 무조건 num++해야하는 반면, rear는 rear == max이면 0으로 초기화해야 한다.*/
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


//num이 1 이상일 경우에만 실행 가능. num-- que[front++] 하며,
//*x에 que[front]의 값을 대입한다. (즉 *x = q->que[q->front++])
//이떼, 디큐를 많이 진행했다면 front == max인 상황도 나올 수 있으므로, 그 경우 q->front = 0으로 초기화한다.
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



//스택, 큐에서 peek의 의미: pop, dequeue하면 나올 자료를 엿본다는 의미(자료의 수정은 하지 않고)
//따라서 스택의 peek는 stk[ptr-1]의 자료를 보고, 큐의 peek는 que[front]의 자료를 본다.
//q->num <= 0 이면 실패한다.
int Peek(INTQUEUE* q, int* x) {

	if (q->num <= 0)
		return -1;

	*x = q->que[q->front];
	return 0;
}


//스택의 clear는 ptr만 초기화하면 됐으나, 큐에서는 initialize와 마찬가지로 num, front, rear을 전부 초기화.
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



/*search란: 입력 데이터 int x의 인덱스를 찾는 것.
스택의 search: i = ptr-1부터 i = 0까지 역순 선형 검색하면 됨.
큐의 search: front부터, front + num까지 선형 검색. 다만 문제는 front + num의 값이 max를 넘어가면 초기화해야 함.
초기화할 수 있는 좋은 아이디어가 바로: (i + front) % max이다. 즉, 나머지를 구하면, 초기화가 가능하다!*/
int Search(const INTQUEUE* q, int x) {

	int i, index;

	for (i = 0; i < q->num; i++) {

		if (q->que[index = (i + q->front) % q->max] == x)
			return index;
	}

	return -1;

}



//search와 같은 아이디어 (i + front) % q->max를 사용하여, printf 함수로 출력
void Print(const INTQUEUE* q) {

	for (int i = 0; i < q->num; i++) 

		printf("%d ", q->que[(i + q->front) % q->max]);
	
	putchar('\n');
	
}


//q->que가 NULL이 아니라면, free함수 실행. max, num, front, rear을 전부 0으로 초기화.
void Terminate(INTQUEUE* q) {

	if (q->que != NULL)
		free(q->que);

	q->max = q->num = q->front = q->rear = 0;
}