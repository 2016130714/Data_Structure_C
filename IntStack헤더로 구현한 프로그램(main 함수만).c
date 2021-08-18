/* switch 조건문을 활용하여 스택 구현
주의할 점: initialize, push, pop, peek에 대해 항상 if문을 통해 실패 가능성을 포함시켜야 한다.
(헤더 코드에서 int형으로 선언하여 return -1과 return 0의 경우를 나눈 함수들)
즉 if(Push(&s, data) == -1) printf("실패했습니다.)         //이런 식으로   */

#include <stdio.h>
#include "IntStack.h"

int main(void) {

	INTSTACK s;

	//스택 생성
	if (Initialize(&s, 64) == -1) {
		printf("스택 생성 실패");
		return 1;
	
	}

	while (1) {

		int menu, data;

		printf("현재 데이터 수: %d/%d\n", Size(&s), Capacity(&s));

		printf("(1) 푸시  (2) 팝  (3) 피크  (4) 출력  (0) 종료: ");
		scanf("%d", &menu);

		if (menu == 0) break;

		switch (menu) {

		case 1:  //push

			printf("데이터: ");
			scanf("%d", &data);

			if (Push(&s, data) == -1)
				printf("push에 실패했습니다.");

			break;

		
		case 2:    //pop
			
			if (Pop(&s, &data) == -1)
				printf("pop에 실패했습니다.");

			else
				printf("pop 데이터는 %d입니다.\n", data);


			break;


		case 3:   //peek

			if (Peek(&s, &data) == -1)
				printf("peek에 실패했습니다.");

			else
				printf("peek데이터는 %d입니다.\n", data);

			break;


		case 4:    //print

			Print(&s);
			break;

		}           //switch문 종료
	}        //while문 종료

	Terminate(&s);

	return 0;
}