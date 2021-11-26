/*
## 7.9 조건 연산자(Conditional Operator) ? :
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {

    int temp;
    temp = true ? 1024 : 7; // ternary (항이 3개라서)(근데 3항연산자보다 조건연산자라고 부르는 것이 일반적)
    printf("%d\n", temp);

    temp = false ? 1024 : 7;
    printf("%d\n", temp);

    return 0;
}


/*********************************************************
*********************************************************/


int main() {

    int a = 1, b = 2;
    int max = (a > b) ? a : b;

    return 0;
}


/*********************************************************
*********************************************************/

// 홀짝 구분

int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    if (number % 2 == 0)
    	is_even = true;
    else
    	is_even = false;

    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;
}


/*********************************************************
*********************************************************/

// 위의 코드의 첫번째 if문을 조건연산자를 이용해서 구현해라

// ※ 내가 한 코드
int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    is_even = ((number % 2) == 0) ? true : false;

    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;
}


// ※ 교수님 코드
int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    is_even = (number % 2 == 0) ? true : false;  // ?는 연산자 우선순위가 매우 낮다. 그래도 대부분의 경우 보기 편하라고 괄호를 친다.

    // bool is_even = (number % 2 == 0) ? true : false; // 이렇게 쓰기도 한다.
    // const bool is_even = (number % 2 == 0) ? true : false; // 이렇게 쓰기도 한다.


    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;
}


/*********************************************************
*********************************************************/


// 홀짝 판별 코드 입력제외 한 줄로 줄이기

// ※ 내 코드
int main() {

    int number;
    scanf("%d", &number);

    (number % 2 == 0) ? printf("Even") : printf("Odd");

    return 0;
}

// ※ 교수님 코드 = 내 코드

/*
위에 처럼 사용은 가능하지만 잘 사용하진 않는다.

보통
bool is_even = ~
처럼 flag를 선언하고
그에 따라서 기능을 수행하는 것이 일반적이다.
*/
