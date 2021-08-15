/*무조건 printf만 쓰는 습관을 버리자!
%d, %s, %c 등 키워드가 필요하지 않은, 단순 문자열 출력에서는 putchar, puts함수를 활용하자.
putchar(''): 단일 문자 출력. \n과 같이 한 글자의 문자 출력. 그에 맞게 작은 따옴표 활용.
puts(""): 문자열 출력. 문자열이기 때문에 큰 따옴표 활용.
printf(""): 키워드 활용 가능. 단일 문자도 출력 가능. but 항상 "" 큰 따옴표를 사용할 것!*/


#include <stdio.h>

int sum(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

void Chart(int calc(int, int)) {
	//원칙적으로 함수 포인터 선언 시 int (*calc)와 같이 해야 하지만, 편의상 int calc(int, int) 이렇게 써도 됨.


	int i, j;

	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++)
			printf("%3d", calc(i, j));
		putchar('\n');
	}
	
}

int main(void) {

	puts("덧셈표\n");
	Chart(sum);
	puts("곱셈표\n");
	Chart(mul);
	return 0;
}