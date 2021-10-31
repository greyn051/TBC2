/*
## 5.11 자료형 변환(Type Conversions)
*/

#include <stdio.h>

int main() {
    /* promotions in assignments */
    short s = 64;
    int i = s;

    float f = 3.14f;
    double d = f;

    /* demotion in assignments */
    d = 1.25;
    f = 1.25; // 1.25는 0.25가 1/4 즉 2배수에 대한 역수이므로 문제 없다.
    //f = 1.123; // 1.123은 double과 float일 때 미묘하게 값이 차이가 난다.(truncation(절삭) 오류)

    /* ranking of types in operations */ // 밑으로 내려갈 수록 ranking이 낮다
    // long double > double > float
    // unsigned long long, long long
    // unsigned long, long
    // unsigned, int
    // short int, unsigned short int
    // signed char, char, unsigned char
    // _Bool
    //Ref: Google 'Integer conversion rank'
    d = f + 1.234;
    f = f + 1.234; // r-value는 double이 된다. 그래서 truncation 오류 뜬다

    /* automatic promotion of function arguments */
    // 1. Functions without prototypes
    // 2. Variadic functions (ellipsis)

    /* casting operators */ // 형변환을 할 거라고 의도적으로 표현
    d = (double)3.14f; // (double)을 해주면 이 expression의 값은 double이 된다.
    i = 1.6 + 1.7; // truncation 되면서 i = 3이 된다.
    i = (int)1.6 + (int)1.7; // 1 + 1되고 i =2이 된다.

    /* more examples */
    char c;
    //int i;
    //float f;
    f = i = c = 'A'; // 65
    printf("%c %d %f\n", c, i, f);
    c = c + 2; // 'C', 67
    i = f + 2 * c; // 65.0f + 2 * 67
    printf("%c %d %f\n", c, i, f); // 199
    c = 1106; // demolition(강등된다), 1106 = 0b10001010010(이진수),	(앞부분 잘라내고 1byte=8bit만 남김, 이게 마치 나머지 연산자 적용한 것과 같음)0b01010010 = 1106 % 256 = 82 = 'R'
    printf("%c\n", c);
    c = 83.99; // truncation, 83
    printf("%c\n", c);

    return 0;
}
