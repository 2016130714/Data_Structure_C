/*이진 검색: 선형 검색에 비해 빠르다. (log(n)의 복잡도)
다만 배열이 sorted 되어 있어야 사용 가능하다. 오름차순 or 내림차순으로*/

#include <stdio.h>
#include <stdlib.h>


int bin_search(int key, int* array, int n) {

	int start = 0;
	int end = n - 1;
	int middle;
	//int middle = (start / end) / 2
	// 여기서 middle을 선언하면, 탐색의 결과에 따라 middle의 값이 바뀌지 않는다.

	while (start <= end) {
		middle = (start + end) / 2;

		if (array[middle] == key)
			return middle;

		else if (array[middle] < key)
			start = middle + 1;

		else if (array[middle] > key)
			end = middle - 1;
	}
}
/*왜 start = middle; end = middle;이 아니라, middle + 1; middle -1을 할까?
middle에 해당하는 값은 첫 번째 if 문에서 걸리기 때문에, 굳이 다시 탐색할 필요 없다.
middle + 1; middle - 1을 하는 것이 조금이라도 복잡도를 아끼는 방법.*/

int main(void) {
	int n, *array, key;

	printf("이진 검색\n");
	printf("원소의 수: ");

	scanf("%d", &n);
	array = (int*)calloc(n, sizeof(int));

	printf("오름차순으로 배열을 입력하세요.\n");

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("검색 값: ");
	scanf("%d", &key);

	printf("%d는(은) x[%d]에 있습니다.", key, bin_search(key, array, n));

	free(array);
	return 0;
}