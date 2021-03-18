# TBC-9 함수

## 9.1 함수가 필요할 때

이름, 사는 곳이 적힌 명함을 출력하는 프로그램 만들기
별은 20개
이름과 주소는 가운데 출력

초보는 이렇게 한다

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	printf("********************\n");
	printf("Name\n");
	printf("Adress\n");
	printf("********************\n");

	return 0;
}
```

//
2개 이상 반복하면 함수로

```c
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	20
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_bar(int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("*");
	printf("\n");

	//printf("********************\n");
}

int main() {

	print_bar(WIDTH);

	printf("   %s\n", NAME);
	printf("   %s\n", ADDRESS);

	print_bar(WIDTH);

	return 0;
}
```

//

별의 개수가 변해도 가운데에 위치하도록 코드 수정하기

😃내 코드

```c
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	30
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_bar(int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("*");
	printf("\n");

	//printf("********************\n");
}

void justify(int n_stars) {
	for (int i = 0; i < ((n_stars / 2) - 7); ++i)
		printf(" ");
}

int main() {

	print_bar(WIDTH);

	justify(WIDTH);
	printf("%s\n", NAME);

	justify(WIDTH);
	printf("%s\n", ADDRESS);

	print_bar(WIDTH);

	return 0;
}
```

😎 교수님 코드

```c
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	30
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)
}

int main() {

	int n_blanks = 0;

	print_multiple_chars('*', WIDTH);
	printf("\n");

	n_blanks = (WIDTH - strlen(NAME)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", NAME);

	n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", ADDRESS);

	print_multiple_chars('*', WIDTH);

	return 0;
}
```

// 위 함수에서 빈칸 생성하는 코드가 중복되니 함수로 바꿔봐

함수에 문자열을 어떻게 받지?

😎교수님 코드

```c
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	25
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)
}

void print_centered_str(char str[])		// width가 코드 전체에서 접근할 수 있으므로 여기선 따로 안 넣어도 됨
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", str);
}

int main() {

	print_multiple_chars('*', WIDTH);
	printf("\n");		// 이거 거슬리면 위에 함수 print_multiple_chars('*', WIDTH, '\n'); 이런 식으로 입력하면 뒤에 추가하도록 바꿀 수도 있음

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH);

	return 0;
}
```

str[] 이용해서 문자열을 받는다.

//
위에 printf("\n"); 없애고 깔끔하게 만들어 보자

```c
#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH	25
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars, bool print_newline) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)

	if (print_newline)
		printf("\n");
}

void print_centered_str(char str[])		// width가 코드 전체에서 접근할 수 있으므로 여기선 따로 안 넣어도 됨
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}

int main() {

	print_multiple_chars('*', WIDTH, true);

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, false);

	return 0;
}
```

//

## 9.2 함수의 프로토타입

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH 25
#define NAME "Jeong-Mo Hong"
#define ADDRESS "Seoul, Korea"

void print_centered_str(char str[]);
void print_multiple_chars(char c, int n_stars, bool print_newline); // prototype

int main() {

    print_multiple_chars('*', WIDTH, true); // argument

    print_centered_str(NAME);
    print_centered_str(ADDRESS);
    print_centered_str("I love you");

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

void print_multiple_chars(char c, int n_stars, bool print_newline) // parameter
{

    for (int i = 0; i < n_stars; ++i)
    	printf("%c", c);	// putchar(c)

    if (print_newline)
    	printf("\n");
}

void print_centered_str(char str[]) {

    int n_blanks = 0;

    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", str);
}
```

//

## 9.3 함수의 자료형과 반환값

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int int_min(int, int);

int main() {

    int i1, i2;

    while (1) {

    	printf("Input two integers : ");

    	if (scanf("%d %d", &i1, &i2) != 2) break;

    	int lesser = int_min(i1, i2);
    	// int lesser = min;
    	printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

    	//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
    }

    printf("End.\n");

    return 0;
}

int int_min(int i, int j)
//int_min(int i, int j)
{
    int min;
    if (i < j)
    min = i;
    else
    min = j;

    return min;

    // return (i < j) ? i : j; // 이거랑 위랑 기능 같음(능숙한 프로그래머는 이것을 선호)

    // return (float)min; // int를 float로 강제로 바꾸는 실험, 하지만 warning이 뜨는 것은 flaot를 int로 바꿀 때 뜬다(return하는 자료형이 int이기 때문)
    ////마치 return (int)((float)min);와 같다.

    /*if (i < j)
    	return i;
    else
    	return j;

    printf("ERROR");
    exit(1);
    */

    //return; // return with no value
}
```

//

## 9.4 변수의 영역(Scope)과 지역 변수(Local Variable)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a;

int int_max(int i, int j);

int int_max(int i, int j) {

    //a = 456;
    int m; // stack frame
    m = i > j ? i : j;
    return m;

}

int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	//int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}
```

여기서 변수 a는 모두 같은 변수인 걸 알 수 있다.
//

```c
int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}
```

큰 영역 안에 다른 영역을 만들고 그 안에 똑같은 이름의 변수를 선언해버리면
각각 다른 변수이다.(메모리 주소가 다르다)

// 추가 예제

```c
int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    b = 456; // int b 영역 밖으로 나왔기 때문에 invisible 하다.

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}
```

//

## 9.5 지역 변수와 스택(Stack)

```c
int int_max(int i, int j) {

    int m;
    m = i > j ? i : j;
    return m;
}

int main() {

    int a;

    a = int_max(1, 2);

    {
    	int b;
    	b = int_max(4, 5);

    	{
    		int b = 123;
    	}

    	{
    		int c = 456;
    	}
    }

    return 0;
}
```

//

## 9.6 재귀 호출(Recursion)

```c
#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, &n);

    my_func(n + 1);		// 자기 자신을 호출하는 구조

    //TODO: stop condition
    //TODO: tail recursion
}
```

//
실전에서 사용하려면
종료 될 조건 같이 사용

```c
#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, &n);

    if(n <= 4)
    	my_func(n + 1);

    printf("Level %d, address of variable n = %p\n", n, &n);

    //TODO: stop condition
    //TODO: tail recursion
}
```

디버그 하면서 이해해봐

//

## 9.7 재귀 호출(Recursion)과 스택(Stack)

```c
#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, (int)& n); // ptr -> int casting

    if(n <= 4)
    	my_func(n + 1);

    printf("Level %d, address of variable n = %p\n", n, (int)& n); // ptr -> int casting
}
```

//

## 9.8 팩토리얼(Factorial) 예제

loop와 recursive를 이용해서 둘 다 구현해봐

※ 내 코드

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;

}

long loop_factorial(int n) {
long factorial = 1;

    for (n; (n > 0); --n) {
    	factorial *= n;
    }

    return factorial;

}

long recursive_factorial(int n) {

    long factorial = 1;

    factorial *= n;

    if (n > 0)
    	recursive_factorial(n - 1);

    return factorial;

}
```

loop_factorial은 구현했는데
recursive_factorial은 어떻게 factorial 계산 식을 넣어야 할지 모르겠음 gg
//
(힌트를 봐도 모르겠다)
아니다 힌트를 보고 직접 풀었다.(이거 안 풀어봤으면 꼭 풀어보라고 하셔서)\*

뭔가 감이 와서 코드를 작성했는데
될 것 같지만 구체적으로 생각을 하기 힘들어서(뇌로만 하니까 과부하와서)
직접 종이에 그리면서 구현해보니 되었다.(아주 좋아)

(Don't Panic의 성과)

※ 힌트를 보고 한 내 코드

```c
#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!		// 이 성질이 recursive에서 힌트
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n) {
long ans;

    for (ans = 1; n > 1; n--) {
    	ans *= n;
    }

    return ans;
}

long recursive_factorial(int n) {

    long ans = n;

    if (n > 0) {
    	//TODO: return ...;

    	ans *= recursive_factorial(n - 1);

    	return ans;		// 여기까지 하고 직접 종이에 그려보았는데 맞는 것 같다.
    }
    else
    	return 1;
}
```

※ 교수님 코드

```c
#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!		// 이 성질이 recursive에서 힌트
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n) {
long ans;

    for (ans = 1; n > 1; n--) {
    	ans *= n;
    }

    return ans;
}

long recursive_factorial(int n) {

    if (n > 0) {
    	//TODO: return ...;
    	return n * recursive_factorial(n - 1); // tail (end) recursion
    }
    else
    	return 1;
}
```

//

## 9.9 이진수 변환 예제

재귀 호출을 이용해서 십진수를 이진수로 변환하는 예제

※ 내 코드
loop에서 printf 역으로 출력하는 방법은 모르겠네

```c
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
	1010(이진수)
*/

long print_binary(unsigned long n);
long print_binary_loop(unsigned long n);

int main() {

    unsigned long number = 10;

    print_binary(number);
    printf("\n");
    print_binary_loop(number);

    return 0;
}

long print_binary(unsigned long n) {
if (n > 0) {

    	print_binary(n / 2);
    }

    if(n != 0)
    	printf("%d", n % 2);

    return 0;
}

long print_binary_loop(unsigned long n) {

    while (n > 0) {

    	printf("%d", n % 2);

    	n = n / 2;
    }

    return 0;
}
```

※ 교수님 코드

```c
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
	1010(이진수)
*/

long print_binary(unsigned long n);
long print_binary_loop(unsigned long n);

int main() {

    unsigned long num = 10;

    print_binary(num);
    print_binary_loop(num);

    printf("\n");

    return 0;
}

//Note: printing order is reversed!
long print_binary_loop(unsigned long num) {

    while (1) {

    	int quotient = num / 2;
    	int remainder = num % 2;

    	printf("%d", remainder); // remainder is 0 or 1

    	num = quotient;

    	if (num == 0) break;
    }

    printf("\n");
}

long print_binary(unsigned long num) {
/\*if (n > 0) {

    	print_binary(n / 2);
    }

    if(n != 0)
    	printf("%d", n % 2);*/

    int remainder = num % 2;

    if (num >= 2)
    	print_binary(num / 2);

    printf("%d", remainder);

    return;
}
```

//

## 9.10 피보나치(Fibonacci) 예제와 재귀 호출의 장단점

피보나치 수열 출력하는 프로그램

※ 내 코드

```c
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
```

※ 교수님 코드

```c
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
```

//
숫자 늘어날 때 마다 미리 이전에 계산한 것을 사용하지 못하고 다시 계산해서 구현하게 된다.
(호출이 얼마나 중복되는지 볼 수 있다)

```c
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
```

//

## 9.11 헤더 파일(Header Files) 만들기 (비주얼 스튜디오)

<my_print_functions.h>

```c
#pragma once // header guard

#include <stdio.h>

void print_hello() {

    printf("Hello\n");
    // many more lines

}

void print_hi() {

    printf("Hi\n");
    // many more lines

}

void print_str(char\* str) {

    printf("%s\n", str);

}

// assume that we have many more longer functions
```

<main.c>

```c
#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h> // 이미 "my_print_functions.h"에서 선언해줘서 없어도 됨
#include "my_print_functions.h"

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}
```

//
헤더파일에는 선언만 남긴다
(헤더 파일과 이름이 같은 c파일 만들어서 정의를 그곳으로 옮긴다)

<my_print_functions.h>

```c
#pragma once // header guard

#include <stdio.h>

void print_hello();
void print_hi();
void print_str(char\* str);

// assume that we have many more longer functions
```

<my_print_functions.c>

```c
#include "my_print_functions.h"

void print_hello() {

    printf("Hello\n");
    // many more lines
}

void print_hi() {

    printf("Hi\n");
    // many more lines
}

void print_str(char\* str) {

    printf("%s\n", str);
}
```

<main.c>

```c
#define _CRT_SECURE_NO_WARNINGS

#include "my_print_functions.h"

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}
```

//
엄격하게 할려면 헤더파일에 stdio.h를 c파일로 옮긴다.
그러면 main.c에서 막히는데 다시 선언해줘야한다.

<my_print_functions.h>

```c
#pragma once // header guard

void print_hello();
void print_hi();
void print_str(char\* str);

// assume that we have many more longer functions
```

```c
<my_print_functions.c>
#include "my_print_functions.h"

#include <stdio.h>

void print_hello() {

    printf("Hello\n");
    // many more lines

}

void print_hi() {

    printf("Hi\n");
    // many more lines

}

void print_str(char\* str) {

    printf("%s\n", str);

}
```

<main.c>

```c
#define _CRT_SECURE_NO_WARNINGS

#include "my_print_functions.h"
#include <stdio.h>

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}
```

근데 현실에서는 크게 중요한 것은 아니다.
//

## 9.12 포인터(Pointer)의 작동 원리

직접적으로 메모리를 사용하는 것이 아니라 간접적으로 가리켜서 사용한다.

//

## 9.13 포인터(Pointer)의 기본적인 사용 방법

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    return 0;
}
```

//
정수형 변수에 주소값 대입하면 warning이 뜬다

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    b = a_ptr;

    /*b = *a_ptr;

    printf("%d\n", b);*/

    return 0;
}
```

//
주소 대입

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    b = a_ptr;	// 주소를 integer에 넣는 경우는 거의 없다. warning뜸

    /*b = *a_ptr;

    printf("%d\n", b);*/

    return 0;
}
```

//
포인터 대입

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.

    printf("%d\n", b);

    return 0;
}
```

//
값을 주소에서 가져와서 그 값을 저장할 때 순수하게 값만 저장한다.

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.(순수하게 값만 저장)

    printf("%d\n", b);

    *a_ptr = 789;

    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

    return 0;
}
```

//

```c
#include <stdio.h>

int main() {

    int a, b;

    a = 123;

    int* a_ptr;	 // * : asterisk

    a_ptr = &a;  // & : address-of operator

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;  // * : re-direction or de-referencing

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    //b = a_ptr;

    b = *a_ptr;		// 값을 주소에서 가져와서 그 값을 저장한다.(순수하게 값만 저장)

    printf("%d\n", b);

    *a_ptr = 789;

    printf("%d\n", b);
    printf("%d %d %p %p\n", a, *a_ptr, a_ptr, &b);

    b = 12;

    printf("%d\n", b);
    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    a = 1004;
    printf("%d %d %p %d\n", a, *a_ptr, a_ptr, b);

    return 0;
}
```

//

## 9.14 포인터와 코딩 스타일

```c
#include <stdio.h>

int main() {

    // int *a_ptr vs int* a_ptr
    // int *my_ptr, sec_ptr;
    int *a, b; // *a만 포인터고 b는 정수다
    //int* a, b; // typedef

    /*
    	if Google style

    int *a; // OK (but 밑에와 혼용하지 말고 한가지 스타일만)
    int* b; // OK
    int * b; // X

    */

    return 0;
}
```

//

## 9.15 NULL 포인터와 런타임 에러

런타임 에러 나는 경우

```c
#include <stdio.h>

int main() {

    /*
    int a = 1234;
    printf("%p\n", &a); // 주소값
    printf("%d\n", a);
    */

    int *ptr = 1234; // 그냥 int *ptr; 이면 컴파일도 안 해줌.

    printf("%p\n", ptr);
    printf("%d\n", *ptr);	// 정말 위의 1234 주소로 가서 가져오려고 시도 했음, 막상 가서 보니까 프로그램이 사용하도록 할당받은 공간이 아님, 그래서 강제 종료시킴

    return 0;
}
```

//
런타임 에러 나는 경우2
b의 값에 따라서 포인터에 주소를 넣거나 안 넣는 경우 생각 가능

```c
#include <stdio.h>

int main() {

    int* safer_ptr; // = NULL;

    int a = 123;

    // safer_ptr = &a;

    // 런타임 에러 나는 경우
    int b;
    scanf("%d", &b);

    if (b % 2 == 0)
    	safer_ptr = &a;

    return 0;
}
```

//
포인터에 NULL값을 넣어 초기화 하는 것이 일반적이다.
(그 포인터를 사용해도 되는지 확인, 런타임 에러 방지할 수 있다)

```c
#include <stdio.h>

int main() {

    int* safer_ptr = NULL;

    int a = 123;

    // safer_ptr = &a;

    int b;
    scanf("%d", &b);

    if (b % 2 == 0)
    	safer_ptr = &a;

    if (safer_ptr != NULL)
    	printf("%p\n", safer_ptr);

    if (safer_ptr != NULL)
    	printf("%d\n", *safer_ptr);

    return 0;
}
```

//

## 9.16 디버거로 메모리 들여다보기(비주얼 스튜디오)

```c
#include <stdio.h>

int main() {

    int a = 3, b = 5, c = 7, d = 9;
    int* a_ptr = &a, * b_ptr = &b, * c_ptr = &c, * d_ptr = &d;

    printf("%p %p %p %p", &a, &b, &c, &d);

    return 0;
}
```

//

## 9.17 포인터 변수의 크기

```c
#include <stdio.h>

int main() {

    char a;		// 1byte
    float b;	// 4byte
    double c;	// 8byte

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));	 // pointer
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));			 // 주소를 직접 출력(주소 연산자)
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 자료형을 직접 출력
}
```

자료형 크기에 상관없이 주소의 크기는 동일하다.
(x86에서는 4byte, x64에서는 8byte)

//
데이터의 크기에 따라서 차지하는 양을 확인하기

```c
#include <stdio.h>

int main() {

    char a = 1;		// 1byte
    float b = 3;	// 4byte
    double c = 5;	// 8byte

    char* ptr_a = &a;
    float* ptr_b = &b;
    double* ptr_c = &c;

    a = 2;
    b = 4;
    c = 6;

    printf("%zd %zd %zd\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%zd %zd %zd\n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));	 // pointer
    printf("%zd %zd %zd\n", sizeof(&a), sizeof(&b), sizeof(&c));			 // 주소를 직접 출력(주소 연산자)
    printf("%zd %zd %zd\n", sizeof(char*), sizeof(float*), sizeof(double*)); // 자료형을 직접 출력
}
```

//

## 9.18 포인터형 매개변수

두개의 값을 'swap'하는 코드 만들어 보자

```c
#include <stdio.h>

int main() {

    int a = 123;
    int b = 456;

    // swap
    int temp = a;
    a = b;
    b = temp;
    printf("%d %d\n", a, b);

    return 0;
}
```

//
위의 swap을 함수로 만들어서 써보자

```c
#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 123;
    int b = 456;

    // swap
    swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}
```

해보면 swap이 전혀 안 된다.

```c
#include <stdio.h>

void swap(int a, int b) {

    printf("%p %p\n", &a, &b);

    int temp = a;
    a = b;
    b = temp;
}

int main() {

    int a = 123;
    int b = 456;

    printf("%p %p\n", &a, &b);

    // swap
    swap(a, b);
    printf("%d %d\n", a, b);

    return 0;
}
```

확인해 보면 주소가 전혀 다르다.
(애초에 이름만 같고 다른 변수이므로)

//
swap 함수에 a의 주소와 b의 주소를 넣어서 해결해보자

```c
#include <stdio.h>

void swap(int* u, int* v) {

    printf("%p %p\n", u, v);

    int temp = *u;
    *u = *v;
    *v = temp;
}

int main() {

    int a = 123;
    int b = 456;

    printf("%p %p\n", &a, &b);

    // swap
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}
```

이런 것을
call by pointer
라고 부르기도 한다.

//
