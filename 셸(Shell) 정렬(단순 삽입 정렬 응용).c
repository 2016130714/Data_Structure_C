/*단순 삽입 정렬: 두 번째 원소부터 시작. 왼쪽 원소가 해당 원소보다 크면 왼쪽 원소를 해당 자리에 대입.
더 작으면, 해당 원소를 대입.
둘 다 안됐을 경우, 왼쪽 끝에 다다르면 array[0]에 해당 원소 대입.
array[1] 삽입->array[2] 삽입->.....array[n - 1] 삽입

셸 정렬: 단순 삽입 정렬의 장점을 수용, 단점을 보완. 그룹별로 단순 삽입 정렬을 적용, 그룹을 합치면서, 전체적인 이동 횟수를 줄임.
아이디어: n개의 원소를 가진 배열을 n/2정렬, n/4정렬, n/8정렬...한다.
ex) 원소의 수가 8개일 때
1) 4-정렬: 배열을 4개의 그룹으로 나눠 정렬 G1: [0], [4] [8].... G2: [1], [5] [9]... G3: [2] [6] [10]... G4: [3] [7] [11]...
2) 2-정렬: 2개의 그룹으로 나눔. G1: [0] [2] [4] [6] [8] .... G2:[1] [3] [5] [7] [9] ...
3) 1-정렬: 전체에 대해 정렬.
4-2-1 각각의 그룹 내에서 단순 삽입 정렬을 적용하면 전반적인 이동 횟수가 줄어든다.

셸 정렬에서 좋은 증분값(h)의 요건: 그룹의 수를 줄일 때, 그룹들이 섞여야 한다.
그러나, 위와 같이 증분값을 배수로 설정하면, 전혀 섞이지 않는다.
해결법: 3h + 1의 수열로 증분값 설정(121, 40, 13, 4, 1)*/

#include <stdio.h>
#include <stdlib.h>


/*핵심 아이디어: for(j = i; j >= 0 && array[j] > ins; j--)
나의 실수: for(j = i; j >= 0; j--) {
				if(array[j] > ins) array[j+1] = array[j];

문제점: 내 방식처럼 for 구문에 조건연산자를 넣지 않고 if문으로 빼버리면, 조건이 거짓일 경우, if문 이하만 수행하지 않고,
반복문은 그냥 진행된다. 따라서 if 참거짓에 관계없이 항상 j == 0이므로 무조건 array[1]에만 1을 넣는 꼴이다.*/
void insertion(int array[], int n) {

	int i, j;
	for (i = 0; i < n; i++) {
		int ins = array[i];
		for (j = i - 1; j >= 0 && array[j] > ins; j--)
			array[j + 1] = array[j];

		array[j + 1] = ins;
	}
}



//내 방식을 쓰려면 else break;를 통해 반복문을 끝내주면 가능하다.
//반복문 내의 명령은 j == 0일 때 마지막으로 수행. 그러나 그 이후 j--를 한 번 더 하기 때문에, 최종 j == -1
//따라서 array[j + 1] = ins를 해주는 것. array[j]가 아니라.
void insertion_2(int array[], int n) {

	int i, j;            //i로 삽입할(정렬할 원소 선택), j로 왼쪽 원소 선택.
	for (i = 1; i < n; i++) {
		int ins = array[i];
		for (j = i - 1; j >= 0; j--) {
			if (array[j] > ins)
				array[j + 1] = array[j];
			else
				break;
		}
		array[j + 1] = ins;

	}


}




/*h: 그룹을 나누는 반복문.(처음엔 2그룹, 4그룹, 8그룹...으로 나눈다.)

i: 단순 삽입 정렬의 선택 원소 temp 선택. i = h부터 시작하기에 각 그룹의 두 번째 원소부터 선택한다.
a[h]->a[h+1]->a[h+2]...의 순서로 선택된다. +1씩만 증가되기 때문에 처음엔 1그룹 정렬, 그 다음 2그룹, 3그룹 이런 식으로 
그룹을 넘나들며 정렬함.

j: 선택된 temp의 왼쪽 원소를 전부 스캔. j -= h를 통해 같은 그룹 내 왼쪽 원소를 전부 스캔함.*/
void shell(int array[], int n) {

	int i, j, h;
	for (h = n / 2; h >= 1; h /= 2) {
		for (i = h; i < n; i++) {
			int temp = array[i];
			for (j = i - h; j >= 0 && array[j] > temp; j -= h) 
				array[j + h] = array[j];
			
			array[j + h] = temp;  //반복문을 나오면 실행 때보다 j -= h를 한 번 더 실행한 것이기에, j + h를 해줌.
		}
	}
}


//증분값을 3h + 1로 설정한 셸 정렬
//장점: 그룹을 섞이게 할 수 있다. 복잡도가 O(n^1.25)까지 낮아진다.
//단점: 멀리 떨어진 요소를 교환하기에 안정적이진 않다.
void shell_2(int array[], int n) {

	int h, i, j;
	for (h = 1; h < n / 9; h = 3 * h + 1);  //h = ....121, 40, 13, 4, 1의 수열을 미리 생성

	for (; h > 0; h /= 3) {
		for (i = h; i < n; i++) {
			int temp = array[i];
			for (j = i - h; j >= 0 && array[j] > temp; j -= h)
				array[j + h] = array[j];
			array[j + h] = temp;
		}
	}



}



int main(void) {

	int* array, n;

	printf("단순 삽입 정렬\n");
	printf("원소의 수: ");

	scanf("%d", &n);
	array = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {

		printf("x[%d]: ", i);
		scanf("%d", array + i);
	}

	shell_2(array, n);
	printf("오름차순으로 정렬했습니다.\n");

	for (int i = 0; i < n; i++) 
		printf("x[%d]: %d\n", i, *(array + i));
	

}