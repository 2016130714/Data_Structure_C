/*�ڷᱸ��: ���ϴ� ��ŭ �����͸� �����ϰ� �Է��ϴµ�,
����Ǵ� �� �ֱ��� MAX��.
���̵��: �Է��� ��: �ε����� input++ % MAX�� ����. �� ���� ���� MAX�� ���� �� ����.
�̶� �ָ��� ���� input++ % MAX�� ���� MAX�� ���� �� ������, input�� ���� ��� �����Ǿ� ����� ���� �� �ִٴ� ��.
input�� �� �״�� �Է��� ������ ����.

�ٽ� ���̵��: i = input - MAX; if(i<0) i = 0;

�Է��� ������ ����: input
�� ��° �Է��� �����ΰ�?: i + 1���� input���� ���
�ش�(�����ִ�) ����?: buffer[i % MAX] ���*/

#include <stdio.h>

#define MAX 10

int main(void) {

	int retry;
	int buffer[MAX];
	int input = 0, i;


	printf("������ �Է��ϼ���.\n");

	do {
		printf("%d��° ����: ", input + 1);
		scanf("%d", &buffer[input++ % MAX]);

		printf("����ұ��?[Yes: (1) / No: (0)]: ");
		scanf("%d", &retry);


	} while (retry == 1);

	//input++ % MAX�� ���Ʊ� ������, input++ % MAX ��ü�� ���� MAX�� �ʰ��� �� ������,
	//input�� �󸶵��� �ʰ��� �� �ִ�.
	i = input - MAX;

	//MAX���� ���� �Է��ߴٸ�, i�� �ٽ� 0���� �ʱ�ȭ
	if (i < 0)
		i = 0;

	
	for (; i < input; i++) {
		printf("%d��° ����: %d\n", i + 1, buffer[i % MAX]);
	}
	//������ �� ��° �Է����� �˷���, i�� �ƴ϶�, i+1���� ��ȸ�ؾ� �Ѵ�.
	//������ buffer[0 == input]���� �ϴµ�, "�� °"�� 1 == input + 1���� ���� ������


	return 0;
}
