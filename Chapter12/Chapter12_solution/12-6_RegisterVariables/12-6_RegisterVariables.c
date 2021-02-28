#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r) {
	// do something with r
}

int main() {

	register int r;
	// register keyword를 붙이면 컴파일러에게 가급적 이 변수를 register에 위치 해달라는 의미
	r = 123;
	// 임베디드 분야 등에 이걸 사용하는 경우가 있다.

	//printf("%p\n", &r);
	int* ptr = &r;	// register keyword 사용시 address of operator를 사용할 수 없다.
	// 이태껏 포인터나 주소를 사용할 때는 주 기억장치를 위주로 사용했기 때문


	return 0;
}
