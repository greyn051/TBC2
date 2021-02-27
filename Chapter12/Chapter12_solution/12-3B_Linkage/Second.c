#include <stdio.h>

extern int el;
//extern int il;
/*
	extern 이라는 키워드를 사용하면
	어딘가 다른데 선언이 되어있는 변수를 끌어올 수 있다.
*/

void testLinkage() {

	printf("DoSomething called\n");
	printf("%d\n", el);
	//printf("%d\n", il);
	//printf("%d", dodgers);

	el++;
}


