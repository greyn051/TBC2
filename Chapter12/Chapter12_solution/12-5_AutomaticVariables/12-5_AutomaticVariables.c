#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Automatic storage class
	- Automatic storage duration, block scope, no linkage
	- Any variable declared in a block or function header
*/

void func(int k);

int main()	// Note: main() is a function.
{
	auto int a;	// keyword auto : a storage-class specifier(거의 사용x, C++에서는 auto keyword가 완전 다른 뜻을 가진다)
	a = 1024;
	//printf("%d\n", a);		// what happens if uninitialized?
	//auto int b = a * 3;		// what happens if uninitialized?
	/*
		자동변수는 빈번하게 사용되기 때문에 초기화를 해줘야한다.
		컴파일러가 자동변수는 초기화 해주지 않음
		(자동변수를 전역변수와 같이 매번 컴파일러가 0으로 초기화해주면 효율이 좋지 않으므로)
	*/

	int i = 1;
	int j = 2;

	printf("i %lld\n", (long long)&i);

	{
		// 영역이 바뀌면 똑같은 identifier 가능
		int i = 3;	// name hiding(더 큰 영역에서 선언이 된 identifier는 hiding된다.)
		printf("i %lld\n", (long long)&i);
		// C언어에서 identifier이 같을 경우 가장 안 쪽 영역에 있는 것을 선택

		// j is visible here
		printf("j = %d\n", j);	// 더 큰 영역에 있는 j 그대로 사용

		int ii = 123;
	}
	// ii is not visible here

	printf("i %lld\n", (long long)&i);	// which i?

	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m);		// no block?	
	// block이 없어도 m을 바로 위까지만 사용 가능

	func(5);	// cannot see any of the variabled defined so far.

	for (int m = 3; m < 4; m++) {
		printf("m %lld\n", (long long)&m);		// block?
	}
	// block이 끝날 때 까지 m 사용 가능

	return 0;
}

void func(int k) {

	int i = k * 2;
	// do something with i and k
	printf("i %lld\n", (long long)&i);
}
/*
	이 function이 호출되면 stack frame이 자체가 바뀌어 버리므로 
	지금 까지 써온 변수들 쓸 수 없다.
	(main 함수 안에 있는 i, j에 접근할 수 없다)
*/
