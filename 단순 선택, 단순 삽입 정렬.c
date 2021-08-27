/*아이디어: 배열 내에서 minimum을 찾는다. minimum을 array[0]과 swap한다.
array[1]...array[n - 1]에서 min, array[2]....array[n -1]...에서 min 찾기... 과정을 반복한다.*/

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) {type temp = x; x = y; y = temp;} while(0)


/*나는 int min = array[i]로 설정하는 코드를 썼는데, 제대로 실행되지 않았다.
이유를 고민해보자!*/
void selection(int array[], int n) {
	

	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;

		for (j = n - 1; j > i; j--)
			if (array[j] < array[min])
				min = j;
		swap(int, array[i], array[min]);
	}
}

void insertion(int array[], int n) {

	int i, j;
	for (i = 1; i < n; i++) {
		int temp = array[i];
		for (j = i - 1; j > 0 && array[j] > temp; j--) 
			array[j + 1] = array[j];     //여기서 temp의 값을 보존해야 하므로, temp이 아닌 j + 1로 표현해야 함.
		array[j] = temp;		
	}

}

int main(void) {

	int n, * array;

	printf("단순 선택 정렬\n");
	printf("원소의 수 입력: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("오름차순으로 정렬했습니다.\n");
	insertion(array, n);

	for (int i = 0; i < n; i++) {
		printf("x[%d]: %d\n", i, array[i]);
	}

	return 0;
}