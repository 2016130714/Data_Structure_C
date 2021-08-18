/*자료구조: 원하는 만큼 데이터를 무한하게 입력하는데,
저장되는 건 최근의 MAX개.
아이디어: 입력할 때: 인덱스를 input++ % MAX로 설정. 이 값은 절대 MAX를 넘을 수 없다.
이때 주목할 점은 input++ % MAX의 값은 MAX를 넘을 수 없지만, input의 값은 계속 누적되어 충분히 넘을 수 있다는 것.
input은 말 그대로 입력한 원소의 수다.

핵심 아이디어: i = input - MAX; if(i<0) i = 0;

입력한 숫자의 개수: input
몇 번째 입력한 정수인가?: i + 1부터 input까지 출력
해당(남아있는) 값은?: buffer[i % MAX] 출력*/

#include <stdio.h>

#define MAX 10

int main(void) {

	int retry;
	int buffer[MAX];
	int input = 0, i;


	printf("정수를 입력하세요.\n");

	do {
		printf("%d번째 정수: ", input + 1);
		scanf("%d", &buffer[input++ % MAX]);

		printf("계속할까요?[Yes: (1) / No: (0)]: ");
		scanf("%d", &retry);


	} while (retry == 1);

	//input++ % MAX를 거쳤기 때문에, input++ % MAX 자체의 값은 MAX를 초과할 수 없으나,
	//input은 얼마든지 초과할 수 있다.
	i = input - MAX;

	//MAX보다 적게 입력했다면, i를 다시 0으로 초기화
	if (i < 0)
		i = 0;

	
	for (; i < input; i++) {
		printf("%d번째 정수: %d\n", i + 1, buffer[i % MAX]);
	}
	//정수가 몇 번째 입력인지 알려면, i가 아니라, i+1부터 조회해야 한다.
	//저장은 buffer[0 == input]부터 하는데, "번 째"는 1 == input + 1부터 세기 때문에


	return 0;
}
