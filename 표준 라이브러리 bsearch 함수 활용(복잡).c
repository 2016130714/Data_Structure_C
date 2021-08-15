/*bsearch �Լ�: ���� Ž�� �Լ�
���: #include <stdlib.h>

����: void *bsearch(&key, array, index, sizeof(�ڷ���), compare�Լ�)  -> 5���� �μ��� �޴´�.
�̶� compare�Լ��� ���� �ۼ��ؾ� ��. �̹����� �ܼ��� int�� �񱳶� �����ѵ�,
�� �Լ��� ���ڿ�, ����ü �� �� ������ �͵��� ���� ���� �ֱ� ������, ���� �ۼ� �ʿ�.

compare �Լ��� ��Ģ: int (*compar) (const void *, const void *)�� �⺻ ����.
��, int���� return�ϰ�, const �μ� �� ��(�� ��� �� ��)�� �޴� �Լ� ������.
void *���̱� ������, ��� �� �Ű������� ����ȯ�� �� �ʿ��ϴ�. (������ ������)

�̶� return�ϴ� int ����, 
if(a < b) return -1;    (�������� ũ�� -1 ��ȯ.)
if(a == b) return 0;
if(a > b) return 1;     (������ ũ�� 1 ��ȯ.)
���� �ܿ��־� �Ѵ�.

��ȯ ��(����): �ش�Ǵ� ������ ������(�ּ�). �ش� ������ ������ - �迭�� �����͸� �ϸ� index�� ���� �� �ִ�.
��, int (search - array).
��ȯ���� ���������̱� ������, ó�� bsearch�� ����� �����ϴ� ���� ���� �����ͷ� �����ؾ� �Ѵ�(int *search)*/

#include<stdio.h>
#include<stdlib.h>

int int_cmp(const int *a, const int *b) {
	
	return *a < *b ? -1 : *a > *b ? 1 : 0;
	//���� ������ Ȱ��.
}


int main(void) {

	int n, *array, key, *search;

	printf("bsearch �Լ��� ����� ���� Ž��\n");
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

	search = bsearch(&key, array, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	//bsearch�� ���: �ش� ������ ������. 
	//�Լ� �����Ϳ� void �����Ͱ� ���Ǿ� �̸� int *�� ����ȯ�ߴ�.

	printf("%d�� x[%d]�� �ֽ��ϴ�.",key, search - array);
	//���⼭ *search�� ���� �ش� ������ ��(key)�� �����Ƿ� ������.
	//search - array�� �迭�� ���� �ּҸ� ����, �ε����� ���´�.
	

	free(array);
	return 0;
}