/*stack�� push, pop������ �����ϴϱ�, �� �����غ��� ��.

���̵��: pivot�� �߽����� ������ �����ϴ� lstack, �������� �����ϴ� rstack ����.
1. lstack�� 0(�ʱ� left), rstack�� n - 1(�ʱ� right) push.
2. pl = left; pr = right�� �����Ͽ�, left, right�� ���� �ǵ��� �ʰ� pl, pr�� Ŀ���� �Ű� �� ���� ����.
(�̴� ����� �˰���� ������ ���̵��)
3. �� ��� pl, pr�� pivot ��ó�� ������ ��.

�ٽ� ���̵��
4. if(pr > left) Push(&rstack, pr) Push(&lstack, left)
if(pl < right) Push(&lstack, pl) Push(&rstack, right)
5. Push ���: lstack: {0, pl} rstack: {pr, right}

6. ��ü �ݺ����� ���� ���ư� Pop(&lstack), Pop(&rstack)�ϸ�, ���Լ��⿡ ���� lstack�� pl, rstack�� right�� ���� ���̴�.
7. ���� ���� ��������(pl -> right) ��, pivot�� �� ���� ���� �����ϰ�, �� �ڿ� left -> pr, pivot�� �� ���� ������ ���̴�.
8. �� if�� ������ ���� pivot�� ���� �Ǵ� pivot�� ������ ���� ������ ���̴�.(�Ʒ� �ڵ忡�� �������� ®��.)*/

#include <stdio.h>
#include "INTSTACK.h"
#include <stdlib.h>

#define swap(type, x, y) do {type temp = x; x = y; y = temp;} while(0)

void quick(int array[], int left, int right) {

	INTSTACK lstack;
	INTSTACK rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		Pop(&lstack, &left);
		Pop(&rstack, &right);
		int pl = left;
		int pr = right;
		int pivot = array[(pl + pr) / 2];
		
		while (pl <= pr) {

			while (array[pl] < pivot) pl++;
			while (array[pr] > pivot) pr--;

			if (pl <= pr) {
				swap(int, array[pl], array[pr]);
				
				pl++;
				pr--;
			}

			if (right > pl) {
				Push(&rstack, right);
				Push(&lstack, pl);
			}

			if (left < pr) {
				Push(&lstack, left);
				Push(&rstack, pr);
			}

		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}


int main(void) {

	int* array, n, i;

	printf("������� �� ����\n");
	printf("������ ��: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("������������ �����߽��ϴ�.\n");

	quick(array, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("x[%d]: %d\n", i, array[i]);

	return 0;
}