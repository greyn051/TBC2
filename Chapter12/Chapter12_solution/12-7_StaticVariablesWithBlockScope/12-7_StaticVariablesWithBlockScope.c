#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count() {

	int ct = 0;	// stack에 저장됨
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

void static_count() {

	static int ct = 0;	// initialized only once!
	// stack에 저장x, 데이터나 BSS같은 곳에 저장(프로그램 시작부터 끝까지 유지되는 곳(static))
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	//TODO: return &ct;
}

/*
* TODO: return &ct;
* 포인터를 반환하는 경우도 꽤 있다.
* ex) 하드웨어 관련 api 사용, 게임 엔진 등

int* count() {

	int ct = 0;
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;	
	// 이런 방식 매우 안 좋음, 지역변수의 포인터를 반환하는데 지역변수는 함수를 나가면 사라지기 때문
}

int* static_count() {

	static int ct = 0;	// initialized only once!
	printf("static count = %d %lld\n", ct, (long long)&ct);
	ct++;

	return &ct;
	// 메모리에 고정된 주소를 가지고 있기 때문에 써도 된다.(좋다는 뜻은 아님, 이럴바엔 차라리 전역변수 사용하자)
}

*/

//int func(static int i) {	// Warning (Error in GCC)
//
//}
/*
	함수의 parameter에 static 넣는 경우, 
	vs에서 i가 bad storage갖는다는 warning이 뜨고
	gcc로 컴파일하면 error가 나서 컴파일 불가

	paremeter의 변수는 함수가 실행이 될 때 메모리의 배정을 받는데
	static과는 맞지 않으므로
*/

void counter_caller() {
	
	count();
}

void static_counter_caller() {

	static_count();
}

int main() {

	count();
	count();
	counter_caller();	// stack 안에서 count() 호출

	static_count();
	static_count();
	static_counter_caller();

	return 0;
}


