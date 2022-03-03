/*
## 10.14 2차원 배열과 포인터
*/

#include <stdio.h>

int main() {

    float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

    printf("%u\n", (unsigned)arr2d);		// Use unsigned long long in x64
    printf("%u\n", (unsigned)arr2d[0]);

    // arr2d points to arr2d[0] (not arr2d[0][0]), KNK CH. 12.4

    printf("%u\n", (unsigned)* arr2d);		// * arr2d(arr2d를 indirection)하면 & arr2d[0]가 나온다.
    printf("%u\n", (unsigned)& arr2d[0]);	// C language allows this
    printf("%u\n", (unsigned)& arr2d[0][0]);
    printf("%f %f\n", arr2d[0][0], **arr2d);// **arr2d(double indirection)을 하면 arr2d[0][0]인 값이 나온다.
    printf("\n");

    printf("%u\n", (unsigned)(arr2d + 1));	// arr2d[2][4]이므로 16byte를 건너 뛴다.(포인터 연산)
    printf("%u\n", (unsigned)(&arr2d[1]));
    printf("%u\n", (unsigned)(arr2d[1]));
    printf("%u\n", (unsigned)(*(arr2d + 1)));// 포인터 연산해서 indirection 한 것과 위와 동일
    printf("%u\n", (unsigned)(&arr2d[0] + 1));
    printf("%u\n", (unsigned)(&arr2d[1][0]));
    printf("\n");

    printf("%f\n", *(*(arr2d + 1) + 2));
    printf("\n");

    for (int j = 0; j < 2; ++j) {
    	printf("[%d] = %u, %u\n", j, (unsigned)(arr2d[j]), (unsigned)*(arr2d + j));

    	for (int i = 0; i < 4; ++i) {
    		printf("[%d][%d] = %f, %f\n", j, i, arr2d[j][i], *(*(arr2d + j) + i));

    		*(*(arr2d + j) + i) += 1.0f; // arr2d[j][i] += 1.0f;
    	}
    }
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    /* Pointers to Multidimensional Arrays */

    float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

    float(*pa)[4];	// a SINGLE pointer to an array of 4 floats
    float* ap[2];	// an array of TWO pointers-to-float

    printf("%zu\n", sizeof(pa));	// 8 in x64
    printf("%zu\n", sizeof(ap));	// 16 in x64
    printf("\n");

    pa = arr2d;			// 사용할 때 이중포인터 처럼 쓸 수는 있다.
    //pz[0] = arr2d[0]; // error (포인터가 하나이기 때문에 배열처럼 쓸 수 없다.)
    //pz[1] = arr2d[1]; // error

    //ap = arr2d;		// error
    ap[0] = arr2d[0];	// 포인터의 배열은 이런식으로 초기화 한다.
    ap[1] = arr2d[1];

    printf("%u %u\n", (unsigned)pa, (unsigned)(pa + 1));	// 첫번째 줄 이외에 나머지 줄은 밑과 동일
    printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
    printf("%u %u\n", (unsigned)pa[0], (unsigned)(pa[0] + 1));
    printf("%f\n", pa[0][0]);
    printf("%f\n", *pa[0]);
    printf("%f\n", **pa);
    printf("%f\n", pa[1][3]);
    printf("%f\n", *(*(pa + 1) + 3));
    printf("\n");

    printf("%u %u\n", (unsigned)ap, (unsigned)(ap + 1));	// 포인터의 배열이기 때문에 포인터를 담는 배열이 새로 생겨남
    printf("%u %u\n", (unsigned)arr2d[0], (unsigned)arr2d[1]);
    printf("%u %u\n", (unsigned)ap[0], (unsigned)(ap[0] + 1));
    printf("%f\n", pa[0][0]);
    printf("%f\n", *pa[0]);
    printf("%f\n", **pa);
    printf("%f\n", pa[1][3]);
    printf("%f\n", *(*(pa + 1) + 3));

    return 0;
}
