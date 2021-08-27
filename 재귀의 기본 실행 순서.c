/*재귀 실행 순서: 머릿 속으로 생각하기 복잡하여, 트리를 그려보는 게 좋다.
recur_2(5)의 경우 - r(4)	-r(3)	-r(2)	 -r(1)	-r(0)
					p5		 p4		 p3		  p2	 p1
					r(3)	 r(2)	 r(1)	  r(0)	 r(-1)
					r(2)	 r(1)	 r(0)	  r(-1)  r(-2)

대략 위와 같은 트리로 실행된다.
종결조건에 다다르기 전까지, 맨 위의(가장 왼쪽의) 재귀를 DFS 형식으로 우선 실행한다.
즉 꼬리 쪽인 recur(1) - printf(1)부터 출력된다.
즉 123141215123112의 순서로 출력된다.

스택과 goto문을 활용해 재귀함수를 대체 가능하다.*/


#include <stdio.h>

void recur(int n) {

	if (n > 0) {

		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}

void recur_2(int n) {

	if (n > 0) {

		recur_2(n - 1);
		printf("%d\n", n);
		recur_2(n - 2);
		recur_2(n - 3);
	}
}

void recur_3(int n) {
TOP:
	if (n > 0) {
		recur_3(n - 1);
		printf("%d\n", n);
		n = n - 2;
		goto TOP;
		n = n - 3;
		goto TOP;
	}
}

int main(void) {

	int n;
	printf("정수를 입력하세요.: ");
	scanf("%d", &n);


	recur_3(n);

	return 0;
}