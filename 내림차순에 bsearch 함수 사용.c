#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int* a, int* b) {

	return *a < *b ? 1 : *a > *b ? -1 : 0;
}






int main(void) {
	
	int n, *array, key, *result;

	printf("bsearch 함수로 검색\n");
	printf("원소의 수: ");
	scanf("%d", &n);

	array = (int*)calloc(n, sizeof(int));
	
	printf("내림차순으로 입력하세요.\n");

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("검색 값: ");
	scanf("%d", &key);

	result = bsearch(&key, array, n, sizeof(int), (int(*)(const void*, const void*))int_cmpr);

	printf("%d는 x[%d]에 있습니다.", key, result - array);

	return 0;
}