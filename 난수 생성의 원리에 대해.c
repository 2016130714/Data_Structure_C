/*의사 난수: 컴퓨터에서 생성한 난수는 정말 random이 아니라,
seed 값과 컴퓨터 환경 기반으로 계산된 값이다!! 
따라서 난수 생성 때마다 seed를 변경해야 진짜 난수를 만들 수 있다.

srand() 함수: seed 값을 설정하는 함수
srand()를 실행하지 않거나, srand(50)과 같이 상수 값을 넣으면, 프로그램을 여러 번 실행해도 값이 그대로.
srand()함수는 난수의 seed를 정하는데, 위와 같은 방법으로는 seed가 고정되어 있기 때문

정말 random 값을 생성하려면 seed도 랜덤해야 한다!!
해결법: seed(time(NULL))사용
time함수가 반환하는 값은 time_t형의 '현재 시간'이다.
따라서 프로그램 실행 시마다 시간이 달라지고, 난수도 random해진다.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	srand(time(NULL));
	printf("%d", rand());
}