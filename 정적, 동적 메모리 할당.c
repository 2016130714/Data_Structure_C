//전역변수: 프로그램이 종료될 때까지 메모리 공간, 주소가 변하지 않음.
//지역변수: 함수 호출, 종료마다 메모리 공간, 주소가 변함. -> 포인터로 주소를 기억해야함.
//지역변수를 사용하려면 변수 개수만큼 주소를 알아야 하는데, 하나하나 선언 시 낭비가 심함.
//stack의 형태 활용: START+0, START+4, START+8...END의 형태로 주소를 관리
//stack으로 지역변수를 관리하면, 개수에 상관없이 START, END, 크기만 알면 된다!
//자료구조의 psuh, pop을 사용하면 너무 비효율적이기에, 실제 c언어는 START, END를 활용

//지역변수, 정적 메모리 할당의 한계: stack 메모리의 최대 공간이 1Mbyte
//즉 char a[1024*1024] 정도의 변수만 선언해도 오류. 실행에 따라 stack overflow 자주 발생

//동적 메모리 할당: Heap 메모리 공간 활용. 2Gbyte까지 메모리 할당 가능
// void * p = malloc(100) 이런 형태로 활용. default는 void형이다.
//실제로는, 활용하려는 자료형에 따라 형변환하여 int *p = (int *)malloc(sizeof(int) * 50) 이렇게 활용.

//malloc, free함수를 쓸 경우 #include<malloc.h>필요.
//heap의 메모리는 프로그램이 끝날 때까지 자동 해제되지 않음. 스택은 함수 호출마다 자동 해제.
//free(변수); free함수를 써 명시적으로 해제해야 한다.

#include<stdio.h>
#include<malloc.h>

int main(void) {
	char* p = (char*)malloc(32);
	if (p != NULL) {
		//메모리 할당에 성공하면(실패할 수도 있다)
		printf("your name: ");
		scanf("%s", p);     //또는 gets(p)
		printf("Hi~ %s\n", p);
		free(p);
	}
	else
		printf("Memory allocation error");
}