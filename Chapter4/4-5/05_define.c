/*
## 4.5 기호적 상수와 전처리기 #define
*/

// 원의 넓이, 원 둘레 구하기

#include <stdio.h>

int main() {

	float radius, area, circum;

	printf("Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * 3.141592f * radius; // circum = 2.0 * pi * r

	// sphere area, sphere volume, ....

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}


/*********************************************************
*********************************************************/


// 원 공식 만들 때 pi를 사람이 계속 입력하면 실수가 나오기 쉽다.
// 그래서 PI를 기호적 상수로 미리 정의해서 쓰자.

#include <stdio.h>
#define PI 3.141592f

int main() {

	float radius, area, circum;

	printf("Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}


/*********************************************************
*********************************************************/


// 문자열도 define해보자(AI 이름)

#include <stdio.h>
#define PI 3.141592f
#define AI_NAME "Jarvis" // 언제든 편리하게 수정 가능

int main() {

	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}
