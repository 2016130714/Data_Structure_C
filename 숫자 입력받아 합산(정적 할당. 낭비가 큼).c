#include <stdio.h>
#define MAX_COUNT 5

int main(void) {
	int num[MAX_COUNT], count = 0, sum = 0;

	while (count < MAX_COUNT) {
		//MAX_COUNT로 숫자 개수를 제한하기 위한 반복문
		printf("숫자를 입력(9999를 입력하면 종료): ");
		scanf("%d", &num[count]);
		if (num[count] == 9999) break;
		count++;
	
	}

	for (int i = 0; i < count; i++) 
		//i <= count로 쓰지 않게 주의
		sum += num[i];


	printf("result: %d", sum);

}



