#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 읽어들인 파일 내용을 고대로 다른 파일로 저장하는 프로그램을 만들어라.
int     main(int argc, char *argv[])
{
    int     ch;
    FILE    *fr;    // TODO: file pointer to write
    FILE    *fw;

    /*
    typedef struct  _iobuf
    {
        char    *_ptr;
        int     _cnt;
        char    *_base;
        int     _flag;
        int     _file;
        int     _charbuf;
        int     _bufsiz;
        char    *tmpfname;
    }               FILE;
    */

    const char       *out_filename = "output.txt";   //TODO: Use this

    unsigned long    count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // fopen 함수는 파일 포인터를 return 해준다.
    if ((fr = fopen(argv[1], "r")) == NULL)  // Open a text file for reading.
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /*
        fopen mode strings for text files
        - r: reading
        - w: creating-and-writing or over-writing
        - a: appending or creating-and-writing
        - r+: both reading and writing
        - w+: reading and writing, over-writing or creating
        - a+: reading and writing, appending or creating
    */

    // TODO: open file to write with "w" mode string
    if ((fw = fopen(out_filename, "w")) == NULL)
    {
        printf("Can't write %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 파일 스트림으로 부터 데이터를 읽어오는 과정
    while ((ch = fgetc(fr)) != EOF)  // getc(fr)
    {
        //putc(ch, stdout);  // same as putchar(ch);
        fputc(ch, stdout);

        // TODO: use fputs() to write a file stream!
 
        count++;
    }
    char    *file_string;   // 파일에서 문자열 받기 실패

    fputs(fgets(file_string, count, fr), fw);

    fclose(fr);
    // TODO: 다 썼으면 닫아라
    fclose(fw);

    printf("FILE %s has %lu characters\n", argv[1], count);

    return 0;
}

/*
    https://www.tutorialspoint.com/c_standard_library/c_function_fputc.htm
    참고하자
*/