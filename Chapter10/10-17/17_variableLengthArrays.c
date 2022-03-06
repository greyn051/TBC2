/*
## 10.17 변수로 길이를 정할 수 있는 배열(Variable-Length Arrays (VLAs))
*/

#include <stdio.h>

int main() {

    int n = 5;
    float my_arr[n];	// 가변길이배열은 VS에서 지원을 하지 않는다.

    return 0;
}

/*
그러니 온라인 compiler로 실습하자(repl.it 같은 것)
(online copiler gcc 검색)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_4(int row, int col, int ar[row][col]);

int main() {

    int n;

    printf("Input array length : ");
    scanf("%d", &n);

    // int n = 7;
    float my_arr[n]; // Note: cannot change length after declaration

    for (int i = 0; i < n; ++i)
    	my_arr[i] = (float)i;

    for (int i = 0; i < n; ++i)
    	printf("%f\n", my_arr[i]);

    int data[ROWS][COLS] = {
    			{1, 2, 3, 4},
    			{5, 6, 7, 8},
    			{9, 0, 1, 2}
    					};

    printf("%d\n", sum2d_4(ROWS, COLS, data));	// 숫자를 넣어도 되고 변수를 넣어도 된다.

    return 0;
}

int sum2d_4(int row, int col, int ar[row][col]) // 이렇게 하면 매크로를 덜 사용할 수 있어서 간결하다.(함수의 기능이 매개변수 만으로도 설명이 가능)
{
    //printf("%zd\n", sizeof(ar));
    //printf("%zd\n", sizeof(ar[0]));
    int r, c, tot = 0;
    for (r = 0; r < row; r++)
    for (c = 0; c < col; c++)
    tot += ar[r][c];
    return tot;
}
