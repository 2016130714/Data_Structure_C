#include <stdio.h>
//배열의 이름 = 배열의 주소(포인터 변수)
// int a[10];에서 a는 배열의 주소; *a == a[0]; *(a+i) = a[i]
void main() {
	int array[10];
	int i, result;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &array[i]);  //scanf를 이렇게 for 구문 안에서 활용 가능
	//&array[i] == &(array+i)
	result = calculate_sum(array);
	printf("%d", result);
	return 0;
}

int calculate_sum(int* array) { //매개변수를 int array []으로 쓸 수도 있다. 
	int sum = 0, i;
	for (i = 0; i < 10; i++)
		sum = sum + array[i];
	return sum;
}