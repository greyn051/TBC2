/*
## 10.13 포인터의 배열과 2차원 배열
*/

#include <stdio.h>

int main() {
    /* Two of 1D arrays */

    int arr0[3] = { 1, 2, 3 };
    int arr1[3] = { 4, 5, 6 };

    int* parr[2] = { arr0, arr1 };	// an array of pointers

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)
    		printf("%d(==%d) ", parr[j][i], *(parr[j] + i)); // 이중 배열처럼 가능, 포인터에 정수를 더해서도 찾을 수 있음
    	printf("\n");
    }
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {
    /* Two of 1D arrays */

    int arr0[3] = { 1, 2, 3 };
    int arr1[3] = { 4, 5, 6 };

    int* parr[2] = { arr0, arr1 };	// an array of pointers

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)
    		printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), *(*(parr + j) + i)); // ⭐이해 못 했다. 복습하자.
    	printf("\n");
    }
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {
    /* Two of 1D arrays */

    int arr0[3] = { 1, 2, 3 };
    int arr1[3] = { 4, 5, 6 };

    int* parr[2] = { arr0, arr1 };	// an array of pointers

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)
    		printf("%d(==%d, %d) ", parr[j][i], *(parr[j] + i), (*(parr + j))[i]); // 두번째가 원칙에 더 가깝다.
    	printf("\n");
    }
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


// 위와 같은 예제인데 형태만 바꿈

#include <stdio.h>

int main() {
    /* 2D arrays are arrays of 1D arrays */

    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    int *parr0 = arr[0];
    int *parr1 = arr[1];

    for (int i = 0; i < 3; ++i)
    	printf("%d ", parr0[i]);
    printf("\n");

    for (int i = 0; i < 3; ++i)
    	printf("%d ", parr1[i]);
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {
    /* arrays of pointers works like a 2D array */

    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    //int* parr[2] = { arr[0], arr[1] }; // 이렇게 초기화 해도 된다.
    int* parr[2];
    parr[0] = arr[0];
    parr[1] = arr[1];

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)
    		printf("%d %d %d %d\n",
    			arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));	// 실제론 1차원 처럼 저장되어 있기 때문에 뒤에 처럼 사용한다.
    	printf("\n");
    }
    printf("\n");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    /* arrays of pointers works like a 2D array */

    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };

    //int* parr[2] = { arr[0], arr[1] }; // 이렇게 초기화 해도 된다.
    int* parr[2];
    parr[0] = arr[0]; // 배열의 이름이 배열 전체를 대표하는 메모리 주소로 쓰일 수 있다.
    parr[1] = arr[1];

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)
    		printf("%d %d %d %d\n",
    			arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));	// 실제론 1차원 처럼 저장되어 있기 때문에 뒤에 처럼 사용한다.
    	printf("\n");
    }
    printf("\n");

    /*
    	Notes
    	- parr[0] and parr[1] do not point valid memory by default //  포인터 배열에 대입하기 전에는 쓰레기 값을 가짐
    	- &parr[0] != &arr[0]
    	- &parr[0] != parr[0] but &arr[0] == arr[0]
    */

    printf("%p\n", &parr[0]);	// different! // 포인터 자체의 주소
    printf("%p\n", parr[0]);	// 포인터가 가리키는 곳의 주소
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);	// address of array name is equal to the address of the first
    printf("%p\n", arr[0]);
    printf("%p\n", &arr[0][0]);

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    /* Array of string of diverse lengths example */

    char* name[] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie" };

    const int n = sizeof(name) / sizeof(char*);

    for (int i = 0; i < n; ++i)
    	printf("%s at %u\n", name[i], (unsigned)name[i]); // Use ull in x64 build (ull == unsigned long long)
    printf("\n");

    char aname[][15] = { "Aladdin", "Jasmine", "Magic Carpet", "Genie", "Jafar"}; // 2번째 차원에서 메모리 사이즈가 정해짐

    const int an = sizeof(aname) / sizeof(char[15]);

    for (int i = 0; i < an; ++i)
    	printf("%s at %u\n", aname[i], (unsigned)& aname[i]); // Use ull in x64 build
    printf("\n");


    return 0;
}
