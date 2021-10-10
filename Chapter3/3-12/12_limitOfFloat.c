
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

/*
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
*/

/*
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
*/

/*
int main() {
    //overflow
    float max = 3.402823466e+38F; // float가 가질 수 있는 가장 큰 수, float.h에서 가져옴
    printf("%f\n", max);
    max = max \* 100.0f; // 거기다 100을 곱한다.
    printf("%f\n", max);

    return 0;
}

float 숫자 범위 넘어가면 inf로 표시된다. double로 바꾸면 괜찮음
*/

/*
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
*/

/*
underflow

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

*/

/*
0으로 나누기

int main() {

    float f = 104.0f;
    printf("%f\n", f);
    f = f / 0.0f;
    printf("%f\n", f);

    return 0;
}


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
*/
