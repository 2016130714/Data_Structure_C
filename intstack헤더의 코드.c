#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//스택을 쌓기 위해, max만큼의 메모리 공간 확보, 준비 작업.
//ptr = 0 대입. max에 입력받은 값 대입.
//성공: max만큼의 메모리 공간 확보 return 0   //실패: max에 0 대입. return -1
int Initialize(INTSTACK *s, int max) {
	
	s->ptr = 0;

	//입력받은 max * sizeof(int)만큼의 메모리 할당 시도(max: 스택 최대 용량)
	//max만큼의 메모리 할당에 실패하면 max에 0을 대입하고 return -1한다.
	if ((s->stk = malloc(max * sizeof(int))) == NULL) {
		s->max = 0;
		return -1;
	}

	//메모리 할당이 성공하면, 원소의 수가 max개인 stk를 만드는 준비작업
	//stk[0], stk[1],.....stk[max-1]
	s->max = max;
	return 0;
}


/*int ptr의 역할: 1. ptr이라는 이름과 달리 포인터 변수가 아니라 일반 변수다.
2. *stk, 즉 스택에 int x의 데이터를 넣을 때마다 ptr값을 1씩 증가시킨다. (ptr++)
3. initialize 때 ptr = 0으로 선언하며, push함수에 의해 ptr == max이면 스택이 가득 차 더 이상 push할 수 없다.
4. (s->ptr >= s-> max) 즉 ptr 값이 max 이상이면, 스택이 가득 찼다는 의미로 return -1한다. 
그렇지 않으면, (s->stk[s->ptr++] = x). 즉 stk[0]부터 데이터를 대입한다.*/
int Push(INTSTACK* s, int x) {
	
	if (s->ptr >= s->max)
		return -1;
	
	s->stk[s->ptr++] = x;
	return 0;
}


//push와 반대의 개념. LIFO의 개념에 맞춰 str[ptr]부터 데이터를 pop함. 데이터를 int *x에 저장.
//책의 코드가 잘못된 것 같아 약간 수정했음.
int Pop(INTSTACK* s, int* x) {
	
	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr - 1];
	s->ptr = s->ptr--;

	return 0;

}

//스택 꼭대기의 데이터를 peek(엿보는) 함수. 
//참고로, 꼭대기의 데이터는 stk[ptr-1]에 저장되어 있다. push할 때 stk[ptr++]하기 때문.
//즉, ptr = 0인 상태에서 stk[0] = x를 대입하고, ptr == 1로 만들어 놓은 상태.
//결국 데이터가 차 있는 건 stk[ptr-1]까지고, stk[ptr]은 다음 데이터를 넣을(현재는 비어있는) 위치다.
int Peek(const INTSTACK* s, int* x) {

	if (s->ptr <= 0)
		return -1;

	*x = s->stk[s->ptr - 1];
	return 0;
	
}

//스택을 비우는 함수. 스택의 모든 push와 pop은 ptr을 기반으로 이뤄지기 때문에, 따로 *stk를 건들지 않고,
// ptr = 0만 선언해줘도 스택을 비울 수 있다.
void Clear(INTSTACK* s) {

	s->ptr = 0;
}

//스택의 용량(max의 값)을 반환
int Capacity(const INTSTACK* s) {

	return s->max;
}


//현재 스택에 쌓인 데이터의 개수(ptr 값과 동일) 반환
int Size(const INTSTACK* s) {

	return s->ptr;
}


//스택이 비어 있는가? ptr <= 0 이면 관계연산에 의해 비어 있으면 1, 한 개라도 있으면 0 출력.
int IsEmpty(const INTSTACK* s) {

	return s->ptr <= 0;
}


//스택이 가득 찼는가? ptr >= max만 확인하면 된다.(관계연산이 참이면 1, 거짓이면 0을 출력할 것.)
int IsFull(const INTSTACK* s) {

	return s->ptr >= s->max;
}


//특정 데이터(x)가 어느 index에 위치하는지 검색. 이때 stk[ptr - 1] 즉 꼭대기부터 stk[0] 바닥의 순서로 검색함.
int Search(const INTSTACK* s, int x) {

	for (int i = s->ptr - 1; i >= 0; i--) {
		if (s->stk[i] == x)
			return i;
	}

	return -1;

}


//스택의 모든 데이터를 출력. 바닥->꼭대기 순서로 출력. "%d "의 형태로 한 칸 씩 띄어가며 출력.
void Print(const INTSTACK* s) {
	
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);

	putchar('\n');

}


//스택에 데이터가 할당되어 있으면, free함수를 통해 해제한다.
//max와 ptr 값도 0으로 바꾼다.
void Terminate(INTSTACK *s) {

	if (s->stk != NULL)
		free(s->stk);

	s->max = s->ptr = 0;

}


