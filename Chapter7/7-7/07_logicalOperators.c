/*
## 7.7 논리 연산자(Logical Operators)
*/

#define _CRT_SECURE_NO_WARNINGS

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


/*********************************************************
*********************************************************/


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


/*********************************************************
*********************************************************/


// 글자수에 줄바꿈은 제외하기

// ※ 내 코드
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


// ※ 교수님 코드
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


/*********************************************************
*********************************************************/


// 빈칸도 count 빼보자

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


/*********************************************************
*********************************************************/


// iso646.h

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


/*********************************************************
*********************************************************/


// 우선순위, 괄호

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


/*********************************************************
*********************************************************/


// ⭐Short-circuit Evaluation

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


/*********************************************************
*********************************************************/


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

/*
홍교수님은 개인적으로
저렇게 논리연산자에 증가연산자 쓰는 것을 매우 싫어함
왠만하면 헷갈리는 상황을 피해간다.
(성능에서 차이나는 경우가 있기 때문에 알아는 두어야한다.)
*/


/*********************************************************
*********************************************************/


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


/*********************************************************
*********************************************************/


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
