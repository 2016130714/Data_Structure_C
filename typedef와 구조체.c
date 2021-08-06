/*typedef: 긴 이름의 자료형, 배열, 포인터와 같은 형식을 짧게 재정의하는 수단
typedef unsigned short int US;
US data         // unsigned short int data를 선언한 것과 같다.

typedef int MY_DATA[5];
MY_DATA *p           // int (*p)[5]를 선언한 것과 같다.
장점: 여러 함수에서 여러 번 선언된 변수의 자료형을 바꿀 때 효율적이다. 
typedef를 미리 써놨다면, 하나하나 바꾸지 않고 typedef 부분만 바꾸면 되기 때문.*/

/*배열: 같은 성질의 데이터를 그룹화. ex)나이 따로, 키 따로, 몸무게 따로...
구조체: 서로 다른 성질의 데이터를 그룹화. ex) 현준 씨의 나이+키+몸무게
단점: 다른 자료형과 달리 변수를 사용할 때마다 struct 이하를 붙여야 함.
해결법: typedef struct {...} person;과 같이 쓰면 person만 쓰면 됨.(간략화 가능)*/


#include <stdio.h>

typedef struct {
	char name[10];    //문자열 뒤에 공백이 필요, 한국어의 자모음 각각 하나의 입력.
	//3글자 이름 기준 10칸은 필요할 것.
	unsigned short int age;     //나이의 범위를 고려하여 메모리 절약        
	float height;
	float weight;
} Person;

int main(void) {
	Person data;       //구조체 선언 후 함수 내 지역변수로 별도 선언 필요

	printf("대상자의 정보를 입력하세요\n이름: ");
	scanf("%s", data.name);
	
	printf("나이: ");
	scanf("%hu", &data.age);
	//unsigned short int의 형식: %hu       unsigned int의 형식: %u

	printf("키: ");
	scanf("%f", &data.height);

	printf("몸무게: ");
	scanf("%f", &data.weight);

	printf("입력한 정보는 다음과 같습니다.\n");
	printf("%s, %d, %.1fcm, %.1fkg", data.name, data.age, data.height, data.weight);
	
}

