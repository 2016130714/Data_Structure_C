#include<stdio.h>
#include<malloc.h>

int main(void) {
	int age, person, age_step, temp;
	int sum = 0;
	printf("20����� �������� �� ���ΰ��� :");
	scanf("%d", &age_step);
	unsigned char* p_limit_table = (unsigned char*)malloc(sizeof(unsigned char) * age_step);
	unsigned char** pp = (unsigned char**)malloc(sizeof(unsigned char*)*age_step); 
	//malloc�� ������ ��Ȯ�� ����� �Ѵ�. Ư�� ��� *�� ������ ��Ȯ�� �ľ�!!

	for (age = 0; age < age_step; age++) {
		printf("\n%d0���� ���� ����Ű�� Ƚ��\n", age + 2);
		printf("�� ���ɴ�� �� ���Դϱ�? :");
		scanf("%d", &temp);
		
		*(p_limit_table + age) = (unsigned char)temp;
		*(pp + age) = (unsigned char*)malloc(sizeof(unsigned char) * temp);
		//�� �ڵ� ����

		for (person = 0; person < *(p_limit_table+age); person++) {
			scanf("%d", &temp);
			
			*(*(pp + age) + person) = (unsigned char)temp;
			//�� �ڵ� ����
		}
	}

	printf("\n���ɺ� ���");

	for (age = 0; age < age_step; age++) {
		printf("\n%d0��: ", age + 2);

		for (person = 0; person < *(p_limit_table + age); person++) 
			sum += *(*(pp + age) + person);

		printf("%5.2f", (double)sum / *(p_limit_table + age));

		sum = 0;
	}


}