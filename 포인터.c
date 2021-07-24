#include <stdio.h>

void main() {
	int x = 1, y = 2;
	int* ip;
	ip = &x;  //포인터 변수 ip에 일반 변수 x의 주소를 할당
	y = *ip;  //*ip는 값을 의미하는데, ip의 값이 아니라, 연동된 변수 x의 값이다.
	//즉 y에 x의 값 1을 대입한 것.
	*ip = 0; //*ip == x다. 즉 x에 0을 대입
	printf("%d %d %d", *ip, x, y);
}