#include <stdio.h>
#include<malloc.h>

int main(void) {
	int limit = 0, count = 0, sum = 0;
	printf("입력하려는 숫자의 개수: ");
	scanf("%d", &limit);
	int* num_list = (int*)malloc(sizeof(int) * limit);

	while (count < limit) {
		printf("숫자를 입력 (9999 입력 시 종료): ");
		scanf("%d", &num_list[count]);
		if (num_list[count] == 9999) break;
		count++;
	}
	for (int i = 0; i < count; i++)
		sum += num_list[i];

	printf("result: %d", sum);
	free(num_list);   //꼭 습관으로 써줘야 한다!

}