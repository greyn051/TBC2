/*
## 5.7 나머지 연산자(Modulus Operator)
*/

#include <stdio.h>

int main() {
    int seconds = 0, minutes = 0, hours = 0;

    printf("Input seconds : ");
    scanf("%d", &seconds);

    //TODO: seconds -> hours, minutes, seconds
    minutes = seconds / 60;
    seconds %= 60; //seconds = seconds % 60;

    hours = minutes / 60;
    minutes %= 60; //minutes = minutes % 60;

    // printf result
    printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    printf("Good bye\n");

    return 0;
}


/*********************************************************
*********************************************************/


// 반복해서 사용할 수 있도록 while문 사용해보자(음수가 나오면 종료)

int main() {
    int seconds = 0, minutes = 0, hours = 0;

    while (seconds >= 0) {
    	printf("Input seconds : ");
    	scanf("%d", &seconds);

    	minutes = seconds / 60;
    	seconds %= 60; //seconds = seconds % 60;

    	hours = minutes / 60;
    	minutes %= 60; //minutes = minutes % 60;

    	// printf result
    	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    }

    printf("Good bye\n");

    return 0;
}


/*********************************************************
*********************************************************/


// 음수 입력하면 계산값 생략하고 바로 goodbye 나올 수 있게

int main() {
    int seconds = 0, minutes = 0, hours = 0;

    printf("Input seconds : ");
    scanf("%d", &seconds);

    while (seconds >= 0) {
    	minutes = seconds / 60;
    	seconds %= 60; //seconds = seconds % 60;

    	hours = minutes / 60;
    	minutes %= 60; //minutes = minutes % 60;

    	// printf result
    	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    	printf("Input seconds : ");
    	scanf("%d", &seconds);
    }

    printf("Good bye\n");

    return 0;
}


/*********************************************************
*********************************************************/


// 음수에서 나머지 연산자의 결과는?

int main() {
    int div, mod;

    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod);

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / -5;
    mod = -11 % -5;// first operand is negative // 앞에 있는 피연산자가 음수면 나머지 연산자의 결과도 음수다
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / 5;
    mod = -11 % 5;// first operand is negative
    printf("div = %d, mod = %d\n", div, mod);

    return 0;
}
