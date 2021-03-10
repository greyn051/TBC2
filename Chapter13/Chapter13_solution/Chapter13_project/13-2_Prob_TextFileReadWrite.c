#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// command arguments에 명령줄 인수 파일을 설정한다.

int main(int argc, char* argv[])	// 명령줄 인수
{

	int ch;
	FILE* fr;	// TODO: file pointer to write
	// 파일을 처리할 때 필요한 데이터의 묶음에 대한 포인터
	// 마치 파일 자체에 대한 포인터인 것 처럼 쓰고 느껴진다.

	/*
	typedef struct _iobuf	// struct, 데이터의 묶음
	{
		char*	_ptr;
		int _cnt;
		char*	_base;
		int _flag;
		int _file;
		int _charbuf;
		int _bufsiz;
		char*	_tmpfname;
	} FILE;
	*/
	// 파일을 처리할 때 필요한 여러가지 데이터들의 묶음을 
	// 파일이라는 자료형이 있는 것 처럼 사용할 수 있게 해줌

	// const char* out_filename = "output.txt";	// TODO: Use this

	unsigned long count = 0;	// 몇글자인지 카운트하려고 선언한 변수

	if (argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}	// 명령줄 인수로 부터 파일이름 받음
	// 명령줄 인수가 비어있으면 이렇게 사용하라는 뜻(파일이름 입력해라)
	// 이런식으로 명령줄 인수의 사용법을 알려주는 것이 C프로그래밍에서 일반적인 방식

	/*	파일 이름의 입력이 제대로 들어왔다면 파일을 연다
		fopen함수는 파일 포인터를 return해줌(위 FILE과 같은 의미) */
	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading.
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}	/* NULL 포인터가 반환되는 경우는 쉽지 않은데 
		하드가 꽉찼거나 읽기전용 파일을 강제로 쓰려고 할 때 생긴다. */
	
	/*
		fopen mode strings for text files	// 위에 "r"이므로 문자열이다.
		- r: reading
		- w: creating-and-writing or oven-writing
		- a: appending or creating-and-writing	// 내용 덧붙이거나 내용 없으면 새로 생성
		- r+: both reading and writing
		- w+: reading and writing, over-writing or creating
		- a+: reading and writing, appending or creating
	*/

	// TODO: open file to write with "w" mode string

	/*	file stream으로 부터 데이터를 읽어오는 과정
		문자(데이터)를 한글자씩 받아오고 있다.
		EOF가 아닐 때 까지 읽음 */
	while ((ch = fgetc(fr)) != EOF)	// getc(fr)	// fgetc, getc 기능 거의 동일(fgetc 더 많이 사용)
	{
		//putc(ch, stdout);	// smae as putchar(ch);
		fputc(ch, stdout);	// fputc를 사용하는 것이 좀 더 안정적이라고 함
		// 다른 stream인 stderr로 보낼 수도 있다. 
		// redirection을 할 때 stdout, stderr 나눠서 가능

		// TODO: use fputs() to write a file stream!

		count++;	// 글자수 세기
	}

	// file stream을 다 사용했다면 반드시 닫아줘야한다.
	fclose(fr);	// buffer에 남아있는 데이터를 처리
	// TODO:

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;
}
