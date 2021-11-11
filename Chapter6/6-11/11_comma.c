/*
## 6.11 콤마(,) 연산자 Comma
*/

#include <stdio.h>

int main() {
    // , 씀으로서 여러줄에 하는 것을 한줄로도 할 수 있다.
    for (int n = 1, nsqr = n _ n; n < 10; n++, nsqr = n _ n)
    printf("%d %d\n", n, nsqr);

    // Note that commas in printf() are not comma operators
    // but separators

    return 0;
}


/*********************************************************
*********************************************************/


// ,도 ;와 같은 sequence point

int main() {
    int i, j;
    i = 1;
    i++, j = i; // comma is a sequence point
    printf("%d %d\n", i, j);

    return 0;
}


/*********************************************************
*********************************************************/


int main() {
    // ,의 연산자 우선순위는 가장 마지막. 그리고 왼쪽에서 오른쪽으로 진행한다.(Left-to-right)
    int x, y, z;
    z = x = 1, y = 2;
    printf("x=%d, y=%d, z=%d \n", x, y, z);
    z = (x = 1), (y = 2);
    printf("x=%d, y=%d, z=%d \n", x, y, z);
    z = ((x = 1), (y = 2)); // ,는 오른쪽에 있는 것이 expression값이다. 그래서 z에는 2가 대입된다.
    printf("x=%d, y=%d, z=%d \n", x, y, z);

    return 0;
}


/*********************************************************
*********************************************************/


int main() {
    //int my_money = 123,456; // error 프로그래밍 언어에서 숫자에 ,찍으면 에러난다.
    int my_money = (123, 456); // , 오른쪽이 전체 expression의 값
    printf("%d\n", my_money);

    return 0;
}
