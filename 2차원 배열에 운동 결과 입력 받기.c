/*20대 4명, 30대 2명 40대 3명의 결과를 2차원 배열에 저장
최대 인원이 있는 20대의 4명에 맞춰 최소 [3][4] 크기의 배열 필요
윗몸 일으키기가 1분에 200개 넘는 건 불가능하기에 0-255의 unsigned char로 충분
총 인원은 9명인데 배열이 [3][4]이므로, 3바이트 낭비 발생*/

#include <stdio.h>
//limit_table을 선언하지 않으면 [3][4] 배열 12칸 전체를 쓸 수밖에 없다.


int main(void) {
	unsigned char limit_table[3] = { 4, 2, 3 };
	unsigned char everyone[3][4];
	int age, person, temp;
	int sum = 0;

	for (age = 0; age < 3; age++) {
		printf("%d0대의 윗몸 일으키기 횟수: \n", age + 2);

		for (person = 0; person < limit_table[age]; person++) {
			scanf("%d", &temp);
			//scanf는 자료형에 엄격하기 때문에, 정수를 바로 unsigned char에 받을 수 없다.(print와 달리)
			//따라서 int형인 temp를 통해 scanf를 쓴 뒤, 값을 대입.
			everyone[age][person] = temp;
		}
		//scanf뒤에 별도로 print문을 적을 필요 없다. 적으면 중복 출력됨.
		}
	printf("연령별 평균\n");

	for (age = 0; age < 3; age++) {
		for (person = 0; person < limit_table[age]; person++) 
			sum += everyone[age][person];

		printf("%d0대: %5.2f\n", age + 2, (double)sum / limit_table[age]);
		//소수 둘 째 자리까지 출력하기 위해 %5.2f(5칸 출력, 소숫점 아래 2자리) 사용.
		//이에 상응하게 sum의 자료형을 double로 선언.

		sum = 0; // sum을 초기화하지 않으면 누적되기 때문에 조심!
	}

	
}