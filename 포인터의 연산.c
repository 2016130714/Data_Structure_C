//*(a+i) == a[i]; &a[0] == &*a == a
//포인터 변수는 int형이기에, 포인터 변수+1은 자동으로 +4byte 취급됨.
#include<stdio.h>

int main(void) {
	int data1[] = { 1, 2, 3 };
	char data2[] = { 'a', 'b', 'c' };
	long long data3[] = { 1, 2, 3 };

	int * p = data1;
	char * p2 = data2;
	long long * p3 = data3;
	printf("%d %d\n", p, p+1); //결과: 1899900 1899904
	printf("%d %d\n", p2, p2 + 1); //결과 x x+1
	printf("%d %d\n", p3, p3 + 1); //결과 y y+8
	//주소의 구체적 값은 실행할 때마다 바뀜.
	//포인터 변수에 선언된 자료형에 따라 +1의 크기가 알아서 계산됨(1, 4, 8바이트...)
}