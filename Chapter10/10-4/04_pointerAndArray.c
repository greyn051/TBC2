/*
## 10.4 포인터와 배열
*/

#include <stdio.h>

int main() {

    int arr[10];

    int num = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < num; ++i)
    	arr[i] = (i + 1) * 100;

    int* ptr = arr;

    printf("%p %p %p\n", ptr, arr, &arr[0]);	// 주소값 3개 모두 같다.

    ptr += 2;

    printf("%p %p %p\n", ptr, arr + 2, &arr[2]);

    //Note: arr += 2; // invalid (배열 주소를 직접적으로 연산할 수 없다)

    printf("%d %d %d\n", *(ptr + 1), *(arr + 3), arr[3]);	// 모두 4번째 배열 원소의 주소다

    // Warning
    printf("%d %d %d\n", *ptr + 1, *arr + 3, arr[3]);	// 가져온 값에 대해서 연산을 하는 것 주의!(의도에 맞는지 확인)

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

int main() {

    int arr[10];

    int num = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < num; ++i)
    	arr[i] = (i + 1) * 100;

    /*
    for (int i = 0, *ptr = arr; i < num; ++i)	// 초기화하는 부분에서 ptr까지 하고 있는데 이렇게 까지 줄여서 쓰는 경우는 많이 없다
    {											// 하지만 scope(영역)을 이용해서 문법 오류를 피하는 방법으로 사용할 수 있다.
    	printf("%d %d\n", *ptr++, arr[i]);		// 실무에서 많이 사용되는 문법 형태
    }
    	위와 같이 줄여쓰기 보다는 밑에와 같이 의미가 잘 이해되는 코드를 쓴다.
    	(요즘엔 코드를 줄이는 것 보단 프로그래머의 실수를 줄이는 것이 더 중요하다)
    */

    //int* ptr = NULL;
    //ptr = arr;
    int* ptr = arr;
    for (int i = 0; i < num; ++i) {
    	printf("%d %d\n", *ptr++, arr[i]);		  // 실무에서 많이 사용되는 문법 형태 *ptr++ (증가 연산자 따로 밑에 써도 되긴 함)
    	//printf("%d, %d\n", *(ptr + i), arr[i]);	// 결과 동일
    	//printf("%d, %d\n", *ptr + i, arr[i]);		// 결과 다름
    }

    return 0;
}
