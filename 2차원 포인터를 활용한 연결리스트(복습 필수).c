/*구조체로 포인터 변수를 선언할 수 있다.
typedef struct {
char name int age....
} person;

person *p;
(*p).age = 23;       //이때 이와 같이 꼭 포인터에 () 소괄호를 붙여야 함.
그런데 이것이 불편하여 p->age = 23;으로도 표현 가능. (*p).age = 23;과 동일한 기능.*/

/*구조체의 크기는 컴파일러가 어떠한 구조체 정렬 기준(1, 2, 4, 8바이트 정렬)을 쓰는지에
따라 달라질 수 있다. 정렬 기준으로 인한 혼동과 메모리 낭비 방지를 위해
구조체의 요소는 같은 크기, 유사한 크기의 자료형끼리 모아주는 게 좋다.
작은 자료형을 앞 쪽에, 큰 자료형을 뒤 쪽에 묶어 배치하는 게 좋다.
struct Test {
char a; char b; short c; double d; } */

/*연결리스트: 이전에 배운 동적 할당으론, 사용자에게 얼마의 메모리를 쓸지 물어보는 과정이 필수였다.
연결리스트를 활용하면, 프로그램이 메모리 사용에 맞게 자동으로 동적 할당하게 가능.
아이디어: node == target 숫자와 포인터를 하나로 묶는 구조체
head pointer(node1의 주소) -> node1(node2의 주소) -> node2.......->NULL
NULL은 다음 노드가 없음을 나타낸다.*/

#include <stdio.h>
#include<stdlib.h>

typedef struct {
	int number;
	int* p_next;
} NODE;


// NODE **pp_tail = &p_tail;   *pp_tail == p_tail  (2차원 포인터에 1차원 포인터의 주소를 받았기 때문에)
// *를 하나씩 없애 생각해야 한다.
//p_tail을 기준으로 node를 추가하는 이유는, node를 끝까지 추가했을 때 p_tail에 결국 맨 뒤 node의 주소가 저장될 것이기 때문
//p_head를 기준으로 node를 추가하면, p_head에 저장된 주소가 맨 끝으로 밀릴 것이기 때문에 적절하지 않다.
void AddNODE(NODE **pp_head, NODE **pp_tail, int data) {
	

	if (NULL != *pp_head) {

		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE)); //다음 노드의 공간 확보
		*pp_tail = (*pp_tail)->p_next; //다음 노드로 주소 옮김.
	} 
	
	
	else { 	
		//처음에는 p_head = NULL이므로 여기를 먼저 실행하여, 첫 노드를 p_head에 만든다.
		//p_head는 고정, p_head의 주소를 p_tail이 받아 뒤로 한 칸씩 움직인다.

		*pp_head = (NODE*)malloc(sizeof(NODE));
		*pp_tail = *pp_head;
	}

	//현재 상황: p_tail에 다음 노드의 주소(p_next) 저장됨. 
	//즉 *pp_tail을 사용하면, p_next의 값을 바꿀 수 있음
	(*pp_tail)->number = data;
	(*pp_tail)->p_next = NULL; 

}

int main(void) {

	NODE* p_head = NULL, * p_tail = NULL, * p;
	//처음에는 헤드, 테일 포인터를 NULL로 설정하고, AddNODE 함수 내에서 노드를 추가한다.
	int temp, sum;

	while (1) {
		printf("숫자를 입력하세요(9999를 누르면 종료): ");
		scanf("%d", &temp);

		if (9999 == temp) break;

		AddNODE(&p_head, &p_tail, temp);
		//여기서 pp_head = &p_head; pp_tail = &p_tail; 즉 2차원 포인터에 1차원 포인터의 주소를 저장.
		//즉 *pp_head = p_head; *pp_tail = p_tail; 
		//AddNODE 함수 내에선 *를 하나씩 없애서 생각해야 한다!
	}


	p = p_head;       //맨 처음의 주소를 받음

	while (NULL != p) { //다음 주소가 존재하면,
		if (p != p_head) printf(" + "); //처음엔 p == p_head이므로 실행되지 않고, 2번째부터 실행된다.

		printf("%d", p->number);
		sum += p->number;
		p = p->p_next;
	}

	printf(" = %d", sum);


	//메모리 할당 해제
	while (NULL != p_head) {
		p = p_head; //원래 마지막 주소는 0인데, 해제를 위해 p_head 대입.
		p_head = p_head->p_next;
		free(p); //p_head부터 해제, p_next해제....
	}

	p_tail = p_head; //마지막 남은 p_tail까지 별도로 해제해야 한다.

	return 0;
}