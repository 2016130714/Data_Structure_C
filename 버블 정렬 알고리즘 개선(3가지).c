/*����: �������� ��� ���迡 ���� ������ ������ �ٲٴ� �۾�
���� �˰����� �ٽ�: ��ȯ, ����, ����

���� ����: �̿��� �� ������ ��Ұ��踦 ���Ͽ� ��ȯ�� �ݺ��ϴ� �˰���.
pass: ���� ���Ŀ��� �迭�� ���� �� �� ���Һ��� ��, ��ȯ�ϴ� �Ϸ��� �۾�.
ù ��° �н��� n-1, �� ��°�� n-2, �� ��°�� n-3�� ���⵵.
�н��� kȸ �ϸ�, k���� ��Ұ� ���ĵ�.
n���� ��Ҹ� �����Ϸ��� (n-1)+(n-2)+...+(n-n)�� ���⵵.

�ڵ� ���̵��: ��ø �ݺ���
for(i = 0; i < n; i++)               -> i�� array[0]���� ������ �Ϸ�� ���Ҹ� ����.
	for(j = n - 1; j < i; j--)       -> j�� array[n-1]���� �� �� ���� ���Ҹ� ���ϸ� ����*/

#include <stdio.h>

#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)


void bubble(int array[], int n) {

	for (int i = 0; i < n; i++) {
		
		for (int j = n - 1; j > i; j--) {
			
			if (array[j - 1] > array[j])				
				swap(int, array[j - 1], array[j]);
		}
	}
}


//������ ���� ����: k��° �н����� ��ȯ�� �� ���� �Ͼ�� �ʴ´ٸ�, ������ �����ٴ� �ǹ̴�.
//������ �н����� �����ϱ� ����, ��ȯ�� �Ͼ�� �ʴ� �н��� ã�´ٸ�, �ð��� ������ �� �ִ�.
void bubble_2(int array[], int n) {

	int i, j;

	for (i = 0; i < n; i++) {
		int exchange = 0;
		for (j = n - 1; j > i; j--) {
			if (array[j - 1] > array[j]) {
				swap(int, array[j - 1], array[j]);
				exchange++;
			}
		}
		if (exchange == 0) break;         //�̰��� �����ϴ� pass�� swap�� �� ���� �����ٴ� �ǹ�.
	} 
}


/*���̵� �� �ٽ� ����غ���
void bubble_3(int array[], int n) {

	
	int k = 0;
	while (k < n - 1) {
		int j;
		int last = n - 1;

		for (j = n - 1; j > k; j--) 
			if (array[j - 1] > array[j]) {
				swap(int, array[j = 1], array[j]);
				last = j;
			}
		k = last;
	}
}
*/


int main(void) {

	int* array, n, i;

	puts("���� ����\n");
	printf("��� ����: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("������������ �����߽��ϴ�.\n");
	bubble_2(array, n);

	for (i = 0; i < n; i++) {
		printf("x[%d] = %d\n", i, array[i]);
	}
		
}