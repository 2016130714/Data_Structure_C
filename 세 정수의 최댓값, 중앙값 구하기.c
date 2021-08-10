/*최댓값 아이디어: int max = a
if문을 거쳐 더 큰 수를 max에 대입한다. return max;한다. 
중앙값 아이디어: 세 숫자의 대소 관계, 경우의 수는 13이다.
i) 세 값이 다 다른 경우: 6  ii) 두 값이 같은 경우: 6   iii) 세 값이 같은 경우: 1*/
#include <stdio.h>

int Max3(int a, int b, int c) {
	int max = a;
	
	if (b > a) max = b;
	if (c > b) max = c;

	return max;
}


int Med3(int a, int b, int c) {
	int med = a;

	if ((a <= b && b <= c) || (c <= b && b <= a)) med = b;
	if ((a <= c && c < b) || (b <= c && c <= a)) med = c;
	//a <= b <= c의 형태로 쓰면 안됨. a <= b && b <= c로 써야함!!

	return med;
}


//중앙값 구하기 다른 알고리즘
int Med_else(int a, int b, int c) {
	int med = a;

	if (b >= a) if (b <= c) med = b;
	if (a <= c) if (c <= b) med = c;

	return med;
}


int main(void) {
	int a, b, c, max, med, med2;
	printf("정수 3개 입력: ");
	scanf("%d %d %d", &a, &b, &c);
	max = Max3(a, b, c);
	med = Med3(a, b, c);
	med2 = Med_else(a, b, c);
	printf("최댓값: %d\n", max);
	printf("중앙값: %d\n", med);
	printf("중앙값: %d", med2);

	return 0;
}