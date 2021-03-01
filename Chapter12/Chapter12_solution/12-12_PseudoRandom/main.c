#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// srand()	// random number를 생성할 때 필요한 함수들이 포함됨
#include <time.h>	// time()

int main() {

	/*
		rand()
		- 0 to RAND_MAX (typically INT_MAX)
		- defined in stdlib.h.

		C언어에서 난수 생성시 사용(사람이 봤을 때 무작위로 보임)
		컴퓨터는 진정한 난수를 만드는 능력이 없다.
	*/

	/*
	//srand(3);	// random seed	// seed값이 바뀌면 나오는 rand() 값이 바뀜
	srand((unsigned int)time(0));	// time을 이용해서 seed값을 예측하기 힘들게 만든다
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
		//printf("%d\n", rand() % 6 + 1);
	}
	*/

	unsigned int next = (unsigned int)time(0);	// seed값

	for (int i = 0; i < 10; ++i) {
		next = next * 1103515245 + 1234;
		// 난수를 만드는 어떤 규칙이 있다. 흔히 '유사 난수'(pseudo random number)로 부르기도 함
		next = (unsigned int)(next / 65536) % 32768;
		printf("%d\n", (int)next);
	}

	return 0;
}


