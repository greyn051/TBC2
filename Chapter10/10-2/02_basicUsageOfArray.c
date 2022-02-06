/*
## 10.2 배열의 기본적인 사용방법
*/

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	/* Basic usage */
	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	for (int i = 0; i < MONTHS; ++i)
		printf("%d ", high[i]);
	printf("\n");

	float avg = 0.0;
	for (int i = 0; i < MONTHS; ++i)
		avg += high[i];
	printf("Average = %f\n", avg / (float)MONTHS);

	high[0] = 1;
	high[1] = 2;
	//high = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // Not working
	//high[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }; // Not working
	/*
		배열은 일단 선언이 한 번 끝나면 값 여러개를 다시 나열해서 한 번에대입할 수 없다.
	*/

	/* Addresses */
	printf("%p %p\n", high, &high[0]);
	for (int i = 0; i < MONTHS; ++i)
		printf("%lld\n", (long long)&high[i]);	// 주소 10진수로 바꿀 때 long long으로 casting(x64 대비), 숫자가 4씩 증가한다.
	printf("\n");

	return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Compiler doesn't check whether indices are valid. */
	high[12] = 4; //Error // index를 우리가 사용할 수 있는 범위 넘어서 사용하면 문제가 생김
	high[-1] = 123; //Error // index가 음수일 때도 문제가 생김
	/* 무서운 점은 compiler가 위 오류는 잡지 못한다. */

	return 0;
}


/*********************************************************
*********************************************************/


// const와 배열 같이 사용하기

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* const and array */
	const int temp = 0;
	temp = 4; // 불가능

	const int low[12] = { -7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, 05 };
	low[0] = 123;

	return 0;
}


/*********************************************************
*********************************************************/


#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* When array is not initialized */
	int not_init[4];	//TODO: try static
	for (int i = 0; i < 4; ++i)
		printf("%d\n", not_init[i]);

	return 0;
}

// 위에서 try static 한다면

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* When array is not initialized */
	static int not_init[4];	 //TODO: try static (storage class)
	for (int i = 0; i < 4; ++i)
		printf("%d\n", not_init[i]);

	return 0;
}


/*********************************************************
*********************************************************/


// 부족하게 배열 초기화를 한다면

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Partially initialized */
	int insuff[4] = { 2, 4 };
	for (int i = 0; i < 4; ++i)
		printf("%d\n", insuff[i]);

	return 0;
}


/*********************************************************
*********************************************************/


// 과하게 많이 초기화

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Overlly initialized */
	int over[2] = { 2, 4, 8, 16 };

	return 0;
}


/*********************************************************
*********************************************************/


/*
어레이의 사이즈 지정 안 하고 정의(index에 값 안 넣음)
그리고 여기서 for문 사용하는 방법
*/

#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Omitting size */
	const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };
	printf("%d\n", sizeof(power_of_twos));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(power_of_twos[0]));

	for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
		printf("%d ", power_of_twos[i]);

	return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Designated initializers */
	int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	for (int i = 0; i < MONTHS; ++i)

	return 0;
}


/*********************************************************
*********************************************************/


#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Specifying Array sizes */
	int arr1[MONTHS];	// Symbolic integer constant
	double arr2[123];	// Literal integer constant
	float arr3[3 * 4 + 1];
	float arr4[sizeof(int) + 1];
	//float arr5[-10];		// No
	//float arr6[0];		// No
	//float arr7[1.5];		// No
	float arr8[(int)1.5];	// Yes

	//int n = 8;
	//float arr9[n];		// Variable-Length Array is optional from C11

	return 0;
}
