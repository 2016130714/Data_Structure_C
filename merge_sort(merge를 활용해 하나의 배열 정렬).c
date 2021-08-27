/*merge: ���ĵ� �� �迭�� �Է����� �޾�, �ϳ��� ���ĵ� �迭�� ����.
merge sort: �ϳ��� �迭�� �ŵ� ����(���Ұ� �ϳ��� ������), recursive�ϰ� merge�� ���� -> �ϳ��� �迭�� ����

static ���� ���: ���α׷� ���� ��ü���� �����ؾ� �� ������ ���� �� ���
1. ����, ���� ������ ��� ��� ����.
2. ����� �Լ� �������� ��� ����. ex) static void merge_sort(){}
3. ����������, ���������� �����ص�, �Լ��� ���� ���� ��� �����ȴ�.

merge sort ���̵��: �ϳ��� �迭�� �޾�. ����� ������ ���� ���Ұ� 2�� ���� ������ �и�. (left < right)�� ������ �ٿ�.
�� ���Һ��� left...center ������ buff�迭�� ���� / center...right ������ a �迭�� ���ܵ�. buff�� a�� ���� merge�� ����.
buff�� a�� ��Ұ��踦 ���ϰ�,
result = left; a[result++]�� �� �迭�� �����ϸ� ����/*/
#include <stdio.h>
#include <stdlib.h>

static int* buff;

static void merge_sort(int a[], int left, int right) {


	if (left < right) {  

		int center = (left + right) / 2;
		int temp = 0;
		int i;
		int j = 0; int result = left;


		merge_sort(a, left, center);        //center ������ ���� recursive�ϰ� �ŵ� ����. ���������� 1���� ���Һ��� �����ϰ� �ȴ�.
		merge_sort(a, center + 1, right);

		for (i = left; i <= center; i++)
			buff[temp++] = a[i];              //buff�� a[0]���� a[center]���� ����. ���� i == center;


		//i == center���� ����Ͽ� a[i]�� �ᱹ a[center]...a[right]�� ����Ŵ.
		//buff[0]...buff[center]�� a[center]...a[right]�� ���ǿ����ڷ� ���Ͽ�, �� ���� ���� a[result++]�� ���� ����
		while (i <= right && j < temp)        
			a[result++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];

		while (j < temp)        //�ٷ� ���� while������, 
			a[result++] = buff[j++];

	}

}

//recursive �Լ� ������ buff�� ������ �Ҵ��ϸ�, malloc�� �� �� ���� ���� ���� ����Ǳ� ������,
//�̷��� ������ ���� Ȯ���� ���� �Լ��� ���.
int __mergesort(int a[], int n) {

	if ((buff = malloc(n * sizeof(int))) == NULL)
		return -1;

	merge_sort(a, 0, n - 1);

	free(buff);
	return 0;

}



int main(void) {

	int* a, n, i;

	printf("merge sort\n");

	printf("������ ��: ");
	scanf("%d", &n);

	a = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", a + i);
	}

	__mergesort(a, n);
	printf("merge sort completed.\n");

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, a[i]);

	free(a);
	return 0;
}