/*c언어에서 두 문자열을 관계연산자로 비교할 수 없다. 
즉, "abc" == "abc"와 같은 비교가 불가능. 문자열이 저장된 주소가 다르기 때문.

해결법: strcmp(string compare)함수 사용.
헤더: #include<string.h>
원형: int strcmp(const char *str1, const char *str2)
반환값: 사전 순서를 따진다.
사전 순서가 str1 < str2면 -1, str1 == str2면 0, str1 > str2면 1 반환.
즉, 반환하는 구조가 bsearch의 int(*compar)이 요구하는 형태와 동일하다.
strcmp, bsearch를 활용하여 문자열의 이진탐색이 가능하다.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int str_cmpr(const Person* a, const Person* b) {
	return strcmp(a->name, b->name);
	//구조체 배열 (*a).name 대신에 a->name을 활용하자.
}


int main(void) {

	Person list[] = {
		{"김영준", 179, 79},
		{"박현규", 172, 63},
		{"이수진", 176, 52},
		{"최윤미", 165, 51},
		{"함진아", 181, 73},
		{"홍연의", 172, 84}
	};
	
	Person temp; // target data인 Person list와 별개로, 입력 데이터 등을 받고 활용하기 위해
	//별도의 구조체 Person temp를 선언.

	int index = sizeof(list) / sizeof(list[0]); // 구조체 인덱싱 꼭 기억!

	Person* result; // bsearch의 결과를 저장하기 위한 변수. bsearch는 결과로 해당 포인터를 반환한다.
	//구조체로 이진 탐색하므로, 구조체의 포인터를 반환할 것. 그래서 Person형 포인터 선언.

	int retry; //재검색 여부를 판별하기 위한 변수


	
	//bsearch 성공/실패로 분류. 교재 126쪽처럼 나오려면 while을 후에 적용하는 do while문을 쓸 수밖에 없다.
	//성공, 실패에 관계 없이 "다시 검색할까요?" 출력.
	do {

		printf("이름으로 검색합니다.\n이름: ");

		scanf("%s", &temp.name);
		result = bsearch(&temp.name, list, index, sizeof(Person), str_cmpr);

		if (result != NULL) {
			printf("검색 성공!! 아래 요소를 찾았습니다.\n");
			printf("list[%d]: %s %4dcm %3dkg\n", result - list, result->name, result->height, result->weight);
		}
		
		else
			printf("검색에 실패했습니다");

		printf("다시 검색할까요? (1) 예 / (0) 아니오 : ");
		scanf("%d", &retry);       //이렇게 다시 검색 여부를 0과 1로 입력 받고, do while문을 통해 재검색 기능 구현.
	} while (retry == 1);
}