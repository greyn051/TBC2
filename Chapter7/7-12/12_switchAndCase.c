/*
## 7.12 다중 선택 switch와 case
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>

int main() {

    char c;
    while ((c = getchar()) != '.') {
    	printf("You love ");

    	switch (c)	//Note: integer types only // char, int 같은 정수형만 switch 사용 가능
    	{
    	case 'a':
    		printf("apple");
    		break;
    	case 'b':
    		printf("baseball");
    		break;
    	case 'c':
    		printf("cake");
    		break;
    	default:
    		printf("nothing");
    	}

    	printf(".\n");

    	while (getchar() != '\n')	// 첫글자 이후에 나머지 글자들 무시하겠다.
    		continue;
    }

    //TODO: upper letters ? (use tolower()?) // 대문자가 들어왔을 때도 같이 실행
    // switch (tolower(c)) 쓰면 됨
    /*
    	혹은
    	case 'a':
    	case 'A':
    		printf("apple");
    		break;
    	이런 식으로 써도 됨
    */

    return 0;
}
