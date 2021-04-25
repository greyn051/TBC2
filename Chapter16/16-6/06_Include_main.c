#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>	// <>는 컴파일러가 어디있는지 미리 알고있는 파일(대부분 표준 라이브러리)
#include	"my_functions.h"
#include	"my_structures.h"
#include	"my_headers/my_macros.h"	// path
// 절대 경로로도 가능한데 이렇게 코딩하는 사람은 잘 없다
//#include	"/Users/refigo/github-repository/TBC/Chapter16/16-6/my_headers/my_macros.h"

extern int	status;

int		main(void)
{
#include	"hello_world.h"	// 이런 식으로는 절대 코딩하면 안 된다. 걍 보여줄려고 한거다.

	printf("PI = %f\n", PI);

	printf("%p %d\n", &status, status);

	print_status();

	printf("%d\n", multiply(51, 2));

	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);

	print_address();

	patient_info	james = { "James Bone", 45 }, michael = { "Michael Jobs", 50 };	

	return (0);
}

