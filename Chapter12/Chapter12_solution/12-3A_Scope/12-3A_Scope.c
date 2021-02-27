#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, function prototype, file.
*/

void f1(int hello, double world);	// to the end of the prototype declaration
//void vla-param(int n, int m, double ar[n][m]); // gcc only

double func_block(double d) {

	double p = 0.0;

	int i;
	for (i = 0; i < 10; i++)	//for (int i = 0; i < 10; i++) // C99
	{
		
	
		double q = d * i;
		p *= q;

		if (i == 5)
			goto hello;	// goto문 거의 사용x
	}
hello:
	printf("Hello, World");

	return 0;
}

int main() {

	func_block(1.0);

	return 0;
}

void f1(int hello, double world) {
	// prototype과 변수명을 맞춰주는 것이 유지관리하기 좋다

}

/*
void vla_param(int n, int m, double ar[n][m]) {
}
*/
