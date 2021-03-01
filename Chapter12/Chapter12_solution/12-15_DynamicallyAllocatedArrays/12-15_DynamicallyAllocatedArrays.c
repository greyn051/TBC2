#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	/*
		One variable
		동적 할당 메모리를 변수 하나처럼 사용
		마치 어떤 변수에 대한 포인터를 알고 있는 것과 비슷
	*/

	int* ptr = NULL;

	ptr = (int*)malloc(sizeof(int) * 1);
	if (!ptr) exit(1);

	*ptr = 1024 * 3;	// indirection
	printf("%d\n", *ptr);

	free(ptr);
	ptr = NULL;

	/*
		1D array
	*/

	int n = 3;
	int * ptr = (int*)malloc(sizeof(int) * n);
	if (!ptr) exit(1);

	ptr[0] = 123;	// 배열과 유사하게 사용 가능
	*(ptr + 1) = 456;	// 포인터 연산을 이용해서 값을 읽거나 저장 가능
	*(ptr + 2) = 789;
	// (int*)로 형변환을 했기 때문에 이런식으로 포인터 연산 가능

	free(ptr);
	ptr = NULL;

	/*
		x64에서 heap 메모리가 매우 크기 때문에 
		어마어마하게 큰 메모리 다룰 때는 
		배열보다 동적할당 메모리 사용
	*/

	/*
		2D array
	*/

	int row = 3, col = 2;
	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);	// constant 밖에 못 쓰면 동적 할당의 의미 퇴색
	//int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);	// VLA(col 변수로 하려면 compiler가 VLA 지원해줘야함)
	if (!ptr2d) exit(1);

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			ptr2d[r][c] = c + col * r;

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < col; c++)
			printf("%d ", ptr2d[r][c]);
		printf("\n");
	}

	/*
		실용적인 측면

		Using 1D arrays as 2D arrays

		row = 3, col = 2

		(r, c)

		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)

		1D(한 줄로 나열하면)
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
		0	   1	  2		 3	    4	   5	   = c + col * r
		(밑에 숫자는 index)

	*/

	int row = 3, col = 2;
	int* ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr) exit(1);

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			ptr[c + col * r] = c + col * r;

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++)
			printf("%d ", *(ptr + c + col * r));
		printf("\n");
	}

	/*
		실용적인 측면(결국 우리가 사용하는 컴퓨터 메모리의 구조는 1차원이므로)

		Using 1D arrays as 3D arrays

		row = 3, col = 2, depth = 2

		(r, c, d)

		3D
		-------------------
		(0, 0, 0) (0, 1, 0)
		(1, 0, 0) (1, 1, 0)
		(2, 0, 0) (2, 1, 0)
		-------------------
		(0, 0, 1) (0, 1, 1)
		(1, 0, 1) (1, 1, 1)
		(2, 0, 1) (2, 1, 1)
		-------------------

		1D
		(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1) (1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1) 
		0		  1			2		  3			4		  5			6		  7			8		  9			10		  11			
		= c + col * r + (col*row) * d
		= 1 + 2 * 1 + (3*2) * 1 = 1 + 2 + 6 = 9
		(3차원 idexing을 1차원으로 바꾸기)
		(4, 5차원 등등 다 가능)

		if 4차원(4차원 부터는 그림으로 설명하기 어렵다. 머리 속으로 추상적으로 상상해야함)
		row, col, depth, height
		(r, c, d, h)
		index = c + col * r + (col*row) * d + (row*col*depth) * h
	*/

	int row = 3, col = 2, depth = 2;
	int* ptr = (int*)malloc(row * col * depth * sizeof(int));
	if (!ptr) exit(1);

	for (int d = 0; d < depth; d++)
		for (int r = 0; r < row; r++)
			for (int c = 0; c < col; c++)
				ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;

	/*
	* 매번 위 처럼 코딩하기 쉽지 않으므로 함수를 만들어서 쓰자
	
		int idx2(int c, int r)
		{
			return c + col * r;
		}

		int idx3(int c, int r, int d)
		{
			static const int cr = col * row;	// col * row하는 시간 아까우면(연산 시간 줄이고 싶으면) static 사용
			return c + col * r + cr * d;
		}
	*/

	// 출력
	for (int d = 0; d < depth; d++) {
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++)
				printf("%d ", *(ptr + c + col * r + (col * row) * d));
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
