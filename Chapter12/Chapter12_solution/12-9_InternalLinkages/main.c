#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Static variable with internal linkage
	- File scope, external linkage, static storage duration
	- Internal storage class
*/

static int g_int = 123;	// defining declaration
/*
	전역변수 사용하는 경우에 복잡해져 유지보수가 힘든경우가 있다.

	그래서 전역변수를 file scope 내에서만 사용할 수 있도록 제한하고 싶은 경우가 있다.
	그 때 static 사용(이 scope 안으로 강제로 고정)

*/

void fun();
void fun_second();
void fun_third();

int main() {

	fun();
	fun_second();
	fun_third();

	return 0;
}

void fun() {

	extern int g_int;	// optional

	g_int += 1;
	printf("g_int in fun() %d %p", g_int, &g_int);
}
