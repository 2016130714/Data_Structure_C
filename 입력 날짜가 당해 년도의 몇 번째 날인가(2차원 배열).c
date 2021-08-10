/*윤년 구하는 방법: 4의 배수 가운데 100의 배수를 제외하고, 다시 400의 배수를 포함*/

#include <stdio.h>

int MthDays[2][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } }; // 전역변수 선언. 윤년과 아닌 걸 구분한 2차원 배열


//윤년인지 판단하는 함수
int IsLeap(int year) {
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	/*0과 1의 판단이 필요한 함수는 굳이 if문을 쓰지 않아도 이렇게 간략화 가능.
	return 이하가 참이면 1을 반환할 것이고, 거짓이면 0을 반환할 것이기 때문.
	(조건 연산자를 활용했기에 참거짓만 판단한다.)
	즉 4의 배수이거나 400의 배수면 1을 반환, 동시에 100의 배수가 아니면 1을 반환 -> MthDays[1][12] 조회
	해당되지 않는 일반 연도의 경우 0을 반환 -> MthDays[0][12] 조회*/
	
}



int DayOfYear(int year, int month, int date) {
	int sum = 0;
	
	//시작 종결 조건 명확히 판단. (2월부터 MthDays를 더해야 한다. 1월은 더하지 않고)
	for (int i = 1; i < month; i++)
		sum += MthDays[IsLeap(year)][i - 1];

	sum += date;
	return sum;
}

int main(void) {
	int year, month, date;
	printf("년: ");
	scanf("%d", &year);
	printf("월: ");
	scanf("%d", &month);
	printf("일: ");
	scanf("%d", &date);

	printf("%\n%d년의 %d번째 날입니다.", year, DayOfYear(year, month, date));




	return 0;
}