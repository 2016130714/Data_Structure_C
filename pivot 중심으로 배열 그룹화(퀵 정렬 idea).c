/*퀵 정렬: 가장 빠른 정렬 알고리즘 중 하나다.
아이디어: pivot설정(처음엔 가운데). pivot을 중심으로 왼쪽을 pl, 오른쪽을 pr로 배정.
pl과 pr의 값을 비교해가며, pivot 이하의 값을 왼쪽으로, 이상의 값을 오른쪽으로 이동.

partition함수: pivot보다 작은 값을 pl로, 큰 값을 pr로 보내는 함수. pl++, pr--를 해가며 대소관계 비교.
pl < pivot < pr 이런 경우는 쉬운데, 문제는 pivot < pl < pr  / pl < pr < pivot -> 이러한 경우들.
pivot < pl < pr이면, pr--만 해야하고, pl < pr < pivot이면 pl++만 해야한다. (알맞은 위치에 있는 인덱스만 ++ or --)
그리고 pl < pivot < pr과 같은 경우에만 swap해야함. 결과적으로 pl과 pr의 개수가 달라져도 문제는 없다.*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type temp = x; x = y; y = temp;} while(0)


void partition(int array[], int n) {
	
	int i;
	int pivot = array[n / 2];
	int pl = 0;
	int pr = n - 1;

	while(pl <= pr) {
		while (array[pl] < pivot) pl++;
		
		while (array[pr] > pivot) pr--;  //위치 이동이 필요 없는 경우, 단순히 pl++, pr--한다.
		//이러한 경우가 연속으로 있을 수 있기에, if문이 아닌 while문을 써야 함.

		if (pl <= pr) {
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;
		}
		
	} 

	putchar('\n');

	printf("피벗: %d\n", pivot);

	printf("피벗 이하의 그룹\n");


	//while문에서 swap을 마친 후, pl++, pr--를 한 번 더 수행하기 때문에, 예상보다 +-1의 수치로 반복문을 진행
	//즉 pl - 1과 pr + 1
	for (i = 0; i <= pl - 1; i++)
		printf("%2d", array[i]);

	putchar('\n');
	
	printf("피벗 이상의 그룹\n");

	for (i = pr + 1; i < n; i++) {
		printf("%2d", array[i]);
	}
}


int main(void) {

	int* array, n;

	printf("원소의 수: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	partition(array, n);


	return 0;
}