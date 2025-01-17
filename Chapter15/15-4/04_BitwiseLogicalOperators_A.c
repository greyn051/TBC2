#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<math.h>	// pow()
#include	<string.h>	// strlen()
#include	<stdlib.h>	// exit()
#include	<stdbool.h>

unsigned char	to_decimal(const char bi[]);
void	print_binary(const unsigned char num);

int		main(void)
{
	/*
		Regular Logical Operators : &&, ||, and !

		bool	have_apple = true;
		bool	like_apple = true;
		if (have_apple && like_apple)
			eat_apple();

		Bitwise Logical Operators :
		- Bitwise NOT ~
		- Bitwise AND &
		- Bitwise OR |
		- Bitwise EXCLUSIVE OR ^
	*/

	unsigned char	a = 6;
	unsigned char	b = 5;

	printf("%hhu\n", a);
	print_binary(a);

	printf("%hhu\n", b);
	print_binary(b);

	printf("hhu\n", a & b);
	print_binary(a & b);

	printf("%hhu\n", a | b);
	print_binary(a | b);

	printf("%hhu\n", a ^ b);
	print_binary(a ^ b);

	printf("%hhu\n", ~a);
	print_binary(~a);

	return (0);
}

unsigned char	to_decimal(const char bi[])
{
	const size_t	bits = strlen(bi);
	unsigned char	sum = 0;
	for (size_t i = 0; i < bits; ++i)
	{
		if (bi[i] == '1')
			sum += (int)pow(2, bits - 1 - i);
		else if (bi[i] != '0')
		{
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}
	}

	return (sum);
	//printf("Binary %s == Decimal %d\n", bi, sum);
}
