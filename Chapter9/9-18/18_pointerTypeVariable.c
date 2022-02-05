/*
## 9.18 포인터형 매개변수
*/

//두개의 값을 'swap'하는 코드 만들어 보자

#include <stdio.h>

int main() {

    int a = 123;
    int b = 456;

    // swap
    int temp = a;
    a = b;
    b = temp;
    printf("%d %d\n", a, b);

    return 0;
}


/*********************************************************
*********************************************************/


// 위의 swap을 함수로 만들어서 써보자

#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 123;
    int b = 456;

    // swap
    swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}

// 해보면 swap이 전혀 안 된다.

#include <stdio.h>

void swap(int a, int b) {

    printf("%p %p\n", &a, &b);

    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 123;
    int b = 456;

    printf("%p %p\n", &a, &b);

    // swap
    swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}

/*
확인해 보면 주소가 전혀 다르다.
(애초에 이름만 같고 다른 변수이므로)
*/


/*********************************************************
*********************************************************/


// swap 함수에 a의 주소와 b의 주소를 넣어서 해결해보자

#include <stdio.h>

void swap(int* u, int* v) {

    printf("%p %p\n", u, v);

    int temp = *u;
    *u = *v;
    *v = temp;
}

int main() {

    int a = 123;
    int b = 456;

    printf("%p %p\n", &a, &b);

    // swap
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}

/*
이런 것을
call by pointer
라고 부르기도 한다.
*/
