# TBC-6 반복문

## 6.1 while 반복 루프에서 scanf()의 반환값 사용하기

여러개의 값을 받다가 q를 입력하면
이전에 입력했던 값들을 모두 더한 합을 보여주고 종료 하는 프로그램 만들기

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num, sum = 0;
	int status;		// scanf함수의 반환값 저장할 변수 선언

	printf("Enter an integer (q to quit) : ");

	status = scanf("%d", &num);		// return value of scanf() // scanf의 반환값은 입력받은 변수의 개수를 return 값으로 돌려줌
									// 정수를 입력하면 num이라는 변수에 하나를 입력받았기 때문에 status 변수에 1이라는 값이 저장됨.
									// 만약 숫자가 아니라 q라는 문자를 입력했다면 그 때는 정수로 입력을 받을 수가 없기 때문에 입력을 받지 않는다. 그럼 입력받은 변수의 개수가 0이므로 status의 값도 0이다.

	while (status == 1)				// equality operator (==)
	{
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d", num);

	//TODO: C-style shortcut

	return 0;
}
```

※ 내가 한 코드(실패)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;

	printf("Enter an integer (q to quit) : ");
	scanf("%d", &n);

	while (n != 113 ) {

		sum += n;
		printf("Enter next integer (q to quit) : ");
		scanf("%d", &n);

	}

	printf("%d", sum);

	return 0;
}
```

//
⭐반복되는 코드 줄이기(status 부분) //TODO: C-style shortcut

```c
int main() {
    int num, sum = 0;
    printf("Enter an integer (q to quit) : ");

    while (scanf("%d", &num) == 1)	// 장점: 코드가 깔끔해짐, 단점: 코드를 주의깊게 봐야함
    {
    	sum = sum + num;

    	printf("Enter next integer (q to quit) : ");
    }

    printf("Sum = %d", num);

    //TODO: C-style shortcut

    return 0;
}
```

//

## 6.3 진입조건 루프(Entry-Condition Loop) while

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    /*
    while (expression)
    	statement
    */

    int i;

    i = 1;
    while (i < 5)		// infinite loop
    	printf("Hi\n"); // iteration (반복)(변수 i를 쓰는 심증)

    i = 1;
    while (--i < 5)		// wrong direction
    	printf("Hi!\n");

    i = 1;
    while (i < 5)
    {
    	printf("i before = %d\n", i);
    	i++;
    	printf("i after = %d\n", i);
    }

    i = 10;
    while (i++ < 5)		// cannot enter
    {
    	printf("Hi\n");
    }

    /* Common mistakes */

    i = 0;
    while (i < 3)
    	printf("%i\n", i);
    	i++; // indenting

    i = 0;
    while (i++ < 3);		// null statement
    	printf("%i\n", i);

    while (scanf("%d", &i) == 1)
    	;// null statement
    // do something (?)

    return 0;
}
```

//

## 6.4 관계 연산자(Relational Operator)

```c
#include <stdio.h>

int main() {

    /*
       Relational Operators
       <	   is less than
       <=      is less than
       ==	   is less than
       >=	   is less than
       >	   is less than
       !=	   is less than
    */

    int n = 0;
    while (n++ < 5)		// n++ < 5 is a relational expression
    	printf("%d", n);

    printf("\n");

    char c = 'A';
    while (c != 'Z')
    	printf("%c ", c++);

    return 0;
}
```

//

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> //fabs()

int main() {
    // 상수 정의 할 때 const 사용 권장
    const double PI = 3.1415026535897932384626433832795;
    double guess = 0.0;

    printf("Input pi : ");
    scanf("%lf", &guess);
    //while (guess != PI)		// 실수 끼리 비교 할 때 != 잘 안 쓴다.(매우 정확하게 일치해야하므로) 그래서 math.h 쓰자!
    while (fabs(guess - PI) > 0.01)		// 차이가 0.01보다 작으면 ok
    {
    	printf("Fool! Try again.\n");
    	scanf("%lf", &guess);
    }

    printf("Good!");

    return 0;
}
```

//

## 6.5 사실과 거짓

```c
#include <stdio.h>

int main() {
    int tv, fv;
    tv = (1 < 2); // true value
    fv = (1 > 2); // false value

    printf("True is %d\n", tv);
    printf("False is %d\n", fv);

    return 0;
}
```

//

```c
int main() {
    int i = -5;
    while (i)
    printf("%d is true\n", i++);
    printf("%d is false\n", i);

    return 0;
}
```

//

## 6.6 \_Bool 자료형

```c
#include <stdio.h>

int main() {
    int i;
    //i = 5; // 대입
    //i == 5; // 비교
    //5 = i;
    //5 == i; // 문법 오류가 없음(비교이기 때문)

    while (i = 5) {/*do something*/ }; // i에 5가 대입되고, expression이 5가 되어 true로 간주됨 but 이렇게 작성한 것은 90%이상 실수한 것일 거임.(실제로 이렇게 사용x, 밑에처럼 사용함)
    while (i == 5) {/*do something*/ };

    return 0;
}
```

//

```c
int main() {
    _Bool boolean_true = (2 > 1); // 이전에 boolean 타입 쓰던 사람들이 bool이라고 지정해서 사용해왔기 때문에 호환성을 유지하려고 \_Bool로 지음
    _Bool boolean_false = (1 > 2); // Bool 자료형도 내부적으로는 '정수형'으로 처리된다.

    printf("True is %d\n", boolean_true);
    printf("False is %d\n", boolean_false);

    printf(boolean_true ? "true" : "false");
    printf("\n");
    printf(boolean_false ? "true" : "false");

    return 0;
}
```

//

```c
#include <stdbool.h> 추가하고 나서

#include <stdio.h>
#include <stdbool.h>

int main() {
    bool bt = true; // 키워드는 아니라서 파란색이 아니다
    bool bf = false; // 예전에 프로그래머들이 bool 만들어서 쓰던거 표준화한 것임

    printf("\n");
    printf("True is %d\n", bt);
    printf("Flase is %d\n", bf);

    return 0;
}
```

//

## 6.7 관계 연산자의 우선순위

```c
#include <stdio.h>

int main() {
    int x = 1, y = 2, z;

    x > y + 2;		// +가 > 우선순위 높아서 밑과 같다.
    x > (y + 2);	// 지금 붙어 있는 statement들은 같은 의미라는 뜻이다.

    x = y > 2;
    x = (y > 2);

    z = x > y;
    z = (x > y);

    x != y == z;	// 우선순위가 같으면 왼쪽에서 오른쪽 순서로 진행
    (x != y) == z;

    return 0;
}
```

//

## 6.8 for 루프 소개

//
while은 indefinite loop를 목적으로 설계

```c
#include <stdio.h>

int main() {
    // Indefinte loop vs. Counting loop
    while (1) {
    // do something
    }

    /*
    	Counting Loop
    	1. Counter initialization
    	2. Counter check
    	3. Counter change
    */

    int i;

    i = 1;

    while (i <= 10)			//Note: <=
    {
    	printf("%d ", i);
    	i++;
    }

    return 0;
}
```

//
counting loop 목적인 for문

위와 같은 기능을 for문으로 구현하자

```c
#include <stdio.h>

int main() {
int i;

    for (i = 1; i <= 10; i++)
    	printf("%d ", i);

    /* or
    for (int i = 1; i <= 10; i++)
    	printf("%d ", i);
    와 같다*/

    return 0;
}
```

//

```c
int main() {
    for (int i = 1; i <= 10; i++) {
    printf("dummy ");
    printf("%d ", i);
    }

    return 0;
}
```

## 6.9 for는 유연해요

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    /*
    for(initialize; test; update)
    statement
    */

    for (int i = 10; i > 0; i--)
    	printf("%d ", i);

    for (int i = 0; i < 100; i = 1 + 8)
    	printf("%d ", i);

    for (char c = 'A'; c <= 'Z'; c++)
    	printf("%c ", c);

    for (int i = 0; i * i < 10; i++)
    	printf("%d ", i);

    for (int x = 1, y = 5; y <= 20; y = (++x * 3) + 10)  // 같은 자료형의 변수 여러개 초기화 가능
    	printf("%d ", x);

    for (double d = 100.0; d < 300; d = d * 1.1)
    	printf("%f\n", d);

    int i, n;
    n = 2;
    for (i = 2; n < 10; /* left blank */) {
    	n = n * i;
    	printf("%d\n", n);
    }

    for ( ; ; ) // while(1)과 동일
    	printf("I love you! ");

    int i = 0;
    for (printf("Let's go!\n"); i != 7; scanf("%d", &i))	// 이 정도 과도하긴 한데 가능하다. 그런데 사용하지 않는게 좋다.
    	; // null statement

    return 0;
}
```

//

## 6.10 다양한 대입 연산자들 (그리고 어셈블리 코드 확인법)

```c
#include <stdio.h>

int main() {
    /*
    +=, -=, *=, /=, %=
    */

    int i = 1024;

    i = i + 10;
    i += 10;

    i %= 4;

    i = i * (1 + 2);
    i *= 1 + 2;
    i *= (1 + 2);	// Check precedence

    for (int i = 0; i < 10; i += 2)		// i = i + 2 보단 i += 2를 주로 쓴다. +1인 경우에는 i++.
    	;

    return 0;
}
```

//

## 6.11 콤마(,) 연산자 Comma

```c
#include <stdio.h>

int main() {
    // , 씀으로서 여러줄에 하는 것을 한줄로도 할 수 있다.
    for (int n = 1, nsqr = n _ n; n < 10; n++, nsqr = n _ n)
    printf("%d %d\n", n, nsqr);

    // Note that commas in printf() are not comma operators
    // but separators

    return 0;
}
```

//

,도 ;와 같은 sequence point

```c
int main() {
    int i, j;
    i = 1;
    i++, j = i; // comma is a sequence point
    printf("%d %d\n", i, j);

    return 0;
}
```

//

```c
int main() {
    // ,의 연산자 우선순위는 가장 마지막. 그리고 왼쪽에서 오른쪽으로 진행한다.(Left-to-right)
    int x, y, z;
    z = x = 1, y = 2;
    printf("x=%d, y=%d, z=%d \n", x, y, z);
    z = (x = 1), (y = 2);
    printf("x=%d, y=%d, z=%d \n", x, y, z);
    z = ((x = 1), (y = 2)); // ,는 오른쪽에 있는 것이 expression값이다. 그래서 z에는 2가 대입된다.
    printf("x=%d, y=%d, z=%d \n", x, y, z);

    return 0;
}
```

//

```c
int main() {
    //int my_money = 123,456; // error 프로그래밍 언어에서 숫자에 ,찍으면 에러난다.
    int my_money = (123, 456); // , 오른쪽이 전체 expression의 값
    printf("%d\n", my_money);

    return 0;
}
```

//

## 6.12 제논의 역설 시뮬레이션 예제

//

    /*
    	Simulation of a Moving Object

    	- Speed = 1.0 m/s
    	- dt = 1.0 s
    	- Distance traveled during dt = Speed * dt

    	- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
    	- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
    	- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
    	- ... ...
    */ 이러한 코드 만들기

※ 내가 한 코드

```c
#include <stdio.h>

int main() {

    double speed = 1.0, dt = 0, distance = 0;

    for (dt = 1; dt <= 10; dt++) {
    	distance = speed * dt;

    	printf("Elapsed time = %lfs, ", dt);
    	printf("Distance = %lfm\n", distance);
    }

    return 0;
}
```

※ 교수님 코드

```c
#include <stdio.h>

int main() {
    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);
    }

    return 0;
}
```

//
위에 코드 수정해서 제논의 역설 식 만들기

    /*
    	Zeno's Paradox

    	- Step 1 : 1.0 * 1.0 = 1.0, 1.0
    	- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
    	- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75
    	... ...(1step 마다 dt를 절반으로 줄여서 계산)
    */

※ 내가 한 코드

```c
#include <stdio.h>

int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

    	//TODO: half time step
    	dt = dt / 2;
    }

    //Note: infinite geometric series

    return 0;
}
```

dt가 double일 때 dt = dt / 2; 해도 되긴 한다.
하지만 C/C++의 엄격함을 따라 가려면 dt = dt / 2.0;으로 쓰는 것이 좋다.

그리고 *(곱하기)가 /(나누기)보다 빠르다.
그래서 *를 쓰는 것이 좋다.
dt = dt / 2.0;을 dt = dt _ 0.5;로 쓰는 것이 일반적. 더 나아가서 dt _= 0.5;

```c
int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 10;

    double dt = 1.0;
    double time = 0.0;		// Elaped time
    double dist = 0.0;		// Distance

    for (unsigned i = 0; i < repeat_max; ++i) {

    	dist += speed * dt; // dist = dist + speed * dt;
    	time += dt;

    	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

    	//TODO: half time step
    	dt *= 0.5;
    }

    //Note: infinite geometric series

    return 0;
}
```

repeat_max를 100으로 해도 time이 2를 넘어가지 못한다.
제논의 역설에서 말하는 무한 등비 급수 infinite geometric series

//
제논의 역설 구현

```c
int main() {

    const double speed = 1.0;
    const unsigned repeat_max = 50;

    double time = 0.0;			// Elaped time
    double dist_arch = 0.0;		// Achilleus distance from start point
    double dist_turtle = 1.0;	// turtle distance from start point
    double speed_arch = 10.0;
    double speed_turtle = 0.001;
    double dt = 0.01;
    unsigned i;

    printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
    	time, dt, dist_arch, dist_turtle);

    for (i = 0; i < repeat_max; ++i) {

    	dist_arch += speed_arch * dt;
    	dist_turtle += speed_turtle * dt;
    	time += dt;

    	printf("Time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
    		time, dt, dist_arch, dist_turtle);

    	dt *= 0.5;
    }

    //Note: infinite geometric series

    return 0;
}
```

//

## 6.13 탈출조건 루프(Exit-Condition Loop) do while

비밀번호를 미리 설정해 놓고 그 비밀번호를 여러번 쳐서
알맞는 숫자를 입력하면 끝나는 프로그램 만들어보자

※ 내 코드

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    const unsigned int secret_code = 337;
    unsigned int input = 0;

    while (input != secret_code) {
    	printf("Enter secret code : ");
    	scanf("%d", &input);
    }
    printf("Good!");

    return 0;
}
```

※ 교수님 코드

```c
int main() {

    const int secret_code = 337;
    int guess = 0;

    printf("Enter secret code : ");
    scanf("%d", &guess);

    while (guess != secret_code) {
    	printf("Enter secret code : ");
    	scanf("%d", &guess);
    }

    printf("Good!");

    return 0;
}
```

똑같은 코드를 while 이전에 무조건 한 번 해야하는 경우
중복된 코드를 줄이기 위해서 do while문을 사용

```c
int main() {

    const int secret_code = 337;
    int guess = 0;

    do {
    	printf("Enter secret code : ");
    	scanf("%d", &guess);
    }
    while (guess != secret_code);

    printf("Good!");

    return 0;
}
```

동일하게 작동하지만 훨씬 간결하다.
//

## 6.14 어떤 루프를 사용할까?

//

## 6.15 중첩된(nested) 루프들

ex 1)
원하는 첫글자부터 원하는 마지막 글자까지
원하는 횟수만큼 출력하기.
예를 들어
A B C D E F G H I J K 5줄 쓰는 것 구현하기.

※ 내 코드

```c
#include <stdio.h>

int main() {

    int i = 0;
    char c = 'A';
    int num = 5;

    for (i = 0; i < num; i++) {
    	for (c = 'A'; c <= 'K'; c++) {
    		printf("%c ", c);
    	}
    printf("\n");
    }

    return 0;
}
```

※ 교수님 코드

```c
#include <stdio.h>

#define NUM_ROWS 5
#define FIRST_CHAR 'A'
#define LAST_CHAR 'K'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r) // outer row loop
    {
    	for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
```

//
ex 2)
A
A B
A B C
...
이런 식으로
원하는 개수만큼 쌓이도록 출력

※ 내 코드

````c
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop
    int column = FIRST_CHAR;

    for (r = 0; r < NUM_ROWS; ++r) // outer row loop
    {
    	for (c = FIRST_CHAR; c <= column; ++c)
    		printf("%c ", c);
    	printf("\n");
    	column++;
    }

    return 0;
}

※ 교수님 코드
```c
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
````

outer loop의 변수가
inner loop의 변수에 연결돼 있는 경우가 상당히 많다.

//
ex 3)
A B C D E F G H I J K L
B C D E F G H I J K L
C D E F G H I J K L
...
L
처럼 점점 내려가기 구현

※ 내 코드

```c
#include <stdio.h>

#define NUM_ROWS 12
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
```

※ 교수님 코드

```c
#include <stdio.h>

#define NUM_ROWS 12
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
```

내가 위 쪽 예제 코드를 기반으로 만들어서 그런지
교수님 코드와 내 코드가 같다.

or

```c
#include <stdio.h>

#define FIRST_CHAR 'A'

int main() {

    const char last_char = 'L'; //TODO: use scanf()
    const int num_rows = last_char - FIRST_CHAR + 1;

    int r;// row loop
    int c;// character loop

    for (r = 0; r < num_rows; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + num_rows; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
```

이와 같이 const를 쓰는 식으로 만들어도 된다.
scanf를 사용해서 좀 더 interactive하게도 가능
//

## 6.16 배열(Array)과 런타임(Runtime) 에러

```c
#include <stdio.h>

#define NUM_DAYS 365

int main() {

    char my_chars[] = "Hello, World!"; // 자동으로 공간을 할당해줌

    int daily_temperature[NUM_DAYS];
    double stock_prices_history[NUM_DAYS];

    printf("%zd\n", sizeof(stock_prices_history));
    printf("%zd\n", sizeof(double) * NUM_DAYS);		// 8*365
    printf("%zd\n", sizeof(stock_prices_history[0]));

    return 0;
}
```

//

```c
#include <stdio.h>

#define NUM_DAYS 365

int main() {

    int my_numbers[5];

    my_numbers[0] = 1;	// [ ]안에 숫자 부르는 용어들 : subscripts, indices, offsets // [0]부터 시작하고 세는 것 아주 중요
    my_numbers[1] = 3;
    my_numbers[2] = 4;
    my_numbers[3] = 2;
    my_numbers[4] = 1024;

    //scanf("%d", &my_numbers[0]); // [0]가 &보다 연산자 우선순위가 높음
    scanf("%d", my_numbers); // offset이 0일 때는 &와 [0]떼고 사용 가능

    printf("%d\n", my_numbers[0]);
    printf("%d\n", my_numbers[1]);
    printf("%d\n", my_numbers[2]);
    printf("%d\n", my_numbers[3]);
    printf("%d\n", my_numbers[4]); // 나중에 for문 써서 한 줄로 바꿈

    return 0;
}
```

//
배열 사용 시 오류들

```c
int main() {

    int my_numbers[5];

    /* Runtime Error */
    my_numbers[5] = 123; // out of bound
    // 초보 때 가장 실수 주의해야하는 부분, 게다가 컴파일할 때 이 에러를 안 잡아줌 실행하면 그 때 runtime error가 뜸.

    my_numbers = 7; // compile error // []를 안 썼을 때 그냥 첫 주소의 역할을 하기 때문에 대입이 되지 않는다.(이 정도는 컴파일러가 잡아준다)

    printf("%d\n", my_numbers[5]); // out of bound

    return 0;
}
```

//

## 6.17 for 루프를 배열과 함께 사용하기

```c
#include <stdio.h>

#define SIZE 5

int main() {

    int my_arr[SIZE];

    // prepare for array data
    for (int i = 0; i < SIZE; ++i) // []안은 index
    	my_arr[i] = i; // my_arr[i] = i * i;도 가능

    // print array data
    for (int i = 0; i < SIZE; ++i)
    	printf("%d ", my_arr[i]);

    // for 1개에 대입, 출력을 다 처리하면 될 것 같지만, 데이터 사이즈가 매우 커지면 아닐 수 있다.(오히려 쪼개는 것이 장기적으로 더 효율적)

    //TODO: try debugger

    return 0;
}
```

//
ex)
숫자를 5개 입력받고
입력받은 숫자들의 합을
배열과 for 루프를 함께 사용해서
구현을 해보자.
(입력받는 개수도 define으로 바꿀 수 있으면 더 좋음)

※ 내 코드

```c
#include <stdio.h>

#define SIZE 5

int main() {
    int input[SIZE];
    int sum = 0;

    printf("Enter 5 numbers : ");

    for (int i = 0; i < SIZE; ++i) {
    	scanf("%d", &input[i]);
    	sum += input[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}
```

//

※ 교수님 코드

```c
#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE];
    int sum = 0;
    int i;

    printf("Enter %d numbers : ", SIZE);

    for (i = 0; i < SIZE; ++i)
    	scanf("%d", &numbers[i]); // &(numbers[i])

    for (i = 0; i < SIZE; ++i)
    	sum += numbers[i];

    /* for문을 쪼갠 이유는 최근의 컴퓨팅 기법에서는 멀티쓰레딩, GPU 발달되어있고,
    예전과 달리 데이터 양이 많기 때문에 for loop를 여러개 쪼개는 것이 효율적인 경우가 많다. */

    //TODO: average

    printf("Sum = %d\n", sum);

    return 0;
}
```

//

## 6.18 루프 안에서 함수의 반환값 사용하기

제곱 구하는 프로그램 같이 구현

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // 제곱 구해주는 프로그램
    // 3 4 입력하면
    // 3*3*3\*3 = 81 이런식으로 나오게

    int base, exp, i, result;
    scanf("%d %d", &base, &exp);

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    printf("Result = %d\n", result);

    return 0;
}
```

//

- 입력 반복하는 것도 구현

```c
int main() {
    // 제곱 구해주는 프로그램
    // 3 4 입력하면
    // 3*3*3\*3 = 81 이런식으로 나오게

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {
    	result = 1;
    	for (i = 0; i < exp; ++i)
    		result *= base;

    	printf("Result = %d\n", result);
    }

    return 0;
}
```

//
위 루프 안의 코드를 함수로 만들어서 빼고 다시 받아오자.

- 영역(scope)라는 개념 나온다.

main에서 정의된 변수들은함수에서 바로 쓸 수 없다.
함수에서 별도로 정의를 해 줘야 한다.

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp) {

    int i, result;

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    return result; // 계산 결과 반환
}
```

```c
int main() {

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {

    	result = compute_pow(base, exp); // 함수의 return 값이 변수에 대입되어 저장된다.

    	printf("Result = %d\n", result);
    }

    return 0;
}
```

//
함수의 prototype

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp); // prototype (이런 함수가 있다고 알려줌)

int main() {

    int base, exp, i, result;

    while (scanf("%d %d", &base, &exp) == 2) {

    	result = compute_pow(base, exp); // 함수의 return 값이 변수에 대입되어 저장된다.

    	printf("Result = %d\n", result);
    }

    return 0;
}

int compute_pow(int base, int exp) {

    int i, result;

    result = 1;
    for (i = 0; i < exp; ++i)
    	result *= base;

    return result; // 계산 결과 반환
}
```

//
