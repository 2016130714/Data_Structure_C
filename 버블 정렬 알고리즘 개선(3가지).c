/*정렬: 데이터의 대소 관계에 따라 일정한 순서로 바꾸는 작업
정렬 알고리즘의 핵심: 교환, 선택, 삽입

버블 정렬: 이웃한 두 원소의 대소관계를 비교하여 교환을 반복하는 알고리즘.
pass: 버블 정렬에서 배열의 가장 뒤 두 원소부터 비교, 교환하는 일련의 작업.
첫 번째 패스는 n-1, 두 번째는 n-2, 세 번째는 n-3의 복잡도.
패스를 k회 하면, k개의 요소가 정렬됨.
n개의 요소를 정렬하려면 (n-1)+(n-2)+...+(n-n)의 복잡도.

코딩 아이디어: 중첩 반복문
for(i = 0; i < n; i++)               -> i는 array[0]부터 정렬이 완료된 원소를 관리.
	for(j = n - 1; j < i; j--)       -> j는 array[n-1]부터 뒤 두 개의 원소를 비교하며 정렬*/

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


//개선된 버블 정렬: k번째 패스에서 교환이 한 번도 일어나지 않는다면, 정렬이 끝났다는 의미다.
//마지막 패스까지 도달하기 전에, 교환이 일어나지 않는 패스를 찾는다면, 시간을 절약할 수 있다.
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
		if (exchange == 0) break;         //이것이 성립하는 pass는 swap이 한 번도 없었다는 의미.
	} 
}


/*아이디어를 꼭 다시 고민해보자
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

	puts("버블 정렬\n");
	printf("요소 개수: ");
	scanf("%d", &n);

	array = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	printf("오름차순으로 정렬했습니다.\n");
	bubble_2(array, n);

	for (i = 0; i < n; i++) {
		printf("x[%d] = %d\n", i, array[i]);
	}
		
}