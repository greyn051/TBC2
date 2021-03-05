# TBC-7 분기

## 7.1 분기문 if

ex)
TODO: print even or odd

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int number;

	printf("Input a positive integer : ");
	scanf("%d", &number);

	//TODO: print even or odd

	if (number % 2 == 0)
		printf("Even");

	if (number % 2 != 0)
		printf("Odd");

	return 0;
}
```

if else문 써보자

```c
int main() {

	int number;

	printf("Input a positive integer : ");
	scanf("%d", &number);

	//TODO: print even or odd

	if (number % 2 == 0)
		printf("Even");
	else // if (number % 2 != 0)
		printf("Odd");

	return 0;
}
```

//

## 7.2 표준 입출력 함수들 getchar(), putchar()

```c
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
```

//

- getchar, putchar와 buffer

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

한글자만 입력받고 출력한댔는데 여러문자 다 됨.
이유는 buffer라는 공간에 입력받은 문자들을 두었다가
입력이 완료되면 한 글자 씩 출력해서 모두 다 출력한다.
(getchar와 putchar가 왕창 받았다가 왕창 처리 가능한 이유)
buffer라는 개념 매우 중요\*

//
한 block안에 넣어 만들어 보자

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

while에 대입과 비교 모두 하는 구조
// 3. Filter a specific character
입력한 문자를 원하는 문자로 바꾸기
if문 while 안에

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

//

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

//
익숙해지면 논리연산자 쓴다.

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

// 4. Convert numbers to asterisks

노가다
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

//
for문 이용

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

//
&& 이용

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

// 5. Lower characters to Upper characters

- int main() {

      char ch;

      while ((ch = getchar()) != '\n') {
      		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
      			ch -= 'a' - 'A';

      	putchar(ch);
      }

      putchar(ch);

      return 0;

  }

//
대문자 > 소문자로도 바꾸기

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

//
#7.3 ctype.h 문자 함수들

대문자 > 소문자
소문자 > 대문자

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // isalpha() and more

/_
Reference link
https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
_/

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

//
숫자 > \*로 변환
isdigit(ch) 사용

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

//
#7.4 다중 선택 else if

종합소득세 계산하는 프로그램 만드는 문제

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// assessment standard tax base
#define BASE1 12000000.0
#define BASE2 46000000.0
#define BASE3 88000000.0
#define BASE4 150000000.0
#define BASE5 300000000.0
#define BASE6 500000000.0

#define RATE1 (6.0 / 100.0) // percent to rate
#define RATE2 (15.0 / 100.0)
#define RATE3 (24.0 / 100.0)
#define RATE4 (35.0 / 100.0)
#define RATE5 (38.0 / 100.0)
#define RATE6 (40.0 / 100.0)
#define RATE7 (42.0 / 100.0)

#define BASIC_DEDUCTION 1500000.0

int main() {

    double income = 0.0;		// annual income
    double tax = 0.0;

    scanf("%lf", &income);

    income -= BASIC_DEDUCTION;

    if (income <= BASE1) {
    	tax = income * RATE1;
    }
    else if (income <= BASE2) {
    	tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
    }
    else if (income <= BASE3) {
    	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
    }
    else if (income <= BASE4) {
    	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (income - BASE3) * RATE4;
    }
    else if (income <= BASE5) {
    	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
    		+ (income - BASE4) * RATE5;
    }
    else if (income <= BASE6) {
    	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
    		+ (BASE5 - BASE4) * RATE5 + (income - BASE5) * RATE6;
    }
    else if (income > BASE6) {
    	tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3 + (BASE4 - BASE3) * RATE4
    		+ (BASE5 - BASE4) * RATE5 + (BASE6 - BASE5) * RATE6 + (income - BASE6) * RATE7;
    }

    printf("Tax is = %f\n", tax);
    printf("Your income after tax deduction = %f", income - tax);

    return 0;

}

빈칸보고 똑같이 구현함

마지막 else if에
else만 가능

else // if (income > BASE6)
{
tax = BASE1 _ RATE1 + (BASE2 - BASE1) _ RATE2 + (BASE3 - BASE2) _ RATE3 + (BASE4 - BASE3) _ RATE4 + (BASE5 - BASE4) _ RATE5 + (BASE6 - BASE5) _ RATE6 + (income - BASE6) \* RATE7;
}
//

#7.5 else와 if 짝짓기

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int number;
    scanf("%d", &number);

    if (number == 1)
    	printf("One");
    else if (number == 2)
    	printf("Two");
    else if (number == 3)
    	printf("Three");

    return 0;

}

//

int main() {

    int number;
    scanf("%d", &number);

    if (number == 1)
    	printf("One");
    else
    	if (number == 2)
    		printf("Two");
    	else
    		if (number == 3)
    			printf("Three");

    // minimun 127 levels of nestings

    return 0;

}

//
컴파일러는 인덴팅 무시함

int main() {

    int number;
    scanf("%d", &number);

    if (number > 5)
    	if (number < 10)
    		printf("Larger than 5 smaller than 10\n");
    else
    	printf("Less than or equal to 5");
    /*	else
    		printf("Less than or equal to 5"); */

    // Compilers ignore indenting

    return 0;

}
밑 if에 else가 적용된다.
\*else는 가까이 있는 if에 적용된다.

//
위 if에 else 붙이고 싶다면 \*헷갈릴 여지가 있는 경우 중괄호{}를 쳐라

int main() {

    int number;
    scanf("%d", &number);

    if (number > 5)
    {
    	if (number < 10)
    		printf("Larger than 5 smaller than 10\n");
    	else
    		printf("Larger 10\n");
    }
    else
    	printf("Less than or equal to 5");

    return 0;

}

//
#7.6 소수 판단 예제

소수인지 아닌지 판별하는 프로그램 만드는 예제
prime number : 소수

※ 내가 한 코드
#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {

    unsigned num;
    bool isPrime = 0; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    if (num == 2) {
    	isPrime = 1;
    }

    for (unsigned i = 2; i < num; ++i) {
    	if (num % i == 0) {
    		isPrime = 0;
    		break;
    	}
    	else {
    		isPrime = 1;
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;

}

※ 교수님 코드
int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; div < num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;

}

//
위 프로그램을 좀 더 업그레이드해서 약수까지 찾게 만들기

int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; div < num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;
    		printf("%u is divisible by %u.\n", num, div);
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;

}

//
중복되는 약수 줄이기
ex) 2로 나누어지면 4나 8로도 나누어진다고 출력x

int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; (div*div) <= num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;

    		if (num == div * div)
    			printf("%u is divisible by %u.\n", num, div);
    		else
    			printf("%u is divisible by %u and %u.\n", num, div, num/div);
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;

}

//
#7.7 논리 연산자(Logical Operators)

#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> // islower()
#include <stdbool.h>
#include <iso646.h> // and, or, not

#define PERIOD '.'

int main() {

    /*
    	Logical operators

    	&& : and
    	|| : or
    	!  : not
    */

    bool test1 = 3 > 2 || 5 > 6;	// true
    bool test2 = 3 > 2 && 5 > 6;	// false
    bool test3 = !(5 > 6);			// true, equivalent to 5 <= 6

    printf("%d %d %d\n", test1, test2, test3);

    return 0;

}

//

#define PERIOD '.'

int main() {

    /* Character counting example */
    // 적은 글자수 세는 프로그램

    char ch;
    int count = 0;

    while ((ch = getchar()) != PERIOD) {
    	//TODO: make exceptions
    	count++;
    }

    printf("%d", count);

    return 0;

}

//
글자수에 줄바꿈은 제외하기

※ 내 코드
#define PERIOD '.'

int main() {

    /* Character counting example */
    // 적은 글자수 세는 프로그램

    char ch;
    int count = 0;

    while ((ch = getchar()) != PERIOD) {
    	//TODO: make exceptions
    	if (ch == '\n') {}
    	else
    		count++;
    }

    printf("%d", count);

    return 0;

}

※ 교수님 코드
int main() {

    /* Character counting example */
    // 적은 글자수 세는 프로그램

    char ch;
    int count = 0;

    while ((ch = getchar()) != PERIOD) {
    	//TODO: make exceptions
    	if (ch != '\n')
    		count++;
    }

    printf("%d", count);

    return 0;

}

//
빈칸도 count 빼보자

#define PERIOD '.'

int main() {

    /* Character counting example */
    // 적은 글자수 세는 프로그램

    char ch;
    int count = 0;

    while ((ch = getchar()) != PERIOD) {
    	//TODO: make exceptions
    	if (ch != '\n' && ch != ' ')
    		count++;
    }

    printf("%d", count);

    return 0;

}

//
iso646.h

int main() {

    /*
    	Alternatives in iso646.h	// 그냥 and, or, not 치면 됨 (#define됨)

    	&&	: and
    	||	: or
    	!	: not
    */
    // 그런데 잘 안씀(오픈소스에서도 쓴 걸 본 적이 없음)
    // C프로그래밍은 기호를 쓰자

    bool test1 = 3 > 2 or 5 > 6;	// true
    bool test2 = 3 > 2 and 5 > 6;	// false
    bool test3 = not(5 > 6);		// true, equivalent to 5 <= 6

    printf("%d %d %d\n", test1, test2, test3);


    return 0;

}

//
우선순위, 괄호

int main() {

    /*
    	Precedence

    	Check !, &&, !! in the operator precedence table
    	https://en.cppreference.com/w/c/language/operator_precedence
    */

    int a = 1, b = 2, c = 3, d = 4;

    a > b && b > c || b > d;
    ((a > b) && (b > c)) || (b > d);	// 위를 정리하면 이런 형태
    /*
    	실무에선 그냥 밑의 형태로 쓰자
    	내가 어떤 의도로 표현했는지를 나타내야한다.
    	실력 좋은 프로그래머도 위의 형태는 바로 의미 알기 힘들고 실력의 척도도 아님.
    */

    return 0;

}

//
\*Short-circuit Evaluation

int main() {

    /*
    	Short-circuit Evaluation

    	- Logical expressions are evaluated from left to right
    	- && and || are sequence points
    */

    int temp = (1 + 2) * (3 + 4);

    printf("Before : %d\n", temp);

    if (temp == 0 && (++temp == 1024)) {
    	// do nothing
    };
    // 위 if문에서 2번째 조건이 실행이 될 것인가를 주시
    // and를 평가할 때 둘 중 하나만 false면 다 false
    // 그래서 앞이 false면 뒤에는 계산하지 않는다.*(중요)

    printf("After : %d\n", temp);

    return 0;

}

//

int main() {

    /*
    	Short-circuit Evaluation

    	- Logical expressions are evaluated from left to right
    	- && and || are sequence points
    */

    int x = 1, y = 2;
    if (x++ > 0 && x + y == 4)	// x++가 언제 계산될까?
    	printf("%d %d\n", x, y);

    /*
    	sequence point를 만나면 그 전에 있던 식이 계산이 된다.
    	x++도 만나면 계산이 된다는 소리
    */

    return 0;

}

홍교수님은 개인적으로
저렇게 논리연산자에 증가연산자 쓰는 것을 매우 싫어함
왠만하면 헷갈리는 상황을 피해간다.
(성능에서 차이나는 경우가 있기 때문에 알아는 두어야한다.)

//
int main() {

    /* Ranges */

    for (int i = 0; i < 100; ++i)
    	if (i >= 10 && i <= 20)
    		printf("%d ", i);

    printf("\n");

    // 초보때는 아래와 같이 실수 가능

    //for (int i = 0; i < 100; ++i)
    //	if (10 <= i <= 20)		// Note: if((10 <= i) <= 20) 컴파일러는 이렇게 인식
    //		printf("%d ", i);

    // 문법 오류가 아니라 문맥오류가 떠서 디버그로 못 잡는다.(문법적으로는 맞기 때문)


    return 0;

}

//

int main() {

    /* Ranges */

    for (char c = -128; c < 127; ++c)
    	if (c >= 'a' && c <= 'z')
    		printf("%c ", c);

    printf("\n");

    for (char c = 0; c < 127; ++c)
    	if (islower(c))
    		printf("%c ", c);

    // 위 두가지 방식 다 사용하긴 한다.

    return 0;

}

//
#7.8 단어 세기 예제

ex) 입력 받은 문장에서 단어가 몇 개인지 세는 프로그램
characters
words
line
개수 다 나오게
.를 입력하면 개수 출력 후 종료

※ 내가 한 코드 1
(내가 작성했지만 참 주먹구구식이다..)
(bool 언제 쓸지 몰라서 안 씀)
(첫 번째 힌트만 보고 작성)
(작동은 됨)

#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> // islower()
#include <stdbool.h>

#define STOP '.'

int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 1;
    int n_words = 1;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {

    	if (c != ' ' && c != '\n') {
    		n_chars++;
    	}
    	else if (c == '\n') {
    		n_lines++;
    	}
    	else if (c == ' ') {
    		n_words++;
    	}
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;

}

※ 내가 한 코드 2
(두 번째 힌트 본 후 작성)

#define STOP '.'

int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 0;
    int n_words = 0;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {
    	if (!isspace(c))	// 빈칸이 아니라면 (isspace(c) == false)도 가능(실수 줄이기) !isspace처럼 간결한 것이 c코딩 스타일(컴퓨터에게 인간을 맞춰주기 위해 주의력을 기르자!)
    		n_chars++;	// count non-space characters

    	if (!isspace(c) && !line_flag) {
    		n_lines++;
    		line_flag = true;
    	}

    	if (c == '\n') {
    		line_flag = false;
    		word_flag = false; // 이건 내가 추가
    	}

    	// 위에 힌트 이용해서 words 구현

    	if (!isspace(c) && !word_flag) {
    		n_words++;
    		word_flag = true;
    	}

    	if (c == ' ')
    		word_flag = false;
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;

}

※ 교수님 코드

int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 0;
    int n_words = 0;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {
    	if (!isspace(c))
    		n_chars++;

    	if (!isspace(c) && !line_flag) {
    		n_lines++;
    		line_flag = true;
    	}

    	if (c == '\n') {
    		line_flag = false;
    	}

    	if (!isspace(c) && !word_flag) {
    		n_words++;
    		word_flag = true;
    	}

    	if (isspace(c))
    		word_flag = false;
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;

}

//
#7.9 조건 연산자(Conditional Operator) ? :

#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

int main() {

    int temp;
    temp = true ? 1024 : 7; // ternary (항이 3개라서)(근데 3항연산자보다 조건연산자라고 부르는 것이 일반적)
    printf("%d\n", temp);

    temp = false ? 1024 : 7;
    printf("%d\n", temp);

    return 0;

}

//

int main() {

    int a = 1, b = 2;
    int max = (a > b) ? a : b;

    return 0;

}

//
홀짝 구분

int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    if (number % 2 == 0)
    	is_even = true;
    else
    	is_even = false;

    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;

}

//
위의 코드의 첫번째 if문을 조건연산자를 이용해서 구현해라

※ 내가 한 코드

int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    is_even = ((number % 2) == 0) ? true : false;

    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;

}

※ 교수님 코드
int main() {

    int number;
    scanf("%d", &number);

    bool is_even;

    is_even = (number % 2 == 0) ? true : false;  // ?는 연산자 우선순위가 매우 낮다. 그래도 대부분의 경우 보기 편하라고 괄호를 친다.

    // bool is_even = (number % 2 == 0) ? true : false; // 이렇게 쓰기도 한다.
    // const bool is_even = (number % 2 == 0) ? true : false; // 이렇게 쓰기도 한다.


    if (is_even)
    	printf("Even");
    else
    	printf("Odd");

    return 0;

}

//
홀짝 판별 코드 입력제외 한 줄로 줄이기

※ 내 코드

int main() {

    int number;
    scanf("%d", &number);

    (number % 2 == 0) ? printf("Even") : printf("Odd");

    return 0;

}

※ 교수님 코드 = 내 코드

위에 처럼 사용은 가능하지만 잘 사용하진 않는다.

보통
bool is_even = ~
처럼 flag를 선언하고
그에 따라서 기능을 수행하는 것이 일반적이다.

//
#7.10 루프 도우미 continue와 break

//
continue

#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    /* continue */
    for (int i = 0; i < 10; ++i) {
    	if (i == 5)
    		continue;

    	printf("%d ", i);	// i == 5에서 continue가 실행되면 여기 printf 실행 x

    	/*
    	if (i != 5)
    		printf("%d ", i); // 와 기능 같다.
    	*/
    }

    return 0;

}

//
break

int main() {

    /* break */
    for (int i = 0; i < 10; ++i) {
    	if (i == 5)
    		break;

    	printf("%d ", i);
    }

    return 0;

}

//

int main() {

    /* while and continue */
    int count = 0;
    while (count < 5) {
    	int c = getchar();
    	if (c == 'a')
    		continue;
    	putchar(c);
    	count++;
    }

    return 0;

}

//

int main() {

    /* for and continue */
    for (int count = 0; count < 10; ++count) {
    	int c = getchar();
    	if (c == 'a')
    		continue;
    	putchar(c);
    }

    return 0;

}

//
placeholder

int main() {

    /* continue as a placeholder */
    while (getchar() != '\n')
    	continue;

    return 0;

}

//

int main() {

    /* Need to use continue */
    char c;
    while ((c = getchar()) != '\n') {
    	if (c == 'a')
    		continue;
    	putchar(c);

    	//if (c != 'a')
    	//	putchar(c); // 이렇게 바꿔도 기능 동일

    	/*
    		위 2가지는 관점이 다르다. 늬앙스가 다르다.
    		(cotinue를 쓸 수도 안 쓸 수도 있다.)
    		밑이 간결하다.
    		하지만 나중에 실무에 가서 복잡한 코드를 작성하거나 유지보수할 때
    		continue를 사용하는 것이 좋다.
    	*/
    }

    return 0;

}

//

- while(1), break

int main() {

    /* break */
    char c;

    /*
    while ((c = getchar()) != '.') {
    	putchar(c);
    }
    같은 것을 아래와 같이 break를 이용해서 구현 가능
    */

    while (1) {
    	char c = getchar();

    	if (c == '.')
    		break;

    	putchar(c);
    } // 이렇게 구현하는 형태가 더 많다.
    // 이해하기 쉽다. ~하는데 ~할 때 그만둬!

    /*
    	while문의 조건에다가 기능을 수행하는 조건을 같이 넣으면
    	한 부분에 여러가지 기능(반복위해 비교, 글자 입력)을 같이
    	수행하기 때문에 헷갈릴 가능성이 높다.
    	(한 곳에 한 가지 기능을 수행하게 하는 것이 좋다.)
    */

    return 0;

}

//
다중 루프에서 break

int main() {

    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		if (j == 5)
    			break;

    		printf("(%d %d)", i, j);
    	}
    	printf("\n");
    }

    return 0;

}

//
#7.11 최대, 최소, 평균 구하기 예제

여러 값 입력 받고 그 중에서 가장 작은수, 큰 수 그리고 전체 평균을 출력하는 프로그램

※ 내 코드
#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>

int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {
    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	//TODO: ignore negative values

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;

}

※ 교수님 코드 = 내 코드

//
음수 무시, 100 이하 값만 받기

※ 내 코드
int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {

    	//TODO: ignore negative values and accept value below 100.
    	if (input < 0)
    		continue;
    	else if (input > 100)
    		continue;

    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;

}

※ 교수님 코드
int main() {

    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    while (scanf("%f", &input) == 1) {

    	if (input < 0.0f || input > 100.0f) continue;

    	max = (input > max) ? input : max;
    	min = (input < min) ? input : min;
    	sum += input;

    	n++; // Count number of inputs
    }

    if (n > 0)
    	printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    else
    	printf("No input\n");

    return 0;

}

//
#7.12 다중 선택 switch와 case

#define \_CRT_SECURE_NO_WARNINGS

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

//
#7.13 goto를 피하는 방법

#define \_CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <float.h>

int main() {

    /* if else */
    int size = 15, cost;

    if (size < 10)
    	goto a;		// label
    goto b;

a: cost = 50 _ size;
b: cost = 100 _ size;

    if (size < 10)
    	cost = 50 * size;
    cost = 100 * size;
    /* 바로 위 cost 대신 else도 가능
    else
    	cost = 100 * size;
    */

    /* loop */
    char c;

read: c = getchar();
putchar(c);
if (c == '.') goto quit;
goto read;
quit:

    while (1) {
    	c = getchar();
    	putchar(c);
    	if (c == '.') break;
    }
    // 실무에서는 block을 써서 이 부분이 loop인 것을 명확하게 표현
    // 나가야할 조건에는 break; 사용

    return 0;

}

예전에는 goto문을 매우 많이 사용했다.

cpu가 일을 할 때 goto문 처럼 한다.

그러나 사람이 프로그래밍할 때는 꼭 cpu에 맞춰서 할 필요는 없다. 현대 프로그래밍 기법에서는 사람이 작업하고 이해하고 수정하고 유지보수 하기 좋은 방법으로 한다.

가급적이면 goto를 사용하지 않도록 한다.

//
