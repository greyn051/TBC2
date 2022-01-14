/*
## 9.10 피보나치(Fibonacci) 예제와 재귀 호출의 장단점
*/

// 피보나치 수열 출력하는 프로그램


// ※ 내 코드
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
	ex) fibonacci(6) = 8 = 5 + 3 = fibonacci(5) + fibonacci(4)
*/

int fibonacci(int number);

int main() {

    for (int count = 1; count < 13; ++count)
    	printf("%d ", fibonacci(count));

    return 0;
}

int fibonacci(int number) {

	if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 1;
	}
	else if (number > 2) {

		return fibonacci(number - 2) + fibonacci(number - 1);
	}
	else {
		printf("error 1");
		exit(1);
	}
}


// ※ 교수님 코드
#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
	ex) fibonacci(6) = 8 = 5 + 3 = fibonacci(5) + fibonacci(4)
*/

int fibonacci(int number);

int main() {

    for (int count = 1; count < 13; ++count)
    	printf("%d ", fibonacci(count));

    return 0;
}

int fibonacci(int number) {

	if (number > 2)
		return fibonacci(number - 1) + fibonacci(number - 2); // double recursion
	else
		return 1;
}

//Note: memory (in)efficiency, redundant computation



/*********************************************************
*********************************************************/

/*
숫자 늘어날 때 마다 미리 이전에 계산한 것을 사용하지 못하고 다시 계산해서 구현하게 된다.
(호출이 얼마나 중복되는지 볼 수 있다)
*/

#include <stdio.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
	ex) fibonacci(6) = 8 = 5 + 3 = fibonacci(5) + fibonacci(4)
*/

int fibonacci(int number);

int main() {

	for (int count = 1; count < 13; ++count)
		printf("%d ", fibonacci(count));

	return 0;
}

int fibonacci(int number) {

	printf("fibonacci with %d\n", number);

	if (number > 2)
		return fibonacci(number - 1) + fibonacci(number - 2); // double recursion
	else
		return 1;
}

//Note: memory (in)efficiency, redundant computation
