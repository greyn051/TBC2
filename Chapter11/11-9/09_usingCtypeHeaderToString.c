/*
## 11.9 문자 함수(ctype.h)를 문자열에 사용하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper(), ispunct(), ...

#define NUM_LIMIT 1024

void ToUpper(char*); // 대문자로 바꿔줌
int PunctCount(const char*); // 기호가 몇 개인지 세줌

int main() {

    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');	// find first newline
    /*
    	strchr이 '\n'이 나타나는 첫번째 포인터를 return 해준다.
    	그리고 그걸 밑에서 '\0'로 바꿔준다.
    */
    if (new_line)
    	* new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));

    return 0;
}

void ToUpper(char* str) // 문자열을 받기 위해서 문자의 포인터를 받음
{
    /*
    c코드를 볼 때, char(문자) type에 대한 포인터가 parameter로 사용되고 있다면
    대부분의 경우 문자에 대한 포인터라긴 보다 "문자열"을 받기 위해 사용되고 있다고 보면 된다.⭐
    */
    while (*str) {
        *str = toupper(*str);
        /* 코드를 좀 더 자세하게 만들고 싶다면(소문자인지 확인하고 대문자로 바꾸기)(퍼포먼스 아주 중요하다면)
        if (islower(*str))
        * str = toupper(*str);
        예전에는 이렇게 했지만 이제는 toupper()함수 안에 이런 기능이 있다.*/
        str++;
    }
}

int PunctCount(const char* str) {
int ct = 0;
while (*str) {
if (ispunct(*str))
ct++;
str++;
}

    return ct;
}
