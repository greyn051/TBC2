/*
## 10.5 2차원 배열과 메모리
*/

#include <stdio.h>

int main() {

    int arr[2][3] = { {1, 2, 3},
    			      {4, 5, 6} };

    //int arr[2][3] = { 1, 2, 3,
    //				    4, 5, 6 };
    //int arr[2][3] = { 1, 2 }; // insufficient initializer (나머지 0으로 채워주는 거 동일하게 작동)

    printf("%d\n\n", arr[1][1]);

    for (int j = 0; j < 2; ++j) {
    	for (int i = 0; i < 3; ++i)		// 대부분의 경우 오른쪽에 있는 것을 for문 안 쪽에 넣는다.
    		printf("%d ", arr[j][i]);	// i를 안 쪽 루프에 넣고 j를 바깥 루프에 둔다.(2차원 배열도 내부적으로는 1차원이기 때문에 원소를 읽어오는 순서와 메모리가 저장되어 있는 순서가 같으면 빠르게 읽어올 수 있다.)
    }

    //Note: inner loop uses i. why?

    int* ptr = &arr[0][0];
    for (int k = 0; k < 6; ++k)		// 첫 주소를 포인터로 바꾸고 1차원 배열처럼 사용할 수 있다.
    	printf("%d ", ptr[k]);
    printf("\n\n");

    printf("%zd %zd\n", sizeof(arr), sizeof(arr[0]));	// arr[0]은 3개 짜리의 크기이므로 12byte이다.
    printf("\n");

    /* 3D array(참고용) */

    int arr_3d[2][3][4] = {
    						{
    							{000, 001, 002, 003},
    							{010, 011, 012, 013},
    							{020, 021, 022, 023},
    													},
    						{
    							{100, 101, 102, 103},
    							{110, 111, 112, 113},
    							{120, 121, 122, 123},
    													}
    														};
    for (int k = 0; k < 2; ++k) {
    	for (int j = 0; j < 3; ++j) {
    		for (int i = 0; i < 4; ++i)
    			printf("%d ", arr_3d[k][j][i]);
    		printf("\n");
    	}
    	printf("\n");
    }

    return 0;
}
