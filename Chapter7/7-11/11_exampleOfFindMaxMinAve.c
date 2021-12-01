/*
## 7.11 최대, 최소, 평균 구하기 예제
*/

// 여러 값 입력 받고 그 중에서 가장 작은수, 큰 수 그리고 전체 평균을 출력하는 프로그램

// ※ 내 코드
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>

int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {
    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	//TODO: ignore negative values

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;
}

// ※ 교수님 코드 = 내 코드


/*********************************************************
*********************************************************/


// 음수 무시, 100 이하 값만 받기

// ※ 내 코드
int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {

    	//TODO: ignore negative values and accept value below 100.
    	if (input < 0)
    		continue;
    	else if (input > 100)
    		continue;

    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;
}

// ※ 교수님 코드
int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {

    	if (input < 0.0f || input > 100.0f) continue;

    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;
}
