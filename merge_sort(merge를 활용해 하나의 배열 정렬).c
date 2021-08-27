/*merge: 정렬된 두 배열을 입력으로 받아, 하나의 정렬된 배열로 병합.
merge sort: 하나의 배열을 거듭 나눠(원소가 하나일 때까지), recursive하게 merge를 진행 -> 하나의 배열을 정렬

static 변수 사용: 프로그램 실행 전체에서 유지해야 할 변수가 있을 때 사용
1. 지역, 전역 변수에 모두 사용 가능.
2. 선언된 함수 내에서만 사용 가능. ex) static void merge_sort(){}
3. 지역변수로, 전역변수로 선언해도, 함수와 관계 없이 계속 유지된다.

merge sort 아이디어: 하나의 배열을 받아. 재귀적 실행을 통해 원소가 2개 남을 때까지 분리. (left < right)의 조건을 붙여.
두 원소부터 left...center 절반을 buff배열에 저장 / center...right 절반을 a 배열에 남겨둠. buff와 a에 대해 merge를 진행.
buff와 a의 대소관계를 비교하고,
result = left; a[result++]에 두 배열을 병합하며 정렬/*/
#include <stdio.h>
#include <stdlib.h>

static int* buff;

static void merge_sort(int a[], int left, int right) {


	if (left < right) {  

		int center = (left + right) / 2;
		int temp = 0;
		int i;
		int j = 0; int result = left;


		merge_sort(a, left, center);        //center 변수를 통해 recursive하게 거듭 나눔. 최종적으로 1개의 원소부터 병합하게 된다.
		merge_sort(a, center + 1, right);

		for (i = left; i <= center; i++)
			buff[temp++] = a[i];              //buff에 a[0]부터 a[center]까지 저장. 현재 i == center;


		//i == center부터 출발하여 a[i]는 결국 a[center]...a[right]를 가리킴.
		//buff[0]...buff[center]와 a[center]...a[right]를 조건연산자로 비교하여, 더 작은 값을 a[result++]에 최종 저장
		while (i <= right && j < temp)        
			a[result++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];

		while (j < temp)        //바로 위의 while문에서, 
			a[result++] = buff[j++];

	}

}

//recursive 함수 내에서 buff의 공간을 할당하면, malloc이 쓸 데 없이 여러 차례 실행되기 때문에,
//이렇게 별도로 공간 확보를 위한 함수를 썼다.
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

	printf("원소의 수: ");
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