/*한 번의 partition 결과: pl, pr커서는 둘 다 pivot 근처에 있을 것이다.

퀵 정렬 아이디어: pr의 커서를 0까지 보내며, pl의 커서를 n - 1까지 보내며 정렬한다.
즉, partition(array, 0, pr)과 partition(array, pl, n - 1)을 반복하는 알고리즘을 만든다.
그 결과 정렬될 것이다.*/


#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)



void qsort(int array[], int left, int right) {

	int pl = left;
	int pr = right;
	int pivot = array[(pl + pr) / 2];

	//while문 내부의 if(pl <= pr)이 필수인 이유: 만약 while(array[pl] < pivot)의 결과로
	//pl, pr의 앞 뒤가 바뀌었을 때, 전체 while문 앞 뒤의 pl <= pr에 걸리지 않고 swap이 진행될 수 있다.
	//그것을 막기 위해 내부에서도 pl <= pr의 조건을 한 번 더 걸어준 것.
	while(pl <=pr) {
		while (array[pl] < pivot) pl++;

		while (array[pr] > pivot) pr--;

		
		if (pl <= pr) {    
			swap(int, array[pl], array[pr]);
			pl++;
			pr--;

		}
	} 
	
	if (left < pr) qsort(array, left, pr);

	if (pl < right) qsort(array, pl, right);
}

int main(void) {

	int* array, n, i;

	printf("퀵 정렬\n");
	printf("원소의 수: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	qsort(array, 0, n - 1);

	printf("오름차순으로 정렬했습니다.\n");

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, array[i]);

	return 0;
}