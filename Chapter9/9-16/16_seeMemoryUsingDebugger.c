/*
## 9.16 디버거로 메모리 들여다보기(비주얼 스튜디오)
*/

#include <stdio.h>

int main() {

    int a = 3, b = 5, c = 7, d = 9;
    int* a_ptr = &a, * b_ptr = &b, * c_ptr = &c, * d_ptr = &d;

    printf("%p %p %p %p", &a, &b, &c, &d);

    return 0;
}
