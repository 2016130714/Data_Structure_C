/*merge: 정렬된 두 배열 a[na]와 b[nb]를 받아, 정렬된 c[na + nb]로 합치는 알고리즘.
a[pa]와 a[pb]를 비교하여, 더 작은 값을 c[pc]에 저장한다.
a, b 중 어느 한 쪽의 배열에 더 이상 비교할 원소가 없으면, 비교를 마치고 나머지를 c에 저장하면 된다.*/

#include <stdio.h>
#include <stdlib.h>


void merge(int a[], int b[], int na, int nb, int c[]) {

	int pa = 0; int pb = 0; int pc = 0;

	while (pa < na && pb < nb) {

		if (a[pa] >= b[pb]) {
			c[pc] = b[pb];
			pb++;
			pc++;
		}

		else if (a[pa] < b[pb]) {
			c[pc] = a[pa];
			pa++;
			pc++;
		}
	}
	while (pa < na) c[pc++] = a[pa++];

	while (pb < nb) c[pc++] = b[pb++];

}

//책에서 제시한 방법(조건 연산자를 써서 깔끔하다.)
void merge_2(int a[], int b[], int na, int nb, int c[]) {

	int pa = 0; int pb = 0; int pc = 0;

	while (pa < na && pb < nb)
		c[pc++] = (a[pa] >= b[pb]) ? b[pb++] : a[pa++];

	while (pa < na)
		c[pc++] = a[pa++];

	while (pb < nb)
		c[pc++] = b[pb++];
}


int main(void) {

	int* a, * b, *c, na, nb, i;

	printf("a의 원소의 수: ");
	scanf("%d", &na);
	printf("b의 원소의 수: ");
	scanf("%d", &nb);

	a = (int*)malloc(na * sizeof(int));
	b = (int*)malloc(nb * sizeof(int));
	c = (int*)malloc((na + nb) * sizeof(int));


	for (i = 0; i < na; i++) {

		printf("a[%d]: ", i);
		scanf("%d", a + i);
	}

	for (i = 0; i < nb; i++) {
		printf("b[%d]: ", i);
		scanf("%d", b + i);
	}

	merge(a, b, na, nb, c);
	printf("배열 a와 b를 병합하여 배열 c에 저장했습니다.\n");

	for (i = 0; i < (na + nb); i++)
		printf("c[%d]: %d\n", i, c[i]);
	


	free(a); free(b); free(c);
	return 0;
}