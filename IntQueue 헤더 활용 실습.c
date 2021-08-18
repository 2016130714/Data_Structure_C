#include <stdio.h>
#include "IntQueue.h"

int main(void) {

	INTQUEUE que;

	if (Initialize(&que, 64) == -1) {
		printf("큐 생성 실패");
	}

	while (1) {

		int act, x;

		printf("현재 데이터 수: %d/%d\n", Size(&que), Capacity(&que));
		printf("(1) 인큐 (2) 디큐 (3) 피크 (4) 출력 (0) 종료: ");
		scanf("%d", &act);


		if (act == 0) break;


		switch (act) {

		case 1:
			printf("데이터: ");
			scanf("%d", &x);

			if (Enque(&que, x) == -1)
				printf("인큐에 실패했습니다.");

			break;


		case 2:
			if (Deque(&que, &x) == -1)
				printf("디큐에 실패했습니다.");

			else
				printf("디큐한 데이터는 %d입니다.\n", x);

			break;


		case 3:
			if (Peek(&que, &x) == -1)
				printf("피크에 실패했습니다.");

			else
				printf("피크한 데이터는 %d입니다.\n", x);

			break;


		case 4:
			Print(&que);
			break;
		}
	}

	Terminate(&que);
	return 0;
}