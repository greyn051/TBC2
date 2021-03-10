#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/

int g_i = 123;	// global variable
int g_j;		// global variable
// file 영역은 모든 함수 바깥에 선언되면 됨(file scope를 갖는다)

void func1() {
	g_i++;	// uses g_i
}

void func2() {
	g_i += 2;	// uses g_i

	//local = 456;	// Error
}

int main() {

	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);// uses g_i
	printf("%d\n", g_j);// Not initialized?
	// 초기화하지 않은 전역 변수는 BSS segment에 저장되는데 여기에 저장된 값들은 프로그램이 시작될 때 0으로 초기화 된다.
	printf("%d\n", local);

	return 0;
}


