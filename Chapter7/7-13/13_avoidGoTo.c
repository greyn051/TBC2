/*
## 7.13 goto를 피하는 방법
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>

int main() {

    /* if else */
    int size = 15, cost;

    if (size < 10)
    	goto a;		// label
    goto b;

a: cost = 50 _ size;
b: cost = 100 _ size;

    if (size < 10)
    	cost = 50 * size;
    cost = 100 * size;
    /* 바로 위 cost 대신 else도 가능
    else
    	cost = 100 * size;
    */

    /* loop */
    char c;

read: c = getchar();
    putchar(c);
    if (c == '.') goto quit;
    goto read;
quit:

    while (1) {
    	c = getchar();
    	putchar(c);
    	if (c == '.') break;
    }
    // 실무에서는 block을 써서 이 부분이 loop인 것을 명확하게 표현
    // 나가야할 조건에는 break; 사용

    return 0;
}

/*
예전에는 goto문을 매우 많이 사용했다.

cpu가 일을 할 때 goto문 처럼 한다.

그러나 사람이 프로그래밍할 때는 꼭 cpu에 맞춰서 할 필요는 없다. 현대 프로그래밍 기법에서는 사람이 작업하고 이해하고 수정하고 유지보수 하기 좋은 방법으로 한다.

가급적이면 goto를 사용하지 않도록 한다.
*/
