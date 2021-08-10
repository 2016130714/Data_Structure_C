#include <stdio.h>

typedef struct{
	char name[20];
	int height;
	double vision;
} Person;

#define VMAX 21        //�� ���� Dist_Vision �Լ��� main �Լ� �� �ٿ��� �� ���̹Ƿ� ���⼭ �����ߴ�.
//�÷��� �ִ�ġ 2.1�� Ȱ���ϱ� ���� ����.
//�̿� ���� ���� ����ϴ� ����� ��ó����� �����س��� ������ �ʿ��ϴ�.


double Avg_Height(const Person check[], int index) {
	double sum = 0; // ��ȯ���� double�� ���� �̸� double������ �����س��� �Ѵ�.

	for (int i = 0; i < index; i++) 
		sum += check[i].height;

	return sum / index;
}


//�÷��� ������ ���ϴ� �Լ�. ������ ����
void Dist_Vision(const Person check[], int index, int vdist[]) {
	//void�� �Լ��̹Ƿ�, �ݵ�� vdist�� �Ű������� �޾� ���� �ٲ�� �Ѵ�.

	/*for (int temp = 0; temp < VMAX; temp++) {

		for (int i = 0; i < index; i++) {

			if (check[i].vision <= temp / 10.0)
				vdist[temp]++;
		}
	}
			���� �̷��� �ߴµ�, �̷��� �ϸ� ������ ������ų ���ۿ� ����.
			������Ű�� �ʰ� ���Ϸ���, ������ â������ ���̵� �� ����ؾ� �Ѵ�.*/

	for (int i = 0; i < index; i++)
		vdist[(int)(check[i].vision * 10)]++;
	//�׳� �÷� �� * 10�� �״�� index�� Ȱ���ϴ� ���̵��!
		
	
}



int main(void) {
	
	//1�� == ����ü 1��
	// Person check[7]�� ���� �ο� ���� �´� ����ü �迭�� �����ؾ� �Ѵ�.
	Person check[7] = {
		{"������", 162, 0.3},
		{"������", 173, 0.7},
		{"������", 175, 2.0},
		{"ȫ����", 171, 1.5},
		{"�̼���", 168, 0.4},
		{"�迵��", 174, 1.2},
		{"�ڿ��", 169, 0.8}
	};

	int index = sizeof(check) / sizeof(check[0]);
	//�̷��� �ε����� ���ϸ�, �� ���� �Է��ϵ� ���� �ٲ� �ʿ䰡 ����!!. 
	//index = 7 �� ���¿� ���� ������ �����ϴ�.
	
	int i;

	printf("��ü �˻� ǥ\n");

	for (i = 0; i < index; i++)
		printf("%s %4d %5.1f\n", check[i].name, check[i].height, check[i].vision);

	printf("\nŰ�� ���: %.1f", Avg_Height(check, index));

	printf("\n\n�÷� ����\n");

	int vdist[VMAX] = { 0, };
	Dist_Vision(check, index, vdist);

	for (i = 0; i < VMAX; i++) {

		printf("%.1f �̻�: %d ��\n", i / 10.0, vdist[i]);
		//%f������ ����ϱ� ���� 10��� 10.0���� ������.
	}

	return 0;
}