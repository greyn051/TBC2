# TBC-10 배열과 포인터

## 10.1 배열(Array)과 메모리

//

## 10.2 배열의 기본적인 사용방법

```c
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
```

//

```c
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
```

//
const와 배열 같이 사용하기

```c
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
```

//

```c
#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* When array is not initialized */
	int not_init[4];	//TODO: try static
	for (int i = 0; i < 4; ++i)
		printf("%d\n", not_init[i]);

	return 0;
}
```

// 위에서 try static 한다면

```c
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
```

//
부족하게 배열 초기화를 한다면

```c
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
```

//
과하게 많이 초기화

```c
#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Overlly initialized */
	int over[2] = { 2, 4, 8, 16 };

	return 0;
}
```

//
어레이의 사이즈 지정 안 하고 정의(index에 값 안 넣음)
그리고 여기서 for문 사용하는 방법

```c
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
```

//

```c
#include <stdio.h>

#define MONTHS 12	// symbolic constant, macro

int main() {

	int high[MONTHS] = { 2, 5, 11, 18, 23, 27, 29, 30, 26, 20, 12, 4 };

	/* Designated initializers */
	int days[MONTHS] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	for (int i = 0; i < MONTHS; ++i)

	return 0;
}
```

//

```c
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
```

//
## 10.3 포인터의 산술 연산(Pointer Arithmetic)
```c
#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    return 0;
}
```
각 자료형 원소들이 가지는 데이터 사이즈 알 수 있다. -도 가능

//
포인터에서 단항 연산은 막아두었다.
(주소를 음수로 바꿀 이유가 없기 때문)
```c
#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    return 0;
}
```
//
포인터 주소끼리 더하는 것은 안 된다.(의미가 없어서)
다만 빼기는 된다.(주소 간의 차이를 나타내므로 이용 가능)
```c
#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    /* Subtraction */
    int arr[10];
    int* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;	// Not working
    int i = ptr2 - ptr1;	// meaning? // 주소 간의 차이를 나타내므로 이용 가능

    printf("%p %p %d\n", ptr1, ptr2, i);

    return 0;
}
```
//
10진수로도 보자
```c
#include <stdio.h>

int main() {

    int* ptr = 0; // try double*, long long*, char*, void*
    //int* ptr = (int*)0; // 엄밀하게 하면 이렇게 casting하지만 이렇게 까지는 안 함

    //printf("%d", *ptr); //Error in this lecture

    printf("%p %lld\n", ptr, (long long)ptr);

    ptr += 1; // try -=, ++, --, -, +

    printf("%p %lld\n", ptr, (long long)ptr);

    //ptr = -ptr; // Not working
    //ptr = +ptr; // Not working

    /* Subtraction */
    int arr[10];
    int* ptr1 = &arr[3], * ptr2 = &arr[5];

    //ptr2 = ptr1 + ptr2;	// Not working
    int i = ptr2 - ptr1;	// meaning? // 주소 간의 차이를 나타내므로 이용 가능

    printf("%lld %lld %d\n", (long long)ptr1, (long long)ptr2, i);

    return 0;
}
```
//
## 10.4 포인터와 배열
```c
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
```
//
```c
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
```
//


## 10.5 2차원 배열과 메모리

```c
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
```
//

## 10.6 2차원 배열 연습문제
```c
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main() {

    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2,	6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

    /*
    1. Use 2D array
    2. Print data
    3. Calculate and print yearly average temperature of 3 years
    4. Calculate and print monthly average temperatures for 3 years
    */

    return 0;
}
```
※ 내 코드
```c
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main() {

    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

    /*
    1. Use 2D array
    2. Print data
    3. Calculate and print yearly average temperature of 3 years
    4. Calculate and print monthly average temperatures for 3 years
    */

    double yearTemp[YEARS][MONTHS] = { { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
    								   { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
    								   { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 } };

    printf("[Temperature Data]\n");
    printf("Year index :\t");
    for (int i = 1; i < (MONTHS + 1); ++i) {
    	printf("%d\t", i);
    }
    printf("\n");

    for (int j = 0; j < YEARS; ++j) {
    	printf("Year %d     :\t", j);
    	for (int i = 0; i < MONTHS; ++i) {
    		printf("%.1lf\t", yearTemp[j][i]);
    	}
    	printf("\n");
    }

    double yearlyTempSum[3] = { 0 };

    printf("\n[Yearly average temperatures of 3 years]\n");

    for (int j = 0; j < YEARS; ++j) {

    	printf("Year %d : average temperature = ", j);

    	for (int i = 0; i < MONTHS; ++i) {
    		yearlyTempSum[j] += yearTemp[j][i];
    	}

    	printf("%.1lf", yearlyTempSum[j] / MONTHS);
    	printf("\n");
    }

    printf("\n[Monthly average temperatures for 3 years]\n");
    printf("Year index :\t");
    for (int i = 1; i < (MONTHS + 1); ++i) {
    	printf("%d\t", i);
    }
    printf("\n");

    double monthlyTempSum[12] = { 0 };

    printf("Avg temps  :\t");
    for (int i = 0; i < MONTHS; ++i) {
    	for (int j = 0; j < YEARS; ++j) {
    		monthlyTempSum[i] += yearTemp[j][i];
    	}
    	printf("%.1lf\t", monthlyTempSum[i] / YEARS);
    }

    printf("\n");

    return 0;
}
```
※ 교수님 코드
```c
#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main() {

    double year2016[MONTHS] = { -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 };
    double year2017[MONTHS] = { -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 };
    double year2018[MONTHS] = { -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 };

    /*
    1. Use 2D array
    2. Print data
    3. Calculate and print yearly average temperature of 3 years
    4. Calculate and print monthly average temperatures for 3 years
    */

    double temp_data[YEARS][MONTHS] = {
    	{ -3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2 },
    	{ -1.8, -0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9 },
    	{ -4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6 }
    };

    /* Step */
    printf("[Temperature Data]\n");

    printf("Year index : ");
    for (int m = 0; m < MONTHS; ++m) {
    	printf("\t%d ", m + 1);
    }
    printf("\n");

    for (int y = 0; y < YEARS; ++y) {
    	printf("Year %d	   : ", y);
    	for (int m = 0; m < MONTHS; ++m) {
    		printf("\t%.1f", temp_data[y][m]);
    	}
    	printf("\n");
    }
    printf("\n");

    /* Step 3 */
    printf("[Yearly average temperatures of 3 years]\n");
    for (int y = 0; y < YEARS; ++y) {
    	double avg_temp = 0.0;

    	for (int m = 0; m < MONTHS; ++m)
    		avg_temp += temp_data[y][m];

    	avg_temp /= (double)MONTHS;

    	printf("Year %d : average temperature = %.1f\n", y, avg_temp);
    }
    printf("\n");

    /* Step 4 */
    printf("[Monthly average temperatures for 3 years]\n");
    printf("Year index : ");
    for (int m = 0; m < MONTHS; ++m) {
    	printf("\t%d ", m + 1);
    }
    printf("\n");

    printf("Avg temps  : ");
    for (int m = 0; m < MONTHS; ++m) {
    	double avg_temp = 0;
    	for (int y = 0; y < YEARS; ++y) {
    		avg_temp += temp_data[y][m];
    	}
    	avg_temp /= (double)YEARS;
    	printf("\t%.1f ", avg_temp);
    }
    printf("\n");

    return 0;
}
```
//

## 10.7 배열을 함수에게 전달해주는 방법
```c
#include <stdio.h>

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    //double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    printf("Avg = %f\n", avg);

    return 0;
}
```
//
avg2 만들기 위해 함수 만들자
```c
#include <stdio.h>

double average(double arr1[5]) {

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;
}

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    //double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different // 만약 arr2의 배열이 3개라면 avg함수 안 된다.

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));

    printf("Avg = %f\n", average(arr1));
    printf("Avg = %f\n", average(arr2));

    return 0;
}
```
//
함수에 들어가는 배열의 사이즈 확인
```c
#include <stdio.h>

double average(double arr1[5]) {

    printf("Size = %zd in function average\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;
}

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));

    printf("Avg = %f\n", average(arr1));
    printf("Avg = %f\n", average(arr2));

    return 0;
}
```
//
⭐함수에서 배열을 받을 때는 포인터로 받는다!
```c
double average(double \*arr1) // (double arr1)해도 된다.
{
printf("Size = %zd in function average\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;

}
```
//
완벽하게 입력한 경우
(함수에 매개변수 사용해서 일반화, 함수에 들어가는 배열에 index 안 씀)
```c
#include <stdio.h>

double average(double data_array[], int n);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));

    printf("Avg = %f\n", average(arr1, 5));
    printf("Avg = %f\n", average(arr2, 3));

    return 0;
}

double average(double data_array[], int n) {

    printf("Size = %zd in function average\n", sizeof(data_array));

    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
    	avg += data_array[i];
    }
    avg /= (double)n;

    return avg;
}

/*
    위 함수를 선언할 때 이렇게 4가지 경우로 선언할 수 있다.

    double average(double *arr, int n); // 보통 이렇게 포인터로 쓴다
    double average(double _, int n); // 보통 이렇게 하면 알아본다.(뒤에 변수 들어온거 보고 배열인거 알 수 있음)
    double average(double arr[], int n);
    double average(double [], int n);
*/
```
//
## 10.8 두 개의 포인터로 배열을 함수에게 전달해주는 방법
```c
#include <stdio.h>

double average(double*, double*);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };

    printf("Avg = %f\n", average(arr1, arr1 + 5)); 	// 포인터 산술 연산

    return 0;
}

double average(double* start, double* end) {

    int count = 0;
    double avg = 0.0;
    while (start < end) {
    	avg += *start++;
    	count++;
    }
    avg /= (double)count;

    return avg;
}
```
//
while문에서 개수 세는게 부담스러울 수 있으니
함수 안에서 포인터끼리 빼서 구한다.
```c
#include <stdio.h>

double average(double*, double*);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };

    printf("Avg = %f\n", average(arr1, arr1 + 5));

    return 0;
}

double average(double* start, double* end) {

    int count = end - start;
    double avg = 0.0;
    while (start < end) {
    	avg += *start++;
    	//count++;
    }
    avg /= (double)count;
    printf("%d\n", count);
    return avg;
}
```
//
## 10.9 포인터 연산 총정리
```c
#include <stdio.h>

int main() {

    /*
    Pointer operations
    - Assignment
    - Value finding (deferencing)
    - Taking a pointer address
    - Adding an integer to a pointer
    - Incrementing a pointer
    - Subtracting an integer from a pointer
    - Decrementing a pointer
    - Differencing
    - Comparisons
    */

    int arr[5] = { 100, 200, 300, 400, 500 };
    int* ptr1, * ptr2, * ptr3;

    ptr1 = arr;		// Assignment

    printf("%p %d %p\n", ptr1, *ptr1, &ptr1);// dereferencing, Taking a pointer address

    ptr2 = &arr[2]; // Address-of operator &

    printf("%p %d %p\n", ptr2, *ptr2, &ptr2);

    ptr3 = ptr1 + 4;// Adding an integer from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    //Differencing
    printf("%td\n", ptr3 - ptr1);	//Note: t is for pointer difference (printf에서 t가 들어간 형식지정자는 포인터의 차이값을 받아서 출력할 때 사용한다.)

    ptr3 = ptr3 - 4;// Subtracting an integer from a pointer

    printf("%p %d %p\n", ptr3, *ptr3, &ptr3);

    ptr1++;			// Incrementing, ptr1 = ptr1 + 1
    ptr1--;			// Decrementing
    --ptr1;
    ++ptr1;

    if (ptr1 == ptr3)
    	printf("Same\n");
    else
    	printf("Different\n");

    double d = 3.14;
    double* ptr_d = &d;
    if (ptr1 == ptr_d)	// warning C4133: '==': incompatible types - from 'double *' to 'int *' // 둘 다 주소라 메모리 크기는 같은데 타입이 달라서 error가 아니라 warning을 띄워준다. (int*)붙이면 안 뜸
    	printf("Same\n");
    else
    	printf("Different\n");

    return 0;
}
```
//

## 10.10 const와 배열과 포인터
```c
#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[3] = { 1.0, 2.0, 3.0 };
    //arr2[0] = 100.0;

    double* pd = arr2; // 여기서 문제점이 위에 이미 배열에 const 넣었는데 포인터를 통하면 값을 바꿀 수 있어진다. 그래서 이런 방식 쓰는거 매우 안 좋음
    *pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    pd[2] = 1024.0; // arr2[2] = 4.0; (pd는 포인터인데 배열처럼 사용가능)

    printf("%f %f", pd[2], arr2[2]);

    pd++; // allowed

    return 0;
}
```
//
```c
#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
    //arr2[0] = 100.0;

    const double* pd = arr2;
    //*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    //pd[2] = 1024.0; // arr2[2] = 4.0;

    printf("%f %f\n", pd[2], arr2[2]);

    pd++; // allowed (const해도 증가연산자는 된다) > 포인터 자체값인 주소를 바꿀 수 있다는 말임

    printf("%f %f\n", pd[2], arr2[2]);

    return 0;
}
```
// pd++;도 막기위해서는 뭘 해야할까
```c
#include <stdio.h>

int main() {

    // type qualifiers: const, volatile, ...

    const double PI = 3.14159;
    //PI = 2.14159;

    const int arr[5] = { 1, 2, 3, 4, 5 };
    //arr[1] = 123;

    const double arr2[4] = { 1.0, 2.0, 3.0, 4.0 };
    //arr2[0] = 100.0;

    const double* const pd = arr2;
    //*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    //pd[2] = 1024.0; // arr2[2] = 4.0;

    printf("%f %f\n", pd[2], arr2[2]);

    //pd++; // allowed

    printf("%f %f\n", pd[2], arr2[2]);

    return 0;
}
```
포인터의 변수명 앞에 const를 더 붙인다.

//

const double\* pd = arr2;
에서는 포인터가 가리키는 메모리 값을 못 바꾼다.

double\* const pd = arr2;
에서는 포인터 변수 값 자체를 못 바꾼다.(주소값 못 바꿈)

const double\* const pd = arr2; 쓰면 둘 다 못 바꿈

//
## 10.11 배열 매개변수와 const

함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
```c
#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], int n, int val) // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); // 원소가 몇 개 인지

    print_array(arr, 5);
    add_value(arr, 5, 100); // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
    print_array(arr, 5);

    return 0;
}
```
//
sum만 구하는게 목표였는데 배열의 값이 변했다.(의도하지 않음)
```c
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], int n, int val) // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); // 원소가 몇 개 인지

    print_array(arr, 5);
    add_value(arr, 5, 100); // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
    print_array(arr, 5);

    int s = sum(arr, n);

    printf("sum is %d\n", s);
    print_array(arr, 5);

    return 0;
}
```
++한 부분을 지우면 해결되겠지만 프로그래머들은 이러한 실수를 항상 할 수도 있다고 가정을 해야한다.
//
그래서 예비책으로 함수에 입력되는 배열에 const를 붙여준다.
```c
int sum(const int ar[], const int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;

}
```
const를 썼기 때문에 compile이 안 된다. > 실수를 찾을 수 있다.
//
sum 함수를 고쳐서 배열의 값이 변하지 않게 수정,
const를 붙일 수 있는 곳에 다 붙이기
```c
#include <stdio.h>

void print_array(const int arr[], const int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], const int n, const int val) // 배열의 값을 더하는 것이 목적이기 때문에 배열에 const를 붙이면 안 된다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(const int ar[], const int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i];

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 }; // add_value 함수 때문에 const를 붙이면 안 된다.
    const int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, 5);
    add_value(arr, 5, 100);
    print_array(arr, 5);

    int s = sum(arr, n);

    printf("sum is %d\n", s);
    print_array(arr, 5);

    return 0;
}
```
//

## 10.12 포인터에 대한 포인터(2중 포인터)의 작동 원리

//
## 10.13 포인터의 배열과 2차원 배열
```c
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
```
//
```c
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
```
//
```c
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
```
//
위와 같은 예제인데 형태만 바꿈
```c
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
```
//
```c
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
```
//
```c
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
```
//
```c
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
```
//

## 10.14 2차원 배열과 포인터
```c
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
```
//
```c
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
```
//

## 10.15 포인터의 호환성(Compatibility)
```c
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
```
//
```c
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
```
//
```c
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
```
//
## 10.16 다차원 배열(Multidimensional Arrays)을 함수에게 전달해주는 방법
```c
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
```
//

## 10.17 변수로 길이를 정할 수 있는 배열(Variable-Length Arrays (VLAs))
```c
#include <stdio.h>

int main() {

    int n = 5;
    float my_arr[n];	// 가변길이배열은 VS에서 지원을 하지 않는다.

    return 0;
}
```
// 그러니 온라인 compiler로 실습하자(repl.it 같은 것)
(online copiler gcc 검색)
```c
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
```
//
## 10.18 복합 리터럴(Compound Literals)과 배열
```c
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
```
//
