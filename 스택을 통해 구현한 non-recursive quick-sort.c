/*stack의 push, pop과정이 복잡하니까, 잘 생각해봐야 함.

아이디어: pivot을 중심으로 왼쪽을 관리하는 lstack, 오른쪽을 관리하는 rstack 생성.
1. lstack에 0(초기 left), rstack에 n - 1(초기 right) push.
2. pl = left; pr = right를 대입하여, left, right의 값은 건들지 않고 pl, pr의 커서만 옮겨 퀵 정렬 진행.
(이는 재귀적 알고리즘과 동일한 아이디어)
3. 그 결과 pl, pr만 pivot 근처에 도달할 것.

핵심 아이디어
4. if(pr > left) Push(&rstack, pr) Push(&lstack, left)
if(pl < right) Push(&lstack, pl) Push(&rstack, right)
5. Push 결과: lstack: {0, pl} rstack: {pr, right}

6. 전체 반복문의 위로 돌아가 Pop(&lstack), Pop(&rstack)하면, 후입선출에 따라 lstack의 pl, rstack의 right가 나올 것이다.
7. 위와 같은 순서에선(pl -> right) 즉, pivot의 뒤 쪽을 먼저 정렬하고, 그 뒤에 left -> pr, pivot의 앞 쪽을 정렬할 것이다.
8. 즉 if문 순서에 따라 pivot의 앞쪽 또는 pivot의 뒤쪽을 먼저 정렬할 것이다.(아래 코드에선 역순으로 짰다.)*/

#include <stdio.h>
#include "INTSTACK.h"
#include <stdlib.h>

#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void quick(int array[], int left, int right) {

	INTSTACK lstack;
	INTSTACK rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		Pop(&lstack, &left);
		Pop(&rstack, &right);
		int pl = left;
		int pr = right;
		int pivot = array[(pl + pr) / 2];
		
		while (pl <= pr) {

			while (array[pl] < pivot) pl++;
			while (array[pr] > pivot) pr--;

			if (pl <= pr) {
				swap(int, array[pl], array[pr]);
				
				pl++;
				pr--;
			}

			if (right > pl) {
				Push(&rstack, right);
				Push(&lstack, pl);
			}

			if (left < pr) {
				Push(&lstack, left);
				Push(&rstack, pr);
			}

		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}


int main(void) {

	int* array, n, i;

	printf("비재귀적 퀵 정렬\n");
	printf("원소의 수: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("오름차순으로 정렬했습니다.\n");

	quick(array, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, array[i]);

	return 0;
}