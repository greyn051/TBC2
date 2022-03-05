/*
## 10.16 다차원 배열(Multidimensional Arrays)을 함수에게 전달해주는 방법
*/

#include <stdio.h>

#define ROWS 3
#define COLS 4

int sum2d_1(int ar[ROWS][cols]);
int sum2d_2(int ar[][cols], int row); // 프로토 타입에 가장 왼쪽의 index만 생략 가능하고 나머지는 써야한다.
//int sum2d_2(int [][cols], int row);
//int sum2d_2(int (_ar)[COLS], int row); // ar is a SINGLE pointer to the array of COLS ints
int sum2d_3(int_ ar, int row, int col); // 딥러닝(컴퓨터 비전) 같은 것을 한다면 매우 높은 차원의 배열을 이런 식으로 사용한다.
//int sum2d_3(int\*, int, int);

int main() {

    int data[ROWS][COLS] = {
    							{1, 2, 3, 4},
    							{5, 6, 7, 8},
    							{9, 0, 1, 2}
    											};
    printf("%d\n", data[2][3]);

    int* ptr = &data[0][0];
    printf("%d\n", *(ptr + 3 + COLS * 2));	// column의 수를 2배하면 2개의 row를 뛴 것과 같다.

    printf("Sum of all elements = %d\n", sum2d_1(data));
    printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));

    return 0;
}

int sum2d_1(int ar[ROWS][cols]) {
int r, c, tot = 0;
for (r = 0; r < ROWS; r++)
for (c = 0; c < COLS; c++) // 오른쪽에 있는 차원(c)에 대해서 안 쪽으로 도는 것이 좋다.
tot += ar[r][c];
return tot;
}

int sum2d_2(int ar[][cols], int row) {
int r, c, tot = 0;
for (r = 0; r < row; r++)
for (c = 0; c < COLS; c++)
tot += ar[r][c];
return tot;
}

int sum2d_3(int* ar, int row, int col) {
int r, c, tot = 0;
for (r = 0; r < row; r++)
for (c = 0; c < col; c++)
tot += *(ar + c + col _ r); // ar[c + col _ r]
return tot;
}

/*
    In higher dimensions,
    you may omit the value in the left-most bracket

    int my_function(int ar[][3][5][8], int rows);	 // 고차원 배열인 경우, 가장 왼쪽 차원은 숫자를 넣으나 마나 이다.(몇 개인지 따로 변수를 넣어주는 것이 일반적)
    int my_function(int (*ar)[][3][5][8], int rows);
*/
