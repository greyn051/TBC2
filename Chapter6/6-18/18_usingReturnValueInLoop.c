/*
## 6.18 루프 안에서 함수의 반환값 사용하기
*/

// 제곱 구하는 프로그램 같이 구현

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // 제곱 구해주는 프로그램
    // 3 4 입력하면
    // 3*3*3\*3 = 81 이런식으로 나오게

    int base, exp, i, result;
    scanf("%d %d", &base, &exp);

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    printf("Result = %d\n", result);

    return 0;
}


/*********************************************************
*********************************************************/


// + 입력 반복하는 것도 구현

int main() {
    // 제곱 구해주는 프로그램
    // 3 4 입력하면
    // 3*3*3\*3 = 81 이런식으로 나오게

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {
    	result = 1;
    	for (i = 0; i < exp; ++i)
    		result *= base;

    	printf("Result = %d\n", result);
    }

    return 0;
}


/*********************************************************
*********************************************************/


// 위 루프 안의 코드를 함수로 만들어서 빼고 다시 받아오자.

// ⭐ 영역(scope)라는 개념 나온다.

/*
main에서 정의된 변수들은함수에서 바로 쓸 수 없다.
함수에서 별도로 정의를 해 줘야 한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp) {

    int i, result;

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    return result; // 계산 결과 반환
}

int main() {

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {

    	result = compute_pow(base, exp); // 함수의 return 값이 변수에 대입되어 저장된다.

    	printf("Result = %d\n", result);
    }

    return 0;
}


/*********************************************************
*********************************************************/


// 함수의 prototype

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp); // prototype (이런 함수가 있다고 알려줌)

int main() {

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {

    	result = compute_pow(base, exp); // 함수의 return 값이 변수에 대입되어 저장된다.

    	printf("Result = %d\n", result);
    }

    return 0;
}

int compute_pow(int base, int exp) {

    int i, result;

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    return result; // 계산 결과 반환
}
