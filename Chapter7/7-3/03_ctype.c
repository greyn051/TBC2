/*
## 7.3 ctype.h 문자 함수들
*/

/*
대문자 > 소문자
소문자 > 대문자
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // isalpha() and more

/*
    Reference link
    https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    		if (islower(ch)) // 'A' = 65, 'a' = 97
    			ch = toupper(ch);
    		else if (isupper(ch))
    			ch = tolower(ch);

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/

/*
    숫자 > *로 변환
    isdigit(ch) 사용
*/

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    		if (islower(ch)) // 'A' = 65, 'a' = 97
    			ch = toupper(ch);
    		else if (isupper(ch))
    			ch = tolower(ch);

    		if (isdigit(ch) != 0)
    			ch = '*';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}
