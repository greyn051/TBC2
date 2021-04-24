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
	unsigned char	i = to_decimal("01000110");
	unsigned char	mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);

	/*
		Decimal to binary

		       Number     Mask         Mask
		2^7 : (01000110 & 10000000) != 10000000		print 0
		2^6 : (01000110 & 01000000) != 01000000		print 1
		2^5 : (01000110 & 00100000) != 00100000		print 0
		2^4 : (01000110 & 00010000) != 00010000		print 0
		2^3 : (01000110 & 00001000) != 00001000		print 0
		2^2 : (01000110 & 00000100) != 00000100		print 1
		2^1 : (01000110 & 00000010) != 00000010		print 1
		2^0 : (01000110 & 00000001) != 00000001		print 0		
	*/

	return (0);
}