/*
## 6.10 다양한 대입 연산자들 (그리고 어셈블리 코드 확인법)
*/

#include <stdio.h>

int main() {
    /*
    +=, -=, *=, /=, %=
    */

    int i = 1024;

    i = i + 10;
    i += 10;

    i %= 4;

    i = i * (1 + 2);
    i *= 1 + 2;
    i *= (1 + 2);	// Check precedence

    for (int i = 0; i < 10; i += 2)		// i = i + 2 보단 i += 2를 주로 쓴다. +1인 경우에는 i++.
    	;

    return 0;
}
