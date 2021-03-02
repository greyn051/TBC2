#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n = 10;

	int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * n);
	ptr = (int*)calloc(n, sizeof(int));	// contiguous allocation
	// 연속된 n개의 int 메모리 받아라(parameter가 count, size 2개)
	if (!ptr)
		exit(1);

	// calloc()은 전부 초기화를 해준다.
	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);
	printf("\n");

	/*
		realloc() KNK p. 422
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block
		- If first argument is NULL, it behaves like malloc()
		- if second argument is 0, it frees the memory block.

		이전에 동적할당으로 메모리를 받았는데
		내가 필요로 하는 메모리의 사이즈가 달라져서 
		다시 할당을 받고 싶을 때 사용하는 함수
		re-allocation(재할당)
	*/

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;	// n이 10에서 20으로 바뀜

	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n * sizeof(int));	// 늘어난 공간으로 재할당 요청
	// 앞에 ptr은 이미 동적할당으로 가지고 있는 메모리 블럭에 대한 포인터

	//ptr = (int*)realloc(ptr, n * sizeof(int));
	// 실무에선 이렇게 원래 메모리가 늘어나는 것 처럼 써도 된다.

	printf("%p %p\n", ptr, ptr2);

	printf("%d\n", ptr[0]);

	if (!ptr2)
		exit(1);
	else
		ptr = NULL;	// 원래 포인터 사용하지 않도록 막아줌(ptr2 사용시에)

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr2[i]);		// copies data
	printf("\n");
	// 새로 추가가 된 값은 초기화 되지 않는다.(쓰레기 값 출력)

	free(ptr2);

	return 0;
}

