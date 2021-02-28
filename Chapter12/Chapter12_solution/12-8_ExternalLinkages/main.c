#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Static variable with external linkage
	- File scope, external linkage, static storage duration
	- External storage class
	- External variables
*/

int g_int = 0;		// 컴파일러가 전역변수 알아서 초기화 해주지만 가급적이면 직접 초기화 하자
//int g_int = 7;
double g_arr[1000] = { 0.0, };
// 전역변수인 경우 global의 약자 g_를 앞에 잘 붙인다.

/*
	Initializing External Variables
*/

int x = 5;					// ok, constant expression
int y = 1 + 2;				// ok, constant expression
size_t z = sizeof(int);		// ok, sizeof is a constant expression
//int x2 = 2 * x;			// not ok, x is a variable(변수가 들어가는 expression으로 초기화는 불가)

void fun() {

	printf("g_int in fun() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능
	g_int += 10;
}

void fun_sec();	// second.c에 있는 함수 선언만 해주면 외부 연결

int main() {
	/*
		defining declaration vs referencing declaration
	*/

	extern int g_int;			// Optional		// scope 바깥에 이 변수있으니까 연결(file scope에 있다는 걸 명확히)
	//extern int g_int = 1024;	// Error in block scope

	//int g_int = 123;			// hides global g_int

	extern double g_arr[];		// optional, size is not necessary
	// size를 위에서 이미 결정

	printf("g_int in main() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능
	g_int += 1;

	fun();
	fun_sec();

	return 0;
}

