/*
## 6.16 배열(Array)과 런타임(Runtime) 에러
*/

#include <stdio.h>

#define NUM_DAYS 365

int main() {

    char my_chars[] = "Hello, World!"; // 자동으로 공간을 할당해줌

    int daily_temperature[NUM_DAYS];
    double stock_prices_history[NUM_DAYS];

    printf("%zd\n", sizeof(stock_prices_history));
    printf("%zd\n", sizeof(double) * NUM_DAYS);		// 8*365
    printf("%zd\n", sizeof(stock_prices_history[0]));

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

#define NUM_DAYS 365

int main() {

    int my_numbers[5];

    my_numbers[0] = 1;	// [ ]안에 숫자 부르는 용어들 : subscripts, indices, offsets // [0]부터 시작하고 세는 것 아주 중요
    my_numbers[1] = 3;
    my_numbers[2] = 4;
    my_numbers[3] = 2;
    my_numbers[4] = 1024;

    //scanf("%d", &my_numbers[0]); // [0]가 &보다 연산자 우선순위가 높음
    scanf("%d", my_numbers); // offset이 0일 때는 &와 [0]떼고 사용 가능

    printf("%d\n", my_numbers[0]);
    printf("%d\n", my_numbers[1]);
    printf("%d\n", my_numbers[2]);
    printf("%d\n", my_numbers[3]);
    printf("%d\n", my_numbers[4]); // 나중에 for문 써서 한 줄로 바꿈

    return 0;
}


/*********************************************************
*********************************************************/


// 배열 사용 시 오류들

int main() {

    int my_numbers[5];

    /* Runtime Error */
    my_numbers[5] = 123; // out of bound
    // 초보 때 가장 실수 주의해야하는 부분, 게다가 컴파일할 때 이 에러를 안 잡아줌 실행하면 그 때 runtime error가 뜸.

    my_numbers = 7; // compile error // []를 안 썼을 때 그냥 첫 주소의 역할을 하기 때문에 대입이 되지 않는다.(이 정도는 컴파일러가 잡아준다)

    printf("%d\n", my_numbers[5]); // out of bound

    return 0;
}
