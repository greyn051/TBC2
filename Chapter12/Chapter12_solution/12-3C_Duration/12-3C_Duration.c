#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage duration:
	- static storage duration // 시작할 때 부터 끝날 때 까지 메모리 자리 고정적으로	// 여기서 말하는 static은 '정적'이라는 의미 그 자체
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration
	- allocated storage duration
	- thread storage duration

	duration은 메모리의 지속기간을 의미
*/

void count() {

	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count() {

	static int ct = 0;
	/*
		앞에 static이 붙으면 프로그램이 시작될 때 메모리에 들어오고
		끝날때 까지 메모리에 유지된다.(함수가 끝나도 없어지지 않음)
		(다시 선언x)
	*/
	printf("static count = %d\n", ct);
	ct++;
}

int main() {

	count();
	count();
	static_count();
	static_count();

	return 0;
}
