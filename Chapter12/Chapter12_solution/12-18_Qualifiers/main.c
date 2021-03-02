#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// memcpy
#include "constants.h"

//const double gravity = 9.8;
//const double PI = 3.141592;

int main() {

	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/

	/*
		const
	*/

	// C99 ideompotent	// 여러개 써도 된다는 뜻
	const const const int n = 6;	// const int n = 6;

	// type define
	typedef const int zip;	// const int를 zip이라는 type으로 내가 정의
	const zip q = 8;	// const const int zip
	// 이런 경우 대비해서 ideompotent

	//const int i;	// Not initialized!
	//i = 12;	// Error
	//printf("%d\n", i);	// Error

	const int j = 123;
	const int arr[] = { 1, 2, 3 };

	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;
	//*pf1 = 5.0f;	// Error
	pf1 = &f2;		// Allowed
	// pf1이라는 포인터 변수 자체는 다른 값을 가질 수 있다

	float* const pf2 = &f1;
	*pf2 = 6.0f;	// Allowed
	//pf2 = &f2;	// Error

	const float* const pf3 = &f1;
	//*pf3 = 7.0f;	// Error
	//pf3 = &pf2;	// Error

	/*
		Global constants

		위에
		const double gravity = 9.8;
		const double PI = 3.141592;

		constant를 header file에 넣어서 편리하게 사용 가능
		#include "constants.h"
	*/

	double area_circle = PI * 2.0f * 2.0f;

	/*
		volatile
		- Do not optimize	(컴파일러야 최적화 하지 마라) (임시공간 등으로 보내서 속도 빠르게 cashing)
		- (ex: hardward clock)

		휘발성, 불안정한 의미
		컴파일러가 모르는 상황에서 값이 바뀔 수 있다고 표기
		(컴파일러가 알 수 없는 이유로 값이 바뀔 수 있다는 의미)
	*/

	volatile int vi = 1;	// volatile location
	volatile int* pvi = &vi;	// points to a volatile location

	int i1 = vi;

	// ...

	int i2 = vi;

	/*
		restrict (__restrict in VS)
		- sole initial means of accessing a data object
		- compiler can't check this restriction
	*/

	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* par = ar;

	
	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)exit(1);
	/*
		동적할당 받아 온 메모리를 다른 수단(다른 포인터 등)을 이용해서 접근하지 않겠다.
		restar을 통해서만 접근하겠다. 라는 의미
	*/

	// array를 통해서 값을 바꾸는 것과 pointer를 통해서 값을 바꾸는 것은 동일
	ar[0] += 3;
	par[0] += 5;
	// par[0] += 8;	// 위 2개를 합치면 8을 한 번에 더하는 것과 같음
	// 하지만 array와 pointer는 서로 다르기 때문에 한 번에 더하는 최적화 불가

	restar[0] += 3;
	restar[0] += 5;
	//restar[0] += 8;	// Equalivalent
	// 위와는 달리 컴파일러가 한 번에 8을 더하는 최적화를 해줄 수도 있다.
	// (__restrict가 최적화를 도와주는 역할)
	/*
		하지만 컴파일러가 정말로 restrict가 지켜지고 있는지
		(정말 restar만이 restrict인지) 확인할 수 없다.
		compiler can't check this restriction
	*/

	free(restar);

	return 0;
}
