/*
## 5.4 곱하기 연산자
*/

//### 복리 계산 프로그램 만들기
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
double seed_money, target_money, annual_interest;

    printf("Input seed money : ");
    scanf("%lf", &seed_money);

    printf("Input target money : ");
    scanf("%lf", &target_money);

    printf("Input annual interest (%%) : ");
    scanf("%lf", &annual_interest);

    double fund = seed_money;
    int year_count = 0;

    while (fund < target_money) {
    	fund = fund * (1 + annual_interest / 100.0);
    	// fund += fund * annual_interest / 100.0; // 코드 줄이고 싶을 때
    	year_count = year_count + 1;
    	// year_count += 1; // 코드 줄이고 싶을 때
    	// year_count++; // C에서만 이렇게 더 줄일 수 있다(증가연산자)

    	printf("Year %d, fund %f\n", year_count, fund);
    }

    printf("It takes %d years\n", year_count);

    return 0;
}
