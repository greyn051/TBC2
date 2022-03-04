/*
## 10.15 포인터의 호환성(Compatibility)
*/

#include <stdio.h>

int main() {

    /* Pointers Compatibiliy */

    int n = 5;
    double x;
    x = n;			// no error (정수를 실수에 대입할 때는 문제가 없다.)
    int* pi = &n;
    double* pd = &x;
    //pd = pi;		// warning (정수 포인터를 실수 포인터에 대입할 수 없다. 호환이 불가능하다. 원래는 error였기 때문에 매우 위험하다. 그러니까 이렇게 절대 쓰지마라.)

    int* pt;
    int(*pa)[3];		// 원소가 3개짜리인 배열에 대한 포인터
    int ar1[2][3] = { 3, };	// 원소가 3개짜리인 배열에 대한 배열
    int ar2[3][2] = { 7, };
    int** p2;		// a pointer to a pointer

    pt = &ar1[0][0];	// pointer-to-int

    for (int i = 0; i < 6; ++i)
    	printf("%d ", pt[i]); // or *(pt + i)

    pt = ar1[0];		// pointer-to-int;
    //pt = ar1;			// Warning (Error) // ar1자체는 이중포인터이기 때문에 그냥 포인터에 담을 수 없다.

    pa = ar1;			// pointer-to-int[3]
    //pa = ar2;			// Warning or error	// 배열이 3개가 아니라 2개이므로 warning이 뜬다.

    p2 = &pt;			// pointer-to-int *
    *p2 = ar2[0];		// pointer-to-int
    //p2 = ar2;			// Warning (Error)
    //Notes
    // - p2: pointer to pointer to int
    // - ar2: a pointer to array-of-two-ints

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    /* Pointer and const */

    int x = 20;
    const int y = 23;
    int* p1 = &x;
    const int* p2 = &y;		// indirection 했을 때 못 바꾼다는 뜻 // const int* const p2하면 p2 자체도 바꿀 수 없다.
    const int** pp2 = &p1;
    //p1 = p2;		// Warning (Error) // 그냥 int* p1이므로 const가 없기 때문

    //*p2 = 123;	// Error //(const인 y의 값을 바꾸려는 것과 동일)(하지만 이게 값을 못 바꾸는 이유는 const int* p2 때문이다.)
    p2 = p1;

    int x2 = 30;
    int* p3 = &x2;
    *pp2 = p3;	// 이게 허용이 되고 있는데 위에서 const int* const * pp2 = &ap1;로 바꾸면 안 된다.
    pp2 = &p1;	// 위에 const int** const pp2 = &ap1;로 바꾸면 막힌다.

    return 0;
}
```
//
```c
#include <stdio.h>

int main() {

    /* Pointer and const */

    const int** pp2;
    int* p1;
    const int n = 13;
    pp2 = &p1;		// const?
    *pp2 = &n;		// sets p1 to point at n
    *p1 = 10;		// change n

    /*
    컴파일러가 허용하건 허용하지 않건 이런 것은 하지 않는게 좋다.
    (const로 정의된 포인터에 값을 넣어로 빌드 되는 것)
    */

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    /* Const and C++ const */

    const int y;
    const int* p2 = &y;
    int* p1;
    p1 = p2;	// warning (error in cpp) //const를 회피하려는 시도를 cpp에서는 막는다

    /*
    	C++에서는 이걸 보다 엄격하게 막는다.
    */

    return 0;
}
