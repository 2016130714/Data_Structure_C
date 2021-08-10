/*난수의 생성:
헤더: #include<time.h>
seed 초기화: srand(time(NULL))
난수 생성: rand()
rand 함수로 생성되는 난수는 0 이상 RAND_MAX이하다.
RAND_MAX는 컴퓨터 환경에 따라 다른데, 기본적으로 최소 32767 이상이다.
난수의 규모를 조정하기 위해 rand() % 90와 같은 방법을 쓴다.
(ex. 난수를 90으로 나눈 나머지)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MaxOfN(int* array, int index) {
	int max = *array;

	for (int i = 1; i < index; i++) {
		if (array[i] > max)
			max = array[i];
	}

	return max;
}


int main(void) {
	int* array, index;

	printf("사람 수: ");
	scanf("%d", &index);

	array = (int*)calloc(index, sizeof(int));

	srand(time(NULL));
	printf("\n랜덤으로 %d명의 키 값을 생성합니다.\n", index);

	for (int i = 0; i < index; i++) {
		int temp = 100 + rand() % 90;
		printf("%d\n", temp);
		//랜덤의 키를 생성하는 아이디어

		*(array + i) = temp;

	}

	printf("\n최댓값은 %d입니다", MaxOfN(array, index));

	free(array);
}

//사람 수 n을 입력하면, n명의 키를 랜덤 생성. 그 중 최댓값을 구한다.