/*아이디어: 원소가 n개인 배열에 array에서
array[0]과 array[n-1]을 교환한다.
다음으로 array[1]과 array[n-2]을 교환한다.
이 실행을 n/2번 한다. for loop활용.
원소가 홀수 개이면 따로 가운데의 원소를 교환할 필요는 없다.

swap의 기본 원리: x와 y를 swamp할 때, x y 중 하나의 값을 temp에 보관한다.

매크로 활용: #define에 매크로를 설정해놓고, 이를 활용한다. 매크로에 활용되는 do 문의 형식을 꼭 기억하자.

do문의 문법: do{...;...;..;} while(종결 조건)
여기서 while(0)을 쓰면 딱 한 번만 실행하게 활용 가능하다!*/

#include <stdio.h>
#include<stdlib.h>

//매크로: type형의 x와 y를 swap. 형식을 정확히 기억하자.
#define swap(x, y, type) do {type temp = x; x = y; y = temp;} while(0)
//


void SwapArray(int* array, int index) {

	for (int i = 0; i < index / 2; i++) 
		swap(array[i], array[index - 1 - i], int);
	}

int main(void) {
	int* array, index, i;

	printf("배열 원소의 개수: ");
	scanf("%d", &index);

	array = (int*)calloc(index, sizeof(int));

	printf("\n%d개의 정수를 입력하세요.\n", index);

	for (i = 0; i < index; i++) {
		printf("정수[%d]: ", i);
		scanf("%d", array + i);

	}
	printf("\n역순 정렬은 다음과 같습니다.\n");
	SwapArray(array, index);

	for (i = 0; i < index; i++)
		printf("정수[%d]: %d\n", i, array[i]);

	free(array);
}