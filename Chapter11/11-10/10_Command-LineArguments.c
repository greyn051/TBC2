/*
## 11.10 명령줄 인수(Command-Line Arguments)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char * argv[]) // char pointer array의 용도는 문자열의 배열
/*
    arguments에 어떻게 넣을까?
    프로그램을 실행할 때 프로그래머나 사용자가 넣을 수 있다.
    command prompt에 입력
*/
{

    int count;

    printf("The command line has %d arguments:\n", argc);

    for (count = 0; count < argc; count++)
    	printf("Arg %d : %s\n", count, argv[count]);
    printf("\n");

    return 0;
}

/*
---

command line에서 실행한 내용

---

** Visual Studio 2019 Developer Command Prompt v16.8.4
** Copyright (c) 2020 Microsoft Corporation

---

D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe
The command line has 1 arguments:
Arg 0 : D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe

D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe hello world 1234 3.14
The command line has 5 arguments:
Arg 0 : D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe
Arg 1 : hello
Arg 2 : world
Arg 3 : 1234
Arg 4 : 3.14

D:\dev\repository\C\Chapter_3\Chapter_3>

---
*/