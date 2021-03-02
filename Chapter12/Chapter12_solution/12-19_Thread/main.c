#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
/*
	C언어 표준에는 멀티스레딩이 들어와 있지 않다.
	대부분의 경우 운영체제에서 제공하는 API 사용
	운영체제에 따라서 사용하는 프로그래밍 기술이 다르다.
*/

//_Atomic int acnt = 0;	// NA

DWORD WINAPI ThreadFunc(void* data) {

	int n = 1;
	Sleep(1000);

	//acnt += n;	// NA
	printf("Printing from Thread \n");
	return 0;
}

int main() {

	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	if (thread)
		WaitForSingleObject(thread, INFINITE);
}

// 이거보다 gcc에서 일반적으로 사용되는 코드가 있다.
// online gcc compiler 구글링
// www.onlinegdb.com/online_c_compiler
/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	// sleep().
#include <pthread.h>
#include <stdatomic.h>

_Atomic int acnt = 0;	// atomic type qualifer	(C11)

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp) {

	int n = 1;	// thread storage duration
	for (int j = 0; j < 10; ++j) {

		sleep(1);
		acnt += n;
		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
	}

	return NULL;
}

int main() {
	
	pthread_t thread_id1, thread_id2;

	printf("Before Thread\n");

	pthread_create(&thread_id1, NULL, myThreadFun, NULL);
	pthread_create(&thread_id2, NULL, myThreadFun, NULL);

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);

	printf("After Thread\n");
	printf("Atomic %d\n", acnt);

	return 0;
}
*/

/*
To compile
	& gcc <file-name.c> -o <output-file-name> -lpthread
To run
	& ./<output-file-name>
*/