/*함수 포인터: 특정 함수의 시작 명령어의 위치를 가리키는 포인터. 쉽게 말해 함수를 가리키는 포인터.
선언: int (*p)(int, int)     ->         (반환형)(포인터 변수)(자료형, 자료형...)
p = &Sum       -> &를 쓰지 않고 Sum만 써도 같은 기능.

비슷한 함수 그룹화: 반환형, 인수가 같은 함수들은 함수 포인터 배열을 선언하여 그룹화 가능.
int (*p[4])(int, int) = {&Sum, &Sub, &Mul, &Div};*/

#include <stdio.h>

int Sum(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}

int Div(int a, int b) {
	return a / b;
}





int main(void) {
	int a, b;

	int(*p[4])(int, int) = { Sum, Sub, Mul, Div };
	//위와 같이 함수 포인터 배열을 활용할 수 있다.
	int op_table[] = { '+', '-', '*', '/' };

	for (int i = 0; i < 4; i++)
		printf("%d %c %d = %d\n", 8, op_table[i], 2, (*p[i])(8, 2));

	return 0;
}