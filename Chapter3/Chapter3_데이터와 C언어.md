# TBC-3 데이터와 C언어

## 3.1 데이터와 자료형(Data, Data Types)

컴퓨터는 근본적으로 데이터를 처리하는 기계

## 3.2 변수(Variable)와 상수(Constants)

## 3.3 scanf() 함수의 기본적인 사용법

## 3.4 간단한 콘솔 입출력 프로그램 만들기

## 3.5 정수와 실수

## 3.6 정수의 오버플로우(Overflow)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    unsigned int i = 0;

    printf("%u\n", sizeof(unsigned int));
    printf("%u", sizeof(i));

    return 0;
}
```

```c
#include <stdio.h>

int main()
{
unsigned int i = 0b11111111111111111111111111111111;

    printf("%u\n", i);

    return 0;
}
```

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int i = 0b11111111111111111111111111111111;
unsigned int u = UINT_MAX;

    printf("%u\n", i);
    printf("%u\n", u);

    return 0;
}
```

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int u_max = UINT_MAX;
unsigned int u_min = 0;
signed int i_max = INT_MAX;
signed int i_min = INT_MIN;

    printf("max of uint = %u\n", u_max);
    printf("min of uint = %u\n", u_min);
    printf("max of int = %d\n", i_max);
    printf("min of int = %d\n", i_min);

    return 0;
}
```

#### overflow 실행

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int u_max = UINT_MAX + 1;
printf("%u", u_max);

    return 0;
}
```

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int u_max = UINT_MAX;

    // i to binary representation
    char buffer[33];
    _itoa(u_max, buffer, 2);

    // print decimal and binary
    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
```

or

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int u_max = UINT_MAX + 1;

    char buffer[33];
    _itoa(u_max, buffer, 2);

    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
```

or

```c
#include <stdio.h>
#include <limits.h>

int main()
{
unsigned int u_max = 0 - 1;

    char buffer[33];
    _itoa(u_max, buffer, 2);

    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
```

## 3.7 8진수와 16진수

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
char c = 65;
short s = 200;
unsigned int ui = 3000000000U;//3'000'000'000U
long l = 65537L;
long long ll = 12345678908642LL; // 12'345'678'908'642LL
printf("char = %hhd, %d, %c\n",c, c, c);
printf("short = %hhd, %hd, %d\n", s, s, s);
printf("unsigned int = %u, %d\n", ui, ui);
printf("long = %ld, %hd\n", l, l);
printf("long long = %lld, %ld\n", ll, ll);

    return 0;

}

#3.8

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
unsigned int decimal = 4294967295;
unsigned int binary = 0b11111111111111111111111111111111; // 1이 32개
unsigned int oct = 037777777777;
unsigned int hex = 0xffffffff;
printf("%u\n", decimal);
printf("%u\n", binary);
printf("%u\n", oct);
printf("%u\n", hex);

    printf("%o %x %#o %#x %#X\n", decimal, decimal, decimal, decimal, decimal);

    return 0;

}

#3.9

#include <stdio.h>
//#include <stdint.h> // also included in inttypes.h
#include <inttypes.h>

int main()
{
int i;
int32_t i32; // 32 bit integer
int_least8_t i8; // smallest 8 bit
int_fast8_t f8; // fastest minimum
intmax_t imax; // biggest signed integers
uintmax_t uimax; // biggest unsigned integer

    i32 = 1004;

    printf("me32 = %d\n", i32);
    printf("me32 = %" "d" "\n", i32);
    printf("me32 = %" PRId32 "\n", i32);

    return 0;

}

#3.10

#include <stdio.h>

int main()
{
char c = 'A';
char d = 65; // d = 'A'

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    return 0;

}

#3.10

#include <stdio.h>

int main()
{
char c = 'A';
char d = 65; // d = 'A'

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    printf("%c \n", c + 1);

    char a = '\a';
    printf("%c", a);

    printf("\07");	//\7
    printf("\x7");

    float salary;
    //printf("$______");
    printf("$______\b\b\b\b\b\b");
    scanf("%f", &salary);

    printf("AB\tCDEF\n");
    printf("ABC\tDEF\n");

    printf("\\ \'HA+\' \"Hello\" \?\n");

    return 0;

}

#3.11

#include <stdio.h>
#include <float.h>

int main() {
printf("%u\n", sizeof(float));
printf("%u\n", sizeof(double));
printf("%u\n", sizeof(long double));

    float f = 123.456f;
    double d = 123.456;

    float f2 = 123.456;
    double d2 = 123.456f;

    int i = 3;
    float f3 = 3.f; // 3.0f 홍교수님은 이래 쓴다(이런식으로 쓰면 알아보기 쉬우니)
    double d3 = 3.; // 3.0

    float f4 = 1.234e10f;

    float f5 = 0xb.ap1;
    double d5 = 1.0625e0;

    printf("%f %F %e %E\n", f, f, f, f);
    printf("%f %F %e %E\n", d, d, d, d);
    printf("%a %A\n", f5, f5);
    printf("%a %A\n", d5, d5);

    return 0;

}

#3.12

#include <stdio.h>
#include <float.h>

int main() {
//round-off errors (ex1)
float a, b;
a = 1000.0f + 1.0f;
b = a - 1000.0f;
printf("%f\n", b);

    return 0;

}

//
이렇게 하면 아까와 같이 1이 나올 것 같지만 0이 나온다.
int main() {
//round-off errors (ex1)
float a, b;
a = 1.0E20f + 1.0f;
b = a - 1.0E20f;
printf("%f\n", b);

    return 0;

}
숫자가 너무 크면 상대적으로 작은 숫자는 사라져 버린다.
//
밑에 a에 0.01f 100번 더할 거임(※스압 주의)
int main() {
//round-off errors (ex2)
float a = 0.0f;

    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;
    a = a + 0.01f;

    printf("%f\n", a);

    return 0;

}
그런데 1이 아니고 0.9999999 가 나온다
이유는 0.01f위에 커서를 올리면 0.009999~ 뜨는데
0.01로 정확하게 표현할 수 없기 때문이다. 그리고 이 오차가 쌓여서 차이가 난다.

이진수를 십지수로 표현할 때 정확하게 표현하기 어렵기 때문에 오차가 난다.
//

int main() {
//overflow
float max = 3.402823466e+38F; // float가 가질 수 있는 가장 큰 수, float.h에서 가져옴
printf("%f\n", max);
max = max \* 100.0f; // 거기다 100을 곱한다.
printf("%f\n", max);

    return 0;

}
float 숫자 범위 넘어가면 inf로 표시된다. double로 바꾸면 괜찮음
//
double의 한계를 돌파해보자
int main() {
//overflow
double max = 1.7976931348623158e+308;
printf("%f\n", max);
max = max \* 100.0f;
printf("%f\n", max);

    return 0;

}
그럼 inf가 뜬다

// underflow

int main() {
//underflow
float f = 1.401298464e-45F; // FLT_TRUE_MIN 에서 가져옴
printf("%e\n", f);
f = f / 100.0f; // subnormal
printf("%e\n", f);

    return 0;

}

이 경우 0이 나온다.
숫자가 너무 작아서 사라지는 경우 > subnormal

// 0으로 나누기
int main() {

    float f = 104.0f;
    printf("%f\n", f);
    f = f / 0.0f;
    printf("%f\n", f);

    return 0;

}

//
int main() {

    float f = asinf(1.0f);
    printf("%f\n", f);

    f = asinf(2.0f); // arcsin에 2 넣기
    printf("%f\n", f);

    return 0;

}

컴터는 어쩔 수 없이 답을 내지만
-nan(ind) 라고 뜬다(수학적으로 존재할 수 없는 값을 답으로 낼 때 이런식으로 나온다)
(not a number)
//

#3.13

#include <stdio.h>
#include <stdbool.h>

int main() {

    printf("%u\n", sizeof(_Bool)); // 1 byte

    _Bool b1;
    b1 = 0; // false
    b1 = 1; // true

    printf("%d\n", b1);

    bool b2, b3;
    b2 = true;
    b3 = false;

    printf("%d %d\n", b2, b3);

    return 0;

}

#3.14

// vs에서

#include <stdio.h>
#include <complex.h>

int main() {

    _Dcomplex z;
    z._Val[0] = 1.0;
    z._Val[1] = 1.0;

    return 0;

}

//vsc, gcc 에서
vsc는 복소수 지원 좀 더 잘 해줌
#include <stdio.h>
#include <complex.h>

int main()
{
//double \_Imaginary i = 3;
double \_Complex z = 1 + 2 \* I;

    z = 1 / z;

    printf("1 / (1.0 + 2.0i) = %.1f%+.1fi", creal(z), cimag(z));

    return 0;

}
I는 허수 부분을 의미한다(Imaginary number)
creal(z)는 실수 부분
cimag(z)는 허수 부분을 가져와서 출력
복소수의 나누기도 구현
원래 표준에는 \_Imaginary도 있어야 하는데 gcc에서도 조차 구현되어 있지 않다.

```

```
