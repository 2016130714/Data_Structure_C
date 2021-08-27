/*merge: ���ĵ� �� �迭 a[na]�� b[nb]�� �޾�, ���ĵ� c[na + nb]�� ��ġ�� �˰���.
a[pa]�� a[pb]�� ���Ͽ�, �� ���� ���� c[pc]�� �����Ѵ�.
a, b �� ��� �� ���� �迭�� �� �̻� ���� ���Ұ� ������, �񱳸� ��ġ�� �������� c�� �����ϸ� �ȴ�.*/

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

//å���� ������ ���(���� �����ڸ� �Ἥ ����ϴ�.)
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

	printf("a�� ������ ��: ");
	scanf("%d", &na);
	printf("b�� ������ ��: ");
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
	printf("�迭 a�� b�� �����Ͽ� �迭 c�� �����߽��ϴ�.\n");

	for (i = 0; i < (na + nb); i++)
		printf("c[%d]: %d\n", i, c[i]);
	


	free(a); free(b); free(c);
	return 0;
}