/*도수 정렬: 대소 관계 비교 없이 빠르게 정렬할 수 있는 알고리즘. 다만 누적 도수분포표를 준비해야 함.

과정: 1. 도수분포표 만들기: 정렬하고자 하는 배열 a에서 값의 분포가 0부터 10까지라고 하면,
크기가 11인 배열 f를 만든다.(f[0]...f[10])
f[n] = 값이 n인 원소의 수다. 즉 f[9] = 1이면, 값이 9인 원소가 하나 있다는 것.
2. 누적 도수분포표: f에서, 인원 수를 누적한다.
예를 들어, 도수분포표에서 f[0] = 2; f[1] = 3 이라면, 누적 도수분포표에서는 f[1] = 2 + 3 = 5로 한다.

3. a를 정렬하여 또 다른 배열 b에 저장한다. 
a[n - 1]부터 값을 f와 비교한다. a [n - 1] = x일 때, 
f[x]는 0부터 x점인 사람이 몇 명인지 보여준다. f[x]는 x점까지의 누적 인원을 나타냄.
b[f[x] - 1]은 b[0]부터 시작하는 정렬 배열에서 x가 위치해야 하는 자리다! 앞에 f[x]명이 존재해야 하므로.

이중 for문 없이 단일 for문으로만 구성되어 매우 빠르다. 다만 도수분포표가 필요하기에, 최솟값과 최댓값이 필요함.*/

#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max) {

	int* f = calloc(max + 1, sizeof(int));   //max점까지 저장할 f[max]까지 필요하므로, max + 1 크기의 공간 할당
	int* b = (int *)calloc(n, sizeof(int));
	int i;

	for (i = 0; i <= max; i++) f[i] = 0;   //도수분포표 초기화 필수

	for (i = 0; i < n; i++) f[a[i]]++;   //도수분포표 만들기

	for (i = 1; i <= max; i++) f[i] += f[i - 1];  //누적 도수 분포표 만들기 -> 여기서 i = 1부터 시작함에 유의!!!

	for (i = n - 1; i >= 0; i--) b[f[a[i]] - 1] = a[i];   //a[i]는 각 사람의 점수. f[a[i]]는 그 점수까지 누적 몇 명인지 나타냄.
	//b[f[a[i]] - 1]은 해당 점수가 몇 번째 원소로 와야할지 나타냄.(앞에 f[a[i]]명이 있으므로)

	for (i = 0; i < n; i++) a[i] = b[i];        //정렬된 배열 b의 요소를 그대로 a로 옮긴다.

	free(b);
	free(f);
}


int main(void) {

	int* a, n, i;

	int max = 100;

	printf("도수 정렬\n");
	printf("원소의 수: ");
	scanf("%d", &n);

	a = (int*)malloc(n * sizeof(int));

	printf("0부터 %d 사이의 정수만 입력하세요\n", max);

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", a + i);
	}

	fsort(a, n, max);
	printf("fsort completed\n");

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, a[i]);

	free(a);

	return 0;
}