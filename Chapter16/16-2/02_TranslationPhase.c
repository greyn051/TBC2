#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

int		main(void)
{
	/*
		Program written in C

		Translating
		Preprocessing
		Compiling
		Linking

		Executable
	*/

	/*
		International characters	// 다국어 지원
	*/

	puts("안녕하세요? 한글을 사랑합니다.\n");

	/*
		Trigraph Sequences
		- Some keyboards don't provide all the symbols used in C.
		- Three-character sequences

		Trigraph		Replacement
		??=				#
		??/				\
		??'				^
		??(				[
		??)				]
		??!				|
		??<				{
		??>				}
		??-				~

		/Zc:trigraphs
	*/

	int	arr[3] = { 1, 2, 3 };
	printf("arr??(0??) == %d\n", arr??(0??));
	//printf("arr[0] == %d\n", arr[0]);

	/*
		Digraphs
		- Two-character sequences

		Diagraph		Equivalent
		<:				[
		:>				]
		<%				{
		%>				}
		%:				#
	*/

	printf("arr<:1:> == %d\n", arr<:1:>);
	//printf("arr[1] == %d", arr[1]);

	/* Two physical lines vs One logical line */
	//printf("This is a very very very very very very very very long long long long long long line.\n");
	printf("This is a very very very very very \
very very very long long long long long long line.\n");

	/*
		Tokens
		- Groups separated from each other by spaces, tabs, or line breaks
		Whitespace characters -> a single space
	*/

	int/*a variable to count a number*/n = 1;	// 이런 경우에 아래와 같이 한 칸 공백으로 해석
	// int n = 1;	// 이렇게 작동한다.

	
	// 이런식으로 주석 다는 것은 매우 안 좋다고 생각
	// int	n = 1;	/*a variable to count a number*/
	// 차라리 이렇게 달아라

	return (0);
}

