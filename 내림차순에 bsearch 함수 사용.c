#include <stdio.h>
#include <stdlib.h>

int int_cmpr(const int* a, int* b) {

	return *a < *b ? 1 : *a > *b ? -1 : 0;
}






int main(void) {
	
	int n, *array, key, *result;

	printf("bsearch �Լ��� �˻�\n");
	printf("������ ��: ");
	scanf("%d", &n);

	array = (int*)calloc(n, sizeof(int));
	
	printf("������������ �Է��ϼ���.\n");

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("�˻� ��: ");
	scanf("%d", &key);

	result = bsearch(&key, array, n, sizeof(int), (int(*)(const void*, const void*))int_cmpr);

	printf("%d�� x[%d]�� �ֽ��ϴ�.", key, result - array);

	return 0;
}