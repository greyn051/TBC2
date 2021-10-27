/*
## 5.5 나누기 연산자
*/

#include <stdio.h>

int main() {
    printf("Integer divisions\n");
    printf("%d\n", 14 / 7);
    printf("%d\n", 7 / 2);// 3.5 in floating division // 정수에서는 소수점 잘라내서 3이 출력된다
    printf("%d\n", 7 / 3);// 2.333 in floating division
    printf("%d\n", 7 / 4);// 1.75 in floating division
    printf("%d\n", 8 / 4);// 2

    printf("Truncating toward zero (C99)\n");
    printf("%d\n", -7 / 2);// -3.5 in floating division // 정수에서는 소수점 잘라내서 -3이 출력된다
    printf("%d\n", -7 / 3);// -2.333 in floating division
    printf("%d\n", -7 / 4);// -1.75 in floating division
    printf("%d\n", -8 / 4);// -2

    printf("\nFloating divisions\n");
    printf("%f\n", 9.0 / 4.0);
    printf("%f\n", 9.0 / 4);// Note: 4 is integer // 컴파일러가 4를 double로 바꿔서 계산한 결과(다른 자료형끼리는 계산 불가), 가급적 같은 자료형끼리 계산하자

    return 0;
}
