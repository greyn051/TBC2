/*
## 7.2 표준 입출력 함수들 getchar(), putchar()
*/

#include <stdio.h> // getchar(), putchar()

int main() {

    /*
    	1. Introduce getchar(), putchar()
    	2. Use while loop to process character sequences
    	3. Filter a specific character
    	4. Convert numbers to asterisks
    	5. Lower characters to Upper characters
    */

    char ch;

    ch = getchar();		// 문자를 가져옴(입력)
    putchar(ch);		// 문자를 출력함

    return 0;
}


/*********************************************************
*********************************************************/


//⭐ getchar, putchar와 buffer

#include <stdio.h> // getchar(), putchar()

int main() {

    /*
    	1. Introduce getchar(), putchar()
    	2. Use while loop to process character sequences
    	3. Filter a specific character
    	4. Convert numbers to asterisks
    	5. Lower characters to Upper characters
    */

    char ch;

    ch = getchar();		// 문자를 가져옴(입력)
    // putchar(ch);		// 문자를 출력함

    while (ch != '\n') // Use '\n' to find the end of a sentence
    {
    	putchar(ch);

    	ch = getchar();
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/

/*
한글자만 입력받고 출력한댔는데 여러문자 다 됨.
이유는 buffer라는 공간에 입력받은 문자들을 두었다가
입력이 완료되면 한 글자 씩 출력해서 모두 다 출력한다.
(getchar와 putchar가 왕창 받았다가 왕창 처리 가능한 이유)
buffer라는 개념 매우 중요\*
*/

// 한 block안에 넣어 만들어 보자

int main() {

    /*
    	1. Introduce getchar(), putchar()
    	2. Use while loop to process character sequences
    	3. Filter a specific character
    	4. Convert numbers to asterisks
    	5. Lower characters to Upper characters
    */

    char ch;

    while ((ch = getchar()) != '\n')
    	putchar(ch);

    putchar(ch);

    return 0;
}

// while에 대입과 비교 모두 하는 구조


/*********************************************************
*********************************************************/


// 3. Filter a specific character

/*
입력한 문자를 원하는 문자로 바꾸기
if문 while 안에
*/

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    	if (ch == 'f')
    		ch = 'X';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    	if (ch == 'f')
    		ch = 'X';
    	else if (ch == 'F')
    		ch = 'X';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/


// 익숙해지면 논리연산자 쓴다.

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    	if (ch == 'f' || ch == 'F')
    		ch = 'X';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/


// 4. Convert numbers to asterisks

// 노가다

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    	if (ch == '0')
    		ch = '*';
    	if (ch == '1')
    		ch = '*';
    	if (ch == '2')
    		ch = '*';
    	if (ch == '3')
    		ch = '*';
    	if (ch == '4')
    		ch = '*';
    	// ...

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/


// for문 이용

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    	for (int i = '0'; i <= '9'; ++i)
    		if (ch == i)
    			ch = '*';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}

// && 이용

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    		if (ch >= '0' && ch <= '9')
    			ch = '*';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}


/*********************************************************
*********************************************************/


// 5. Lower characters to Upper characters⭐

int main() {

      char ch;

      while ((ch = getchar()) != '\n') {
      		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
      			ch -= 'a' - 'A';

      	putchar(ch);
      }

      putchar(ch);

      return 0;
}


/*********************************************************
*********************************************************/


// 대문자 > 소문자로도 바꾸기

int main() {

    char ch;

    while ((ch = getchar()) != '\n') {
    		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
    			ch -= 'a' - 'A';
    		else if (ch >= 'A' && ch <= 'Z')
    			ch += 'a' - 'A';

    	putchar(ch);
    }

    putchar(ch);

    return 0;
}
