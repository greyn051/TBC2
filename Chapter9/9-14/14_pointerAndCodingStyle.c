/*
## 9.14 포인터와 코딩 스타일
*/

#include <stdio.h>

int main() {

    // int *a_ptr vs int* a_ptr
    // int *my_ptr, sec_ptr;
    int *a, b; // *a만 포인터고 b는 정수다
    //int* a, b; // typedef

    /*
    	if Google style

    int *a; // OK (but 밑에와 혼용하지 말고 한가지 스타일만)
    int* b; // OK
    int * b; // X

    */

    return 0;
}
