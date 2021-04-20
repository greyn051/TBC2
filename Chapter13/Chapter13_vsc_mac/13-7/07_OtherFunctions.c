#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

int		main(void)
{
	FILE	*fp;
	int		ch;

	/* ungetc() */	// 한 글자 읽어서 버퍼에 그 글자 넣음
	fp = fopen("input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	ungetc(ch, fp);		// try another characters // 버퍼에 방금 넣은거 다시 넣음
	//ungetc((int)'A', fp);

	ch = fgetc(fp);
	fputc(ch, stdout);

	ch = fgetc(fp);
	fputc(ch, stdout);
	
	fclose(fp);

	/* setvbuf() */	// buffer의 설정을 바꿀 수 있음
	fp = fopen("input.txt", "r");

	char	buffer[32] = {'\0',};

	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF

	ch = fgetc(fp);	// Read just only a single character!

	// dump buffer(한 글자만 넣고 버퍼에 있는 내용 전부 출력 해봄)
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	/* fflush() */	// buffer에 쌓인 데이터 모두 없애라

	// Writing a large amount of data
	// fflush(fp);

	return (0);
}