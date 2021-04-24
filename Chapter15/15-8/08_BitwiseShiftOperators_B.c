#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

#define		BYTE_MASK	0xff

int		main(void)
{
	unsigned int	rgba_color = 0x66CDAAFF;
	// 4 bytes, medium aqua marine	(102, 205, 170, 255)

	unsigned char	red, green, blue, alpha;

	// Use right shift >> operator
	alpha	= 0;	// TODO: 
	blue	= 0;	// TODO: 
	green	= 0;	// TODO:
	red		= 0;	// TODO:

	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n", 
		red, green, blue, alpha);
	
	return (0);
}