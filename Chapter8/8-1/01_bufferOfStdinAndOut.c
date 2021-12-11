/*
## 8.1 입출력 버퍼
*/

/*
gethchar(), putchar()는 분명 한 글자씩 입력을 받고 있는데
마치 작동하는 것은 덩어리처럼 한 번에 보낸다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h> // Windows, _getch(), _getche()

int main() {

	char c;

	while ((c = getchar()) != '.')
		putchar(c);

	return 0;
}


/*********************************************************
*********************************************************/


// 버퍼 작동하지 않는 경우

#include <stdio.h>
#include <conio.h> // Windows, _getch(), _getche() // 버퍼 사용x

int main() {

	char c;

	while ((c = _getche()) != '.') // e는 echo의 약자, _getch를 쓰면 입력한거 출력x
		putchar(c);

	return 0;
}
