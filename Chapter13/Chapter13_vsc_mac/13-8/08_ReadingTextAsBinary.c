#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<windows.h>		// SetConsoleOutputCP()

int		main(void)
{
	FILE	*fp = fopen("test.txt", "rb");

	unsigned char	ch;

	SetConsoleOutputCP(CP_UTF8);	// UTF-8 mode

	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
	{
		printf("%c", ch);
		//printf("%hhu %c", ch, ch);	// ascii 코드도 출력
	}

	fclose(fp);

	return (0);
}