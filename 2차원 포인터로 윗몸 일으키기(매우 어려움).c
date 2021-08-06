#include<stdio.h>
#include<malloc.h>

int main(void) {
	int age, person, age_step, temp;
	int sum = 0;
	printf("20대부터 연령층이 몇 개인가요 :");
	scanf("%d", &age_step);
	unsigned char* p_limit_table = (unsigned char*)malloc(sizeof(unsigned char) * age_step);
	unsigned char** pp = (unsigned char**)malloc(sizeof(unsigned char*)*age_step); 
	//malloc의 형식을 정확히 맞춰야 한다. 특히 어디에 *이 오는지 정확히 파악!!

	for (age = 0; age < age_step; age++) {
		printf("\n%d0대의 윗몸 일으키기 횟수\n", age + 2);
		printf("이 연령대는 몇 명입니까? :");
		scanf("%d", &temp);
		
		*(p_limit_table + age) = (unsigned char)temp;
		*(pp + age) = (unsigned char*)malloc(sizeof(unsigned char) * temp);
		//위 코드 유의

		for (person = 0; person < *(p_limit_table+age); person++) {
			scanf("%d", &temp);
			
			*(*(pp + age) + person) = (unsigned char)temp;
			//위 코드 유의
		}
	}

	printf("\n연령별 평균");

	for (age = 0; age < age_step; age++) {
		printf("\n%d0대: ", age + 2);

		for (person = 0; person < *(p_limit_table + age); person++) 
			sum += *(*(pp + age) + person);

		printf("%5.2f", (double)sum / *(p_limit_table + age));

		sum = 0;
	}


}