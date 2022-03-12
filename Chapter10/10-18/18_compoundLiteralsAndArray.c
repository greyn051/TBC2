/*
## 10.18 복합 리터럴(Compound Literals)과 배열
*/

#include <stdio.h>

#define COLS 4

int sum_1d(int arr[], int n); // 1차원 배열의 원소들을 더하는 함수
int sum_2d(int arr[][cols], int rows); // 2차원 배열의 원소들을 더하는 함수

int main() {

    int a = 1;
    3;		// Literal are constants that aren't symbolic
    3.14f;
    int b[2] = { 3, 4 };	// 이런 형태를 복합 리터럴 이라고 한다.(여러개의 리터럴이 있으므로)
    (int[2]) {3, 4};		// compound literal(배열을 compoud literal로 표현)(위에는 b라는 array의 이름이 있었음)

    //int c[2] = (int[2]){ 3, 4 };	// Error // 복합 리터럴로 배열을 초기화 할 수 없다

    int arr1[2] = { 1, 2 };
    int arr2[2][COLS] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

    printf("%d\n", sum_1d(arr1, 2));
    printf("%d\n", sum_2d(arr2, 2));
    printf("\n");

    printf("%d\n", sum_1d((int[2]) { 1, 2 }, 2));
    printf("%d\n", sum_2d((int[2][COLS]) { {1, 2, 3, 4}, {5, 6, 7, 8} }, 2));
    printf("\n");
    // compound literal을 함수에 argument로 보낼 수 있다.

    int* ptr1;
    int(*ptr2)[COLS];	// COLS 만큼 원소를 같은 배열에 대한 포인터

    ptr1 = (int[2]){ 1, 2 };
    ptr2 = (int[2][COLS]){ {1, 2, 3, 4}, {5, 6, 7, 8} };

    printf("%d\n", sum_1d(ptr1, 2));
    printf("%d\n", sum_2d(ptr2, 2));
    printf("\n");
    // 포인터에 복합 리터럴을 바로 대입할 수 있다.

    return 0;
}

int sum_1d(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; ++i)
    total += arr[i];
    return total;
}

int sum_2d(int arr[][cols], int rows) {

    int total = 0;
    for (int r = 0; r < rows; r++)
    	for (int c = 0; c < COLS; c++)
    		total += arr[r][c];
    return total;
}
