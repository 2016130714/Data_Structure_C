/*동적 메모리 할당: int *p = calloc(개수, sizeof(자료형))
int *p = (int *)malloc(sizeof(자료형)*개수)
헤더: #include<stdlib.h>*/

#include <stdio.h>
#include <stdlib.h>

//n개의 숫자 중 최댓값을 구하는 알고리즘
int MaxOfN(int *num, int n) {
	int max = *num;

	for (int i = 1; i < n; i++) {
		if (num[i] > max) max = num[i];
	}

	return max;
}



int main(void) {
	int* height, number;

	printf("사람 수: ");
	scanf("%d", &number);

	height = (int*)calloc(number, sizeof(int));

	printf("\n%d 명의 키를 입력하세요.\n", number);

	for (int i = 0; i < number; i++)
		scanf("%d", &height[i]);

	printf("\n최댓값은 %d입니다.", MaxOfN(height, number));

	free(height);


}