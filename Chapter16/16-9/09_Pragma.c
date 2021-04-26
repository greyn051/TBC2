#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

//	https://docs.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword?view=msvc-160

/*
#pragma tokens (ex: once)
*/

//#pragma pack(1)
//_Pragma("pack(1)") // destring : remove first and last ", \" -> "
//#define	PACK1	_Pragma("pack(1)")
//PACK1

//#pragma warning(disable : 4477 )
//#pragma warning( drror : 4477 )

struct	s
{
	int		i;
	char	ch;
	double	d;
};

int		main(void)
{
	struct s	A;
	printf("Size of A is: %d", sizeof(A));

	return (0);
}
