#include <stdio.h>

typedef struct{
	char name[20];
	int height;
	double vision;
} Person;

#define VMAX 21        //이 값은 Dist_Vision 함수와 main 함수 둘 다에서 쓸 것이므로 여기서 선언했다.
//시력의 최대치 2.1을 활용하기 위해 선언.
//이와 같이 많이 사용하는 상수는 전처리기로 선언해놓는 센스가 필요하다.


double Avg_Height(const Person check[], int index) {
	double sum = 0; // 반환형인 double에 맞춰 미리 double형으로 선언해놔야 한다.

	for (int i = 0; i < index; i++) 
		sum += check[i].height;

	return sum / index;
}


//시력의 분포를 구하는 함수. 유심히 보자
void Dist_Vision(const Person check[], int index, int vdist[]) {
	//void형 함수이므로, 반드시 vdist를 매개변수로 받아 값을 바꿔야 한다.

	/*for (int temp = 0; temp < VMAX; temp++) {

		for (int i = 0; i < index; i++) {

			if (check[i].vision <= temp / 10.0)
				vdist[temp]++;
		}
	}
			나는 이렇게 했는데, 이렇게 하면 분포를 누적시킬 수밖에 없다.
			누적시키지 않고 구하려면, 다음의 창의적인 아이디어를 꼭 기억해야 한다.*/

	for (int i = 0; i < index; i++)
		vdist[(int)(check[i].vision * 10)]++;
	//그냥 시력 값 * 10을 그대로 index로 활용하는 아이디어!
		
	
}



int main(void) {
	
	//1명 == 구조체 1개
	// Person check[7]과 같이 인원 수에 맞는 구조체 배열을 선언해야 한다.
	Person check[7] = {
		{"박현규", 162, 0.3},
		{"함진아", 173, 0.7},
		{"최윤미", 175, 2.0},
		{"홍연의", 171, 1.5},
		{"이수진", 168, 0.4},
		{"김영준", 174, 1.2},
		{"박용규", 169, 0.8}
	};

	int index = sizeof(check) / sizeof(check[0]);
	//이렇게 인덱스를 구하면, 몇 명을 입력하든 값을 바꿀 필요가 없다!!. 
	//index = 7 이 형태에 비해 수정이 용이하다.
	
	int i;

	printf("신체 검사 표\n");

	for (i = 0; i < index; i++)
		printf("%s %4d %5.1f\n", check[i].name, check[i].height, check[i].vision);

	printf("\n키의 평균: %.1f", Avg_Height(check, index));

	printf("\n\n시력 분포\n");

	int vdist[VMAX] = { 0, };
	Dist_Vision(check, index, vdist);

	for (i = 0; i < VMAX; i++) {

		printf("%.1f 이상: %d 명\n", i / 10.0, vdist[i]);
		//%f형으로 출력하기 위해 10대신 10.0으로 나눴다.
	}

	return 0;
}