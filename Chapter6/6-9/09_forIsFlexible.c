/*
## 6.9 for는 유연해요
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    /*
    for(initialize; test; update)
    statement
    */

    for (int i = 10; i > 0; i--)
    	printf("%d ", i);

    for (int i = 0; i < 100; i = 1 + 8)
    	printf("%d ", i);

    for (char c = 'A'; c <= 'Z'; c++)
    	printf("%c ", c);

    for (int i = 0; i * i < 10; i++)
    	printf("%d ", i);

    for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)  // 같은 자료형의 변수 여러개 초기화 가능
    	printf("%d ", x);

    for (double d = 100.0; d < 300; d = d * 1.1)
    	printf("%f\n", d);

    int i, n;
    n = 2;
    for (i = 2; n < 10; /* left blank */) {
    	n = n * i;
    	printf("%d\n", n);
    }

    for ( ; ; ) // while(1)과 동일
    	printf("I love you! ");

    int i = 0;
    for (printf("Let's go!\n"); i != 7; scanf("%d", &i))	// 이 정도 과도하긴 한데 가능하다. 그런데 사용하지 않는게 좋다.
    	; // null statement

    return 0;
}
