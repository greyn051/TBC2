/*
## 10.9 포인터 연산 총정리
*/

#include <stdio.h>

int main() {

    /*
    Pointer operations
    - Assignment
    - Value finding (deferencing)
    - Taking a pointer address
    - Adding an integer to a pointer
    - Incrementing a pointer
    - Subtracting an integer from a pointer
    - Decrementing a pointer
    - Differencing
    - Comparisons
    */

    int arr[5] = { 100, 200, 300, 400, 500 };
    int* ptr1, * ptr2, * ptr3;

    ptr1 = arr;		// Assignment

    printf("%p %d %p\n", ptr1, *ptr1, &ptr1);// dereferencing, Taking a pointer address

    ptr2 = &arr[2]; // Address-of operator &

    printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

    ptr3 = ptr1 + 4;// Adding an integer from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    //Differencing
    printf("%td\n", ptr3 - ptr1);	//Note: t is for pointer difference (printf에서 t가 들어간 형식지정자는 포인터의 차이값을 받아서 출력할 때 사용한다.)

    ptr3 = ptr3 - 4;// Subtracting an integer from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    ptr1++;			// Incrementing, ptr1 = ptr1 + 1
    ptr1--;			// Decrementing
    --ptr1;
    ++ptr1;

    if (ptr1 == ptr3)
    	printf("Same\n");
    else
    	printf("Different\n");

    double d = 3.14;
    double* ptr_d = &d;
    if (ptr1 == ptr_d)	// warning C4133: '==': incompatible types - from 'double *' to 'int *' // 둘 다 주소라 메모리 크기는 같은데 타입이 달라서 error가 아니라 warning을 띄워준다. (int*)붙이면 안 뜸
    	printf("Same\n");
    else
    	printf("Different\n");

    return 0;
}
