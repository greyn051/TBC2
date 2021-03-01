#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// malloc(), free()

int main() {

	float x;
	char str[] = "Dancing with a Star";

	int arr[100];

	/*
		(malloc: memory allocation 메모리 할당)
		malloc() returns a void type pointer.(순수한 주소)
		void* : generic pointer

		free() deallocates the memory
	*/

	double* ptr = NULL;

	// 쓰는 쪽(ptr)에서 double로 casting
	ptr = (double*)malloc(30 * sizeof(double));	// double 30개 저장용, 메모리 공간의 첫번째 주소를 return해준다.(pointer)
	//size_t;	// malloc()함수 parameter 확인용	// 몇 byte 메모리 요청할지 size만 적어주면 된다.

	if (ptr == NULL)	// malloc()함수는 줄 메모리 공간이 없을 때 NULL을 return함
	{

		puts("Memory allocation failed");

		/*
			exit(EXIT_FAILURE) is similar to return 1 IN main().
			exit(EXIT_SUCCESS) is similar to return 0 IN main().

			exit()함수는 어떠한 상황에서도 강제로 프로그램 종료 가능
		*/

		exit(EXIT_FAILURE);
		/*
			대부분의 경우 메모리 할당이 안 된다는 의미는 
			아주 심각해서 프로그램을 진행할 수 없는 경우이므로
			exit을 이용해서 강제로 종료(exit 의외로 많이 사용, debugging 할 때 많이 쓴다)
			(메모리 할당 안 되는 경우 잘 없다. 만약 있다면 메모리를 너무 크게 요청한 경우다.)
			(프로그램 여러개 있어서 연속된 공간을 줄 수 없을 때도 메모리 할당 안 된다.)
			
			꼭 나가야 할 필욘 없다.

			다만, 웹서버 등 어떠한 경우에도 계속 돌아가야한다면 
			오류처리라는 문법을 이용해서 다른 대안 찾음(다른 언어에서 공부)
		*/
	}
	/*
		동적할당 받은 메모리와 포인터를 동일시하지 말자
		automatic은 scope 밖으로 가면 잃어버리므로
		(주소를 적은 쪽지라고 생각)
		(주소는 있지만 쪽지를 잃어버려서 찾을 수 없는 경우)

		초보때 포인터를 잃어버렸는데도 
		동적할당을 반복하다가 heap이 꽉차면 문제가 생기는 경우가 있다.
	*/

	printf("Before free %p\n", ptr);

	free(ptr);	// no action occurs when ptr is NULL

	printf("After free %p\n", ptr);
	/*
		free이후에도 ptr의 값(주소)은 이전과 같은데 
		비유는 하면 친구집 주소를 쪽지로 적어서 가지고 있을때
		친구가 이사를 해도 쪽지에 적힌 주소는 동일한 것으로 보면 된다.

		그러므로 free 이후에 동적할당 메모리에 대한 포인터 변수는 
		NULL값으로 바꾸는 것이 안전하고 편하다.(optional)
	*/
	ptr = NULL;	// optional

	/* Dynamic Allocated Array */
	// 동적할당 메모리는 배열처럼 사용 가능

	int n = 5;
	// n의 값은 runtime에 결정되어도 된다.
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)	// if(!ptr)
	{
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");
		// 메모리를 할당 만 받고 초기화를 하지 않았기 때문에 쓰레기 값이 들어있다.

		for (int i = 0; i < n; ++i)
			* (ptr + i) = (double)i;	// 포인터 연산을 이용해 배열처럼 사용

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");
	}
	// 동적할당 메모리는 (malloc()함수로 받아왔을 때는) 초기화를 하지 않는다는 것을 기억

	free(ptr);
	ptr = NULL;

	/*
		Comparision to VLA (가변길이배열과 비교)

		VLA
		- not supported by VS compilers.(gcc에서는 지원)(대부분의 프로그램은 VLA보단 동적할당 지원)
		- automatic duration, cannot be resized	(동적할당은 다른 size의 메모리 다시 받아올 수 있음)
		- limited by stack size (when compiler places VLA in stack segment)
	*/

	return 0;
}