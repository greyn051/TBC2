/*
## 5.12 함수의 인수와 매개변수(Arguments vs. Parameters)
*/

/*
숫자에 따라 그 개수만큼 별이 출력되는 프로그램 만들기
(별을 출력하는 부분을 함수로 만들어서 반복해서 사용을 하는 것이 이 프로그램의 가장 중요한 점)
and argument와 parameter의 차이
*/

#include <stdio.h>

void draw(int n); // ANSI function prototype declaration

int main() {
    int i = 5;
    char c = '#'; // 35
    float f = 7.1f;

    draw(i); /* 함수를 호출하는 측면에서 실제로는 5(i에 들어있는 값)를 넣는 것이므로 argument, value라고 부른다.
    draw((int)c); // draw(c); // promotion은 문법상 문제가 없지만 의도를 확실히 하기 위해서 draw((int)c);라고 써주는 것이 좋다.
    draw((int)f); // draw(f); // demotion warning을 방지하려면 draw((int)f); 라고 써야한다.

    /* Arguments vs. Parameters */ // (argument, parameter가 수식어까지 붙으며 너무 혼용된다고 생각해서 C99에서 정리)
    // actual argument, actual parameter(실 인수, 실 매개변수) -> argument (values)(C99에서 정리)
    // formal argument, formal parameter(형식 인자, 형식 매개변수) -> parameter (variables)

    /* 요약하면 함수를 호출하는 측면에서 볼 때는 i를 argument(value)라고 부르고,
       draw함수를 정의하는 입장에서 볼 때는 변수 n이 parameter(variable)가 된다.*/

    return 0;
}

void draw(int n) /* n에 어떠한 값이 들어와도 함수를 수행할 수 있어야한다. n을 변수로 받아들인다.(function draw가 variable n에 대해서 parameterization(매개변수화)되어있다.) */
{
    //TODO: print stars (asterisks)
    while (n-- > 0)
    printf("\*");
    printf("\n");
}


/*********************************************************
*********************************************************/

// ※ 내가 한 함수 코드


void draw(int n) {
    //TODO: print stars (asterisks)
    int m = 0;
    while (m++ < n) {
    printf("\*");
    }

    printf("\n");

}

