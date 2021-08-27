#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int name_cmpr(const Person* a, const Person* b) {

	return strcmp(a->name, b->name);

}


int height_cmpr(const Person* a, const Person* b) {

	return a->height > b->height ? 1 : a->height < b->height ? -1 : 0;

}


int weight_cmpr(const Person* a, const Person* b) {

	return a->weight > b->weight ? -1 : a->weight < b->weight ? 1 : 0;
}


void Print_Person(const Person a[], int n) {

	for (int i = 0; i < n; i++)
		printf("%s %dcm %dkg\n", a[i].name, a[i].height, a[i].weight);

}



int main(void) {

	Person x[] = {
		{"sunmi", 170, 52},
		{"yoobin", 180, 70},
		{"sohee", 172, 63},
		{"jina", 165, 50},
	};
	
	int n = sizeof(x) / sizeof(x[0]);

	printf("정렬 전\n");
	Print_Person(x, n);


	qsort(x, n, sizeof(Person), name_cmpr);
	printf("\n이름 오름차순 정렬\n");
	Print_Person(x, n);


	qsort(x, n, sizeof(Person), weight_cmpr);
	printf("\n몸무게 내림차순 정렬\n");
	Print_Person(x, n);

}