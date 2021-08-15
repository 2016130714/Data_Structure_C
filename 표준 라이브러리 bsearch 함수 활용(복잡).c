/*bsearch 함수: 이진 탐색 함수
헤더: #include <stdlib.h>

형식: void *bsearch(&key, array, index, sizeof(자료형), compare함수)  -> 5개의 인수를 받는다.
이때 compare함수는 직접 작성해야 함. 이번에는 단순한 int간 비교라 간단한데,
이 함수로 문자열, 구조체 등 더 복잡한 것들을 비교할 수도 있기 때문에, 직접 작성 필요.

compare 함수의 규칙: int (*compar) (const void *, const void *)가 기본 형식.
즉, int형을 return하고, const 인수 두 개(비교 대상 두 개)를 받는 함수 포인터.
void *형이기 때문에, 사용 시 매개변수의 형변환이 꼭 필요하다. (임의의 포인터)

이때 return하는 int 형은, 
if(a < b) return -1;    (오른쪽이 크면 -1 반환.)
if(a == b) return 0;
if(a > b) return 1;     (왼쪽이 크면 1 반환.)
으로 외워둬야 한다.

반환 값(성공): 해당되는 원소의 포인터(주소). 해당 원소의 포인터 - 배열의 포인터를 하면 index를 구할 수 있다.
즉, int (search - array).
반환값이 포인터형이기 때문에, 처음 bsearch의 결과를 저장하는 변수 역시 포인터로 선언해야 한다(int *search)*/

#include<stdio.h>
#include<stdlib.h>

int int_cmp(const int *a, const int *b) {
	
	return *a < *b ? -1 : *a > *b ? 1 : 0;
	//조건 연산자 활용.
}


int main(void) {

	int n, *array, key, *search;

	printf("bsearch 함수를 사용한 이진 탐색\n");
	printf("원소의 수: ");

	scanf("%d", &n);
	array = (int*)calloc(n, sizeof(int));

	printf("오름차순으로 입력하세요.\n");

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("검색 값: ");
	scanf("%d", &key);

	search = bsearch(&key, array, n, sizeof(int), (int(*)(const void*, const void*))int_cmp);
	//bsearch의 결과: 해당 원소의 포인터. 
	//함수 포인터에 void 포인터가 사용되어 이를 int *로 형변환했다.

	printf("%d는 x[%d]에 있습니다.",key, search - array);
	//여기서 *search를 쓰면 해당 원소의 값(key)이 나오므로 부적절.
	//search - array로 배열의 시작 주소를 빼면, 인덱스가 나온다.
	

	free(array);
	return 0;
}