/*
## 9.13 포인터(Pointer)의 기본적인 사용 방법
*/

#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    return 0;
}


/*********************************************************
*********************************************************/


// 정수형 변수에 주소값 대입하면 warning이 뜬다

#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    b = a_ptr;

    /*b = *a_ptr;

    printf("%d\n", b);*/

    return 0;
}


/*********************************************************
*********************************************************/


// 주소 대입

#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    b = a_ptr;	// 주소를 integer에 넣는 경우는 거의 없다. warning뜸

    /*b = *a_ptr;

    printf("%d\n", b);*/

    return 0;
}


/*********************************************************
*********************************************************/


// 포인터 대입

#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.

    printf("%d\n", b);

    return 0;
}


/*********************************************************
*********************************************************/


// 값을 주소에서 가져와서 그 값을 저장할 때 순수하게 값만 저장한다.

#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.(순수하게 값만 저장)

    printf("%d\n", b);

    *a_ptr = 789;

    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.(순수하게 값만 저장)

    printf("%d\n", b);

    *a_ptr = 789;

    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

    b = 12;

    printf("%d\n", b);
    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    a = 1004;
    printf("%d %d %p %d\n", a, *a_ptr, a_ptr, b);

    return 0;
}
