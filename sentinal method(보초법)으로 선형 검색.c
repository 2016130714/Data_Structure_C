/*보초법: 종결 조건의 검사 비용을 줄이는 방법
아이디어: 미리 key 값을 배열의 가장 끝에 추가 해놓는다.
즉, 원소의 수 + 1의 배열을 생성한다.
키 값이 끝 값이면 -1 출력. 끝 값이 아니면 해당 인덱스를 출력한다.*/

#include <stdio.h>
#include <stdlib.h>

//보초법 선형 검색 함수
int search(int key, int array[], int index) {

	int i = 0;

	array[index] = key;   //보초 추가(배열의 끝에 key 값을 미리 추가)

	while (1) {
		
		if (array[i] == key)
			break;
		
		i++;
	}

	return i == index ? -1 : i;
	/*return 문에 조건 연산자를 활용한 문법. (조건식) ? x : y;
	조건식이 참이면 x를 출력, 거짓이면 y를 출력.

	즉, 검색 결과가 맨 끝이면 검색 실패의 -1을 반환. 그렇지 않으면 검색 결과의 인덱스를 반환.*/
	
}


int main(void) {
	int n, *data, key;

	printf("선형 검색(보초법, sentinal method)\n");
	printf("원소의 수: ");
	scanf("%d", &n);

	data = (int*)calloc(n + 1, sizeof(int));
	//동적 할당 시, index+1 크기의 배열 생성

	for (int i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", data + i);
	}

	printf("검색 값:");
	scanf("%d", &key);
	
	int result = search(key, data, n);

	if (result == -1)
		printf("검색에 실패했습니다.");
	
	else
		printf("%d는 x[%d]에 있습니다.", key, search(key, data, n));

	free(data);
	return 0;
}