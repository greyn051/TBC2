#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<ctype.h>	//toupper(), tolower()

void	ToUpper(char *str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void	ToLower(char *str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

//  위의 공통되는 부분을 묶어서 하나의 함수로 만들자
void	UpdateString(char *str, int (*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

int		main(void)
{
	char	str[] = "Hellow, World!";

	void	(*pf)(char *);

	pf = ToUpper;	// Name of a function is a pointer
	//pf = &ToUpper;		// Acceptable
	//pf = ToUpper(str);	// Not acceptible in C

	printf("String literal %lld\n", (long long)("Hellow, World!"));
	printf("Function pointer %lld\n", (long long)ToUpper);
	printF("Variable %lld\n", (long long)str);

	(*pf)(str);
	//pf(str);	// K&R X, ANSI OK

	printf("ToUpper %s\n", str);

	pf = ToLower;

	pf(str);

	printf("ToLower %s\n", str);

	/*
		passing function pointers to functions
	*/

	UpdateString(str, toupper);

	printf("ToUpper %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower %s\n", str);

	// Note: __cdec1 is function calling convention(함수 호출 규약)

	return (0);
}



