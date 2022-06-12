/*
## 12.1 메모리 레이아웃 훑어보기
*/


// ### 프로그램이 시작될 때

#include <stdio.h>

void func() {
    int i = 123;
    printf("%lld\n", (long long)&i);
}

int main() {
    const char* message = "Banana";
    printf("Apple and %s", message);
    printf("\n");

    void (*f_ptr)() = func;	// address of a function

    printf("%lld\n", (long long)&message);
    printf("%lld\n", (long long)&f_ptr);
    printf("%lld\n", (long long)message);
    printf("%lld\n", (long long)f_ptr);
    printf("%lld\n", (long long)main);

    func();

    return 0;
}



/*********************************************************
*********************************************************/


// ### 프로그램 전체에서 계속 사용되는 변수들

#include <stdio.h>

int g_i = 123; // global variable
int g_j; // global variable

void func1() {
    g_i++; // user g_i
}

void func2() {
    g_i += 2; // uses g_i
}

int main() {

    int local = 1234;

    func1();
    func2();

    printf("%d", g_i);// uses g_i

    return 0;
}


/*********************************************************
*********************************************************/


// ### 프로그램의 일부에서 큰 메모리가 필요한 경우

#include <stdio.h>

#define MAX 1000

// 1. Use global variable
int g_arr[MAX];

int main() {

/*
    Use g_arr
    ...
    Do NOT use g_arr
    ...
    Use g_arr
    ...
*/

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

#define MAX 1000

int main() {

    // 2. Use local in main()
    int l_arr[MAX] = { 0, };

/*
    Use l_arr
    ...
    Do NOT use l_arr
    ...
    Use l_arr
    ...
*/

    return 0;
}


/*********************************************************
*********************************************************/


//보다 효율적인 구조
#include <stdio.h>

#define MAX 1000

// 3. Use local in smaller function
void func() {

    int l_arr[MAX] = { 0, };

}

int main() {

/*
    Call func()
    ...
    Call func()
    ...
*/

    return 0;
}

/*********************************************************
*********************************************************/


//필요한 메모리의 크기를 미리 알 수 없을 경우
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;

    // n from files, internet, scanf, etc.

    char* arr = (char*)malloc(sizeof(char) * n);

    // ...

    free(arr);

    return 0;
}
