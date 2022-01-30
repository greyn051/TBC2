/*
## 9.17 포인터 변수의 크기
*/

#include <stdio.h>

int main() {

    char a;		// 1byte
    float b;	// 4byte
    double c;	// 8byte

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));	 // pointer
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));			 // 주소를 직접 출력(주소 연산자)
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 자료형을 직접 출력
}

/*
자료형 크기에 상관없이 주소의 크기는 동일하다.
(x86에서는 4byte, x64에서는 8byte)
*/


/*********************************************************
*********************************************************/

// 데이터의 크기에 따라서 차지하는 양을 확인하기

#include <stdio.h>

int main() {

    char a = 1;		// 1byte
    float b = 3;	// 4byte
    double c = 5;	// 8byte

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    a = 2;
    b = 4;
    c = 6;

    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));	 // pointer
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));			 // 주소를 직접 출력(주소 연산자)
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 자료형을 직접 출력
}
