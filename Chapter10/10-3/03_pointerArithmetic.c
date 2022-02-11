/*
## 10.3 포인터의 산술 연산(Pointer Arithmetic)
*/

#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    return 0;
}

// 각 자료형 원소들이 가지는 데이터 사이즈 알 수 있다. -도 가능


/*********************************************************
*********************************************************/

/*
포인터에서 단항 연산은 막아두었다.
(주소를 음수로 바꿀 이유가 없기 때문)
*/

#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    return 0;
}


/*********************************************************
*********************************************************/


/*
포인터 주소끼리 더하는 것은 안 된다.(의미가 없어서)
다만 빼기는 된다.(주소 간의 차이를 나타내므로 이용 가능)
*/

#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    /* Subtraction */
    int arr[10];
    int* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;	// Not working
    int i = ptr2 - ptr1;	// meaning? // 주소 간의 차이를 나타내므로 이용 가능

    printf("%p %p %d\n", ptr1, ptr2, i);

    return 0;
}


/*********************************************************
*********************************************************/


// 10진수로도 보자

#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    /* Subtraction */
    int arr[10];
    int* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;	// Not working
    int i = ptr2 - ptr1;	// meaning? // 주소 간의 차이를 나타내므로 이용 가능

    printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);

    return 0;
}
