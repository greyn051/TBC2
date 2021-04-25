#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

// empty macro
#define	REPORT

int	sum(int i, int j)
{
	int	s = 0;
	for (int k = i; k <= j; ++k)
	{
		s += k;

// 보통 _DEBUG를 이용해서 디버그 모드일 때 보여지게 한다.
#ifdef	REPORT	//TODO: change in project properties
		printf('%d %d\n", s, k');
#endif
	}

	return s;
}

int		main(void)
{
	prinf("\n%d \n", sum(1, 10));

	return (0);
}
