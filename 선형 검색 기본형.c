/*검색의 원리: 데이터의 "일부"에 주목하여, 그것이 key 값과 일치하는지, 구간에 속하는지, 비슷한지 판단.
배열 검색, 선형 리스트 검색, 이진 검색 트리, 문자열 검색 등이 있다.
여기서는 배열에서 검색하기를 다룬다.

선형 검색(linear search): 직선 모양의 배열에서 key 값과 원소의 일치 여부를 따짐.
키 값과 같은 원소를 발견하면 검색 성공. 발견하지 못하고 배열의 끝에 도달하면 검색 실패.
즉 항상 검색 성공과 검색 실패 둘 다 생각해야 함.*/


#include <stdio.h>
#include <stdlib.h>


//검색 성공 시 인덱스 반환. 실패 시 -1을 반환한다.
int search(int key, int array[], int index) {

	for (int i = 0; i < index; i++) {

		if (array[i] == key)
			return i;
	}

	return -1;
}



int main(void) {
	int n, key;
	int* data;

	printf("선형 검색\n");
	printf("원소의 개수: ");
	scanf("%d", &n);

	data = (int*)calloc(n, sizeof(int));
	//배열의 크기를 정해놓는 게 아니라, 인덱스를 입력 받으므로, 입력 후 동적 할당 필수!


	for (int i = 0; i < n; i++) {

		printf("\nx[%d]: ", i);
		scanf("%d", data + i);
	}

	printf("\n찾으려는 키 값: ");
	scanf("%d", &key);

	printf("%d은(는) x[%d]에 있습니다.", key, search(key, data, n));

	free(data);
	return 0;
}