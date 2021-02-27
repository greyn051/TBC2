#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Linkage

	Variables with block scope, function scope, or function prototype
	- No linkage

	File scope variables
	- External or internal linkage
*/

// translation unit

int el;			// file scope with external linkage (global variable)
// file scope에 있는 변수는 마치 프로그램 전체에서 사용할 수 있는 것 처럼 사용할 수 있어서 전역변수라고 부른다.
static int il;	// file scope with internal linkage
// static, 이 변수의 범위가 현재 scope로 제한하는 의미

void testLinkage();	// 다른 파일에 있는 함수를 사용하기 위해 prototype 선언(linking)

int main() {

	el = 1024;

	testLinkage();

	printf("%d\n", el);

	return 0;
}
