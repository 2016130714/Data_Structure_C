/*스택: 데이터를 임시로 저장하기 위한 자료구조. LIFO(후입선출)의 순서로 push and pop.
실행 순서: push(main->x->y->z...) -> pop(z->y->x->main)
즉 main 함수는 가장 먼저 push되고, 다른 모든 함수가 pop되기 전까지 main으로 돌아가지 않는다.

헤더 만들기: 시작: #ifndef(if not defined) #define......#endif의 구조
중복 선언을 막기 위해 ifndef를 쓰는 것.
헤더 사용 시 define 이하의 ___IntStack으로 호출하는 것이 아니라, 파일명 IntStack.h로 호출한다.*/


#ifndef ___IntStack
#define ___IntStack

typedef struct {
	int max;     //스택 용량
	int ptr;     //스택 포인터
	int* stk;    //스택의 저장 배열
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
