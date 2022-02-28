/*
## 10.10 const와 배열과 포인터
*/

#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[3] = { 1.0, 2.0, 3.0 };
    //arr2[0] = 100.0;

    double* pd = arr2; // 여기서 문제점이 위에 이미 배열에 const 넣었는데 포인터를 통하면 값을 바꿀 수 있어진다. 그래서 이런 방식 쓰는거 매우 안 좋음
    *pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    pd[2] = 1024.0; // arr2[2] = 4.0; (pd는 포인터인데 배열처럼 사용가능)

    printf("%f %f", pd[2], arr2[2]);

    pd++; // allowed

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
    //arr2[0] = 100.0;

    const double* pd = arr2;
    //*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    //pd[2] = 1024.0; // arr2[2] = 4.0;

    printf("%f %f\n", pd[2], arr2[2]);

    pd++; // allowed (const해도 증가연산자는 된다) > 포인터 자체값인 주소를 바꿀 수 있다는 말임

    printf("%f %f\n", pd[2], arr2[2]);

    return 0;
}


/*********************************************************
*********************************************************/


// pd++;도 막기위해서는 뭘 해야할까

#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
    //arr2[0] = 100.0;

    const double* const pd = arr2;
    //*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    //pd[2] = 1024.0; // arr2[2] = 4.0;

    printf("%f %f\n", pd[2], arr2[2]);

    //pd++; // allowed

    printf("%f %f\n", pd[2], arr2[2]);

    return 0;
}

// 포인터의 변수명 앞에 const를 더 붙인다.

/*********************************************************
*********************************************************/

/*
const double\* pd = arr2;
에서는 포인터가 가리키는 메모리 값을 못 바꾼다.

double\* const pd = arr2;
에서는 포인터 변수 값 자체를 못 바꾼다.(주소값 못 바꿈)

const double\* const pd = arr2; 쓰면 둘 다 못 바꿈
*/
