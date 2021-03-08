# TBC-12 Storage Classes, Linkage and Memory Management

## 12.1 메모리 레이아웃 훑어보기

### 프로그램이 시작될 때

    #include <stdio.h>

    void func() {
    	int i = 123;
    	printf("%lld\n", (long long)&i);
    }

    int main() {
    	const char* message = "Banana";
    	printf("Apple and %s", message);
    	printf("\n");

    	void (*f_ptr)() = func;	// address of a function

    	printf("%lld\n", (long long)&message);
    	printf("%lld\n", (long long)&f_ptr);
    	printf("%lld\n", (long long)message);
    	printf("%lld\n", (long long)f_ptr);
    	printf("%lld\n", (long long)main);

    	func();

    	return 0;
    }

---

### 프로그램 전체에서 계속 사용되는 변수들

#include <stdio.h>

int g_i = 123; // global variable
int g_j; // global variable

void func1() {
g_i++; // user g_i
}

void func2() {
g_i += 2; // uses g_i
}

int main() {

    int local = 1234;

    func1();
    func2();

    printf("%d", g_i);// uses g_i

    return 0;

}

---

### 프로그램의 일부에서 큰 메모리가 필요한 경우

#include <stdio.h>

#define MAX 1000

// 1. Use global variable
int g_arr[MAX];

int main() {

/_
Use g_arr
...
Do NOT use g_arr
...
Use g_arr
...
_/

    return 0;

}

---

#include <stdio.h>

#define MAX 1000

int main() {

    // 2. Use local in main()
    int l_arr[MAX] = { 0, };

/_
Use l_arr
...
Do NOT use l_arr
...
Use l_arr
...
_/

    return 0;

}

---

보다 효율적인 구조
#include <stdio.h>

#define MAX 1000

// 3. Use local in smaller function
void func() {

    int l_arr[MAX] = { 0, };

}

int main() {

/_
Call func()
...
Call func()
...
_/

    return 0;

}

---

필요한 메모리의 크기를 미리 알 수 없을 경우

#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 0;

    // n from files, internet, scanf, etc.

    char* arr = (char*)malloc(sizeof(char) * n);

    // ...

    free(arr);

    return 0;

}

---

## 12.2 객체(Object)와 식별자(Identifier), L-value와 R-value

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    /*
    	Object
    	- "An object is simply a block of memory that can store a value." (KNK p. 487)
    	- Object has more developed meaning in C++ and Object Oriented Programming (OOP)

    	Identifiers
    	- Names for variables, functions, macros, and other entitles. (KNK p. 25)
    */

    int var_name = 3;		// creates an object called 'var_name'.

    int* pt = &var_name;	// pt is an identifier.
    *pt = 1;				// *pt is not an identifier. *pt designates an object.

    int arr[100];	// arr is an identifier. Is arr an object?(No, arr is address of first element of array)
    arr[0] = 7;		// arr[0] is an object.(Identifier는 아니지면 expression을 통해 메모리에 접근 가능하므로)
    // Identifier와 Object가 다른 개념으로 사용될 수 있다.


    /*
    	lvalue is an expression 'referring' to an object. (K&R p.197)
    	(refer을 또 다른 이름처럼 사용한다고 이해)

    	L-value : left side of an assignment
    	R-value : right side, variable, constant, expressions (KNK p. 67)
    */

    var_name = 3;	// modifiable lvalue
    // 메모리의 공간을 referring해준다.(변수 이름이 메모리 공간x)
    int temp = var_name; // var_name에 있는 '값'을 복사해서 대입
    temp = 1 + 2;
    // L-value는 object다. 변수명이 R-value로 가면 가진 값만 가져오는 식이다

    pt = &var_name;		// 포인터에 변수의 주소값을 대입
    int* ptr = arr;		// 주소값 대입
    *pt = 7;	// *pt is not an identifier but an modifiable lvalue expression.

    int* ptr2 = arr + 2 * var_name; // address rvalue
    *(arr + 2 * var_name) = 456;	// lvalue expression(위의 형태에 *을 앞에 붙여줘서 rvalue expression(modifiable) 처럼 사용 가능

    const char* str = "Constant string";		// str is a modifiable lvalue.
    str = "Second string";	// "Constant string" = "Second String"	// impossible
    //str[0] = 'A'; // Error(위에 const 떼도 error 생김)
    //puts(str);

    char str2[] = "String in an array";
    /*
    	Array로서 메모리 공간을 따로 할당 받고
    	str2라는 identifier가 문자열이 저장되기 충분한 메모리 공간에 대한 식별자 역할을 한다.
    	그러므로 위에 있는 str과 작동방식이 다르다. 차이점을 알고있자.
    */
    str2[0] = 'A';	// OK
    //puts(str2);

    /*
    	Identifiers have scope.(영역)	// Identifier는 Object의 이름 역할을 하는데 이름이 절대적인건 아니다.(이름이 없을 수도 있다.)
    	Objects have storage duration.(저장공간의 지속기간)(메모리에 언제부터 언제까지 위치하는지)
    	Variables and functions have one of the following linkages(연결):
    		external linkage, internal linkage, or no linkage.
    	다음 강의에 설명
    */

    return 0;

}

---

## 12.3 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(Duration)

### FileScope

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Variable scopes (visibility) - block, function, function prototype, file.
_/

int g_i = 123; // global variable
int g_j; // global variable
// file 영역은 모든 함수 바깥에 선언되면 됨(file scope를 갖는다)

void func1() {
g_i++; // uses g_i
}

void func2() {
g_i += 2; // uses g_i

    //local = 456;	// Error

}

int main() {

    int local = 1234;

    func1();
    func2();

    printf("%d\n", g_i);// uses g_i
    printf("%d\n", g_j);// Not initialized?
    // 초기화하지 않은 전역 변수는 BSS segment에 저장되는데 여기에 저장된 값들은 프로그램이 시작될 때 0으로 초기화 된다.
    printf("%d\n", local);

    return 0;

}

---

### Scope

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Variable scopes (visibility) - block, function, function prototype, file.
_/

void f1(int hello, double world); // to the end of the prototype declaration
//void vla-param(int n, int m, double ar[n][m]); // gcc only

double func_block(double d) {

    double p = 0.0;

    int i;
    for (i = 0; i < 10; i++)	//for (int i = 0; i < 10; i++) // C99
    {


    	double q = d * i;
    	p *= q;

    	if (i == 5)
    		goto hello;	// goto문 거의 사용x
    }

hello:
printf("Hello, World");

    return 0;

}

int main() {

    func_block(1.0);

    return 0;

}

void f1(int hello, double world) {
// prototype과 변수명을 맞춰주는 것이 유지관리하기 좋다

}

/_
void vla_param(int n, int m, double ar[n][m]) {
}
_/

---

### Linkage

파일이 여러개인 경우, 따로 컴파일하기 때문에 서로의 생성된 object 파일에 뭐가 있는지 모른다.
그래서 object 파일간을 연결해주는 것이 linker다.

#### Linkage.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/\*
Linkage

    Variables with block scope, function scope, or function prototype
    - No linkage

    File scope variables
    - External or internal linkage

\*/

// translation unit

int el; // file scope with external linkage (global variable)
// file scope에 있는 변수는 마치 프로그램 전체에서 사용할 수 있는 것 처럼 사용할 수 있어서 전역변수라고 부른다.
static int il; // file scope with internal linkage
// static, 이 변수의 범위가 현재 scope로 제한하는 의미

void testLinkage(); // 다른 파일에 있는 함수를 사용하기 위해 prototype 선언(linking)

int main() {

    el = 1024;

    testLinkage();

    printf("%d\n", el);

    return 0;

}

#### Second.c

#include <stdio.h>

extern int el;
//extern int il;
/_
extern 이라는 키워드를 사용하면
어딘가 다른데 선언이 되어있는 변수를 끌어올 수 있다.
_/

void testLinkage() {

    printf("DoSomething called\n");
    printf("%d\n", el);
    //printf("%d\n", il);
    //printf("%d", dodgers);

    el++;

}

---

### Duration

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/\*
Storage duration: - static storage duration // 시작할 때 부터 끝날 때 까지 메모리 자리 고정적으로 // 여기서 말하는 static은 '정적'이라는 의미 그 자체
(Note: 'static' keyword indicates the linkage type, not the storage duration) - automatic storage duration - allocated storage duration - thread storage duration

    duration은 메모리의 지속기간을 의미

\*/

void count() {

    int ct = 0;
    printf("count = %d\n", ct);
    ct++;

}

void static_count() {

    static int ct = 0;
    /*
    	앞에 static이 붙으면 프로그램이 시작될 때 메모리에 들어오고
    	끝날때 까지 메모리에 유지된다.(함수가 끝나도 없어지지 않음)
    	(다시 선언x)
    */
    printf("static count = %d\n", ct);
    ct++;

}

int main() {

    count();
    count();
    static_count();
    static_count();

    return 0;

}

---

## 12.4 저장 공간의 다섯 가지 분류(Five Storage Classes)

---

## 12.5 자동 변수(Automatic Variables)

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Automatic storage class - Automatic storage duration, block scope, no linkage - Any variable declared in a block or function header
_/

void func(int k);

int main() // Note: main() is a function.
{
auto int a; // keyword auto : a storage-class specifier(거의 사용x, C++에서는 auto keyword가 완전 다른 뜻을 가진다)
a = 1024;
//printf("%d\n", a); // what happens if uninitialized?
//auto int b = a _ 3; // what happens if uninitialized?
/_
자동변수는 빈번하게 사용되기 때문에 초기화를 해줘야한다.
컴파일러가 자동변수는 초기화 해주지 않음
(자동변수를 전역변수와 같이 매번 컴파일러가 0으로 초기화해주면 효율이 좋지 않으므로)
\*/

    int i = 1;
    int j = 2;

    printf("i %lld\n", (long long)&i);

    {
    	// 영역이 바뀌면 똑같은 identifier 가능
    	int i = 3;	// name hiding(더 큰 영역에서 선언이 된 identifier는 hiding된다.)
    	printf("i %lld\n", (long long)&i);
    	// C언어에서 identifier이 같을 경우 가장 안 쪽 영역에 있는 것을 선택

    	// j is visible here
    	printf("j = %d\n", j);	// 더 큰 영역에 있는 j 그대로 사용

    	int ii = 123;
    }
    // ii is not visible here

    printf("i %lld\n", (long long)&i);	// which i?

    for (int m = 1; m < 2; m++)
    	printf("m %lld\n", (long long)&m);		// no block?
    // block이 없어도 m을 바로 위까지만 사용 가능

    func(5);	// cannot see any of the variabled defined so far.

    for (int m = 3; m < 4; m++) {
    	printf("m %lld\n", (long long)&m);		// block?
    }
    // block이 끝날 때 까지 m 사용 가능

    return 0;

}

void func(int k) {

    int i = k * 2;
    // do something with i and k
    printf("i %lld\n", (long long)&i);

}
/_
이 function이 호출되면 stack frame이 자체가 바뀌어 버리므로
지금 까지 써온 변수들 쓸 수 없다.
(main 함수 안에 있는 i, j에 접근할 수 없다)
_/

---

## 12.6 레지스터(Register) 변수

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void temp(register int r) {
// do something with r
}

int main() {

    register int r;
    // register keyword를 붙이면 컴파일러에게 가급적 이 변수를 register에 위치 해달라는 의미
    r = 123;
    // 임베디드 분야 등에 이걸 사용하는 경우가 있다.

    //printf("%p\n", &r);
    int* ptr = &r;	// register keyword 사용시 address of operator를 사용할 수 없다.
    // 이태껏 포인터나 주소를 사용할 때는 주 기억장치를 위주로 사용했기 때문


    return 0;

}

---

## 12.7 블록 영역의 정적(Static) 변수

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count() {

    int ct = 0;	// stack에 저장됨
    printf("count = %d %lld\n", ct, (long long)&ct);
    ct++;

    //TODO: return &ct;

}

void static_count() {

    static int ct = 0;	// initialized only once!
    // stack에 저장x, 데이터나 BSS같은 곳에 저장(프로그램 시작부터 끝까지 유지되는 곳(static))
    printf("static count = %d %lld\n", ct, (long long)&ct);
    ct++;

    //TODO: return &ct;

}

/\*

- TODO: return &ct;
- 포인터를 반환하는 경우도 꽤 있다.
- ex) 하드웨어 관련 api 사용, 게임 엔진 등

int\* count() {

    int ct = 0;
    printf("count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;
    // 이런 방식 매우 안 좋음, 지역변수의 포인터를 반환하는데 지역변수는 함수를 나가면 사라지기 때문

}

int\* static_count() {

    static int ct = 0;	// initialized only once!
    printf("static count = %d %lld\n", ct, (long long)&ct);
    ct++;

    return &ct;
    // 메모리에 고정된 주소를 가지고 있기 때문에 써도 된다.(좋다는 뜻은 아님, 이럴바엔 차라리 전역변수 사용하자)

}

\*/

//int func(static int i) { // Warning (Error in GCC)
//
//}
/\*
함수의 parameter에 static 넣는 경우,
vs에서 i가 bad storage갖는다는 warning이 뜨고
gcc로 컴파일하면 error가 나서 컴파일 불가

    paremeter의 변수는 함수가 실행이 될 때 메모리의 배정을 받는데
    static과는 맞지 않으므로

\*/

void counter_caller() {
count();
}

void static_counter_caller() {

    static_count();

}

int main() {

    count();
    count();
    counter_caller();	// stack 안에서 count() 호출

    static_count();
    static_count();
    static_counter_caller();

    return 0;

}

---

## 12.8 정적 변수의 외부 연결(Static Variables with External Linkage)

### main.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Static variable with external linkage - File scope, external linkage, static storage duration - External storage class - External variables
_/

int g*int = 0; // 컴파일러가 전역변수 알아서 초기화 해주지만 가급적이면 직접 초기화 하자
//int g_int = 7;
double g_arr[1000] = { 0.0, };
// 전역변수인 경우 global의 약자 g*를 앞에 잘 붙인다.

/_
Initializing External Variables
_/

int x = 5; // ok, constant expression
int y = 1 + 2; // ok, constant expression
size_t z = sizeof(int); // ok, sizeof is a constant expression
//int x2 = 2 \* x; // not ok, x is a variable(변수가 들어가는 expression으로 초기화는 불가)

void fun() {

    printf("g_int in fun() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능
    g_int += 10;

}

void fun_sec(); // second.c에 있는 함수 선언만 해주면 외부 연결

int main() {
/_
defining declaration vs referencing declaration
_/

    extern int g_int;			// Optional		// scope 바깥에 이 변수있으니까 연결(file scope에 있다는 걸 명확히)
    //extern int g_int = 1024;	// Error in block scope

    //int g_int = 123;			// hides global g_int

    extern double g_arr[];		// optional, size is not necessary
    // size를 위에서 이미 결정

    printf("g_int in main() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능
    g_int += 1;

    fun();
    fun_sec();

    return 0;

}

### second.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf() in second.c

extern int g_int;
// file scope에서는 초기화 가능(단, 처음 전역변수 선언 시 내가 초기화하지 않아야 함)(file scope중 한 곳에서만 초기화 가능하다는 뜻)
// 가급적 extern이 붙은 곳에서는 초기화 안 하는 것이 좋다.

void temp() {

    // extern int g_int;	// 여기서 초기화는 불가(block scope에서 초기화는 불가능)(BSS data segment를 다뤄야하므로 적절치 않음)

    g_int += 1000;

}

void fun_sec() {

    temp();

    extern int g_int;

    g_int += 7;
    printf("g_int in fun_sec() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능

}

---

## 12.9 정적 변수의 내부 연결(Static Variables with Internal Linkage)

### main.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Static variable with internal linkage - File scope, external linkage, static storage duration - Internal storage class
_/

static int g_int = 123; // defining declaration
/\*
전역변수 사용하는 경우에 복잡해져 유지보수가 힘든경우가 있다.

    그래서 전역변수를 file scope 내에서만 사용할 수 있도록 제한하고 싶은 경우가 있다.
    그 때 static 사용(이 scope 안으로 강제로 고정)

\*/

void fun();
void fun_second();
void fun_third();

int main() {

    fun();
    fun_second();
    fun_third();

    return 0;

}

void fun() {

    extern int g_int;	// optional

    g_int += 1;
    printf("g_int in fun() %d %p", g_int, &g_int);

}

### second.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf() in second.c

extern int g_int; // referencing declaration
// main()에서 static으로 막았기 때문에 접근 불가

void fun_second(void) {

    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);

}

### third.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf() in third.c

extern int g_int; // referencing declaration
// main()에서 static으로 막았기 때문에 접근 불가

void fun_second(void) {

    g_int += 1;
    printf("g_int in fun_third() %d %p\n", g_int, &g_int);

}

---

## 12.10 변수의 저장 공간(Storage Classes) 분류 요약 정리

---

## 12.11 함수의 저장 공간 분류

### main.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/_
Storage Classes and Functions - Functions external (by default) or static - A function declaration is assumed to be extern
_/

int g_int = 123; // defining declaration
// TODO: try static

void fun();
void fun_second();
// 함수 prototype에 모두 extern keyword가 있어야 하지만 당연한 것이므로 생략 가능

int main() {
fun();
fun_second();

    return 0;

}

void fun() {

    extern int g_int;	// optional

    g_int += 1;
    printf("g_int in fun() %d %p\n", g_int, &g_int);

}

### second.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf() in second.c

extern int g_int; // referencing declaration

static void tool(void) {
// 다른 파일에서 직접적으로 사용 막기 위해 static keyword 이용
}

//static void fun_second(); // prototype에 static붙여도 linking error 뜸

void fun_second(void) {

    tool();	// fun_second는 외부에서 사용 가능, tool()만 파일 내에서 사용 가능

    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);

}

/\*
static void fun_second(void) {

    g_int += 1;
    printf("g_int in fun_second() %d %p\n", g_int, &g_int);

}
// 이 경우에 linking error 발생
\*/

---

## 12.12 난수 생성기 모듈 만들기 예제

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // srand() // random number를 생성할 때 필요한 함수들이 포함됨
#include <time.h> // time()

int main() {

    /*
    	rand()
    	- 0 to RAND_MAX (typically INT_MAX)
    	- defined in stdlib.h.

    	C언어에서 난수 생성시 사용(사람이 봤을 때 무작위로 보임)
    	컴퓨터는 진정한 난수를 만드는 능력이 없다.
    */

    //srand(3);	// random seed	// seed값이 바뀌면 나오는 rand() 값이 바뀜
    srand((unsigned int)time(0));	// time을 이용해서 seed값을 예측하기 힘들게 만든다
    for (int i = 0; i < 10; ++i) {
    	printf("%d\n", rand());
    	//printf("%d\n", rand() % 6 + 1);
    }

    return 0;

}

---

유사난수(이것도 동일하게 난수 나옴)
unsigned int next = 1; // seed값

    for (int i = 0; i < 10; ++i) {
    	next = next * 1103515245 + 1234;
    	// 난수를 만드는 어떤 규칙이 있다. 흔히 '유사 난수'(pseudo random number)로 부르기도 함
    	next = (unsigned int)(next / 65536) % 32768;
    	printf("%d\n", (int)next);
    }

---

time()을 이용해서 값이 계속 바뀌게 만들기

    unsigned int next = (unsigned int)time(0);	// seed값

    for (int i = 0; i < 10; ++i) {
    	next = next * 1103515245 + 1234;
    	// 난수를 만드는 어떤 규칙이 있다. 흔히 '유사 난수'(pseudo random number)로 부르기도 함
    	next = (unsigned int)(next / 65536) % 32768;
    	printf("%d\n", (int)next);
    }

---

문제: 방금 본 코드를 확용해서 마치 rand() 함수와 같은 기능을 똑같이 만들어보기
(알고리즘이 다르므로 값이 다르게 나와도 됨)
(단, 유사난수 예제와 같은 값이 나오게)

※ 내 코드(대참사)
my_rand.h에 prototype 선언 정확히 어떻게 하지?
my_rand.c에서 void my_srand의 지역변수를 어떻게 int my_rand()에 넣을까?(parameter 없이)

### my_rand.h

#pragma once
// include를 여러번해도 중복이 되지 않게 막아준다.

// some prototypes
int my_rand();
void my_srand(unsigned int); // 함수명에 초록줄 뜨는데 parameter가 안 맞아서 그런듯

### my_rand.c

void my_srand(static next) {

    next = next * 1103515245 + 1234;
    next = (unsigned int)(next / 65536) % 32768;

    my_rand();

}

int my_rand() {

    return next;

}

### main.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "my_rand.h"

int main() {

    my_srand((unsigned int)time(0));

    for (int i = 0; i < 10; ++i) {

    	printf("%d\n", my_rand() % 6 + 1);	// 주사위 굴리는 느낌
    }

    return 0;

}

※ 교수님 코드
이 연습문제에서 주의깊게 봐야할 것은 모듈형태로 쪼개는 것이다.⭐

### my_rand.h

#pragma once

int my_rand();
void my_srand(unsigned int seed);

### my_rand.c

static unsigned int next = 1; //⭐
// static을 붙이면 외부에서 next 변수에 접근 불가

int my_rand() {

    next = next * 1103515245 + 1234;
    next = (unsigned int)(next / 65536) % 32768;
    // 앞에 알고리즘 그대로 사용

    return (int)next;

}

void my_srand(unsigned int seed) {

    next = seed;

}

### main.c

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "my_rand.h"

int main() {

    my_srand((unsigned int)time(0));

    for (int i = 0; i < 10; ++i) {

    	printf("%d\n", my_rand() % 6 + 1);	// 주사위 굴리는 느낌
    }

    return 0;

}

---

#12.13 메모리 동적 할당(Dynamic Storage Allocation)

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()

int main() {

    float x;
    char str[] = "Dancing with a Star";

    int arr[100];

    /*
    	(malloc: memory allocation 메모리 할당)
    	malloc() returns a void type pointer.(순수한 주소)
    	void* : generic pointer

    	free() deallocates the memory
    */

    double* ptr = NULL;

    // 쓰는 쪽(ptr)에서 double로 casting
    ptr = (double*)malloc(30 * sizeof(double));	// double 30개 저장용, 메모리 공간의 첫번째 주소를 return해준다.(pointer)
    //size_t;	// malloc()함수 parameter 확인용	// 몇 byte 메모리 요청할지 size만 적어주면 된다.

    if (ptr == NULL)	// malloc()함수는 줄 메모리 공간이 없을 때 NULL을 return함
    {

    	puts("Memory allocation failed");

    	/*
    		exit(EXIT_FAILURE) is similar to return 1 IN main().
    		exit(EXIT_SUCCESS) is similar to return 0 IN main().

    		exit()함수는 어떠한 상황에서도 강제로 프로그램 종료 가능
    	*/

    	exit(EXIT_FAILURE);
    	/*
    		대부분의 경우 메모리 할당이 안 된다는 의미는
    		아주 심각해서 프로그램을 진행할 수 없는 경우이므로
    		exit을 이용해서 강제로 종료(exit 의외로 많이 사용, debugging 할 때 많이 쓴다)
    		(메모리 할당 안 되는 경우 잘 없다. 만약 있다면 메모리를 너무 크게 요청한 경우다.)
    		(프로그램 여러개 있어서 연속된 공간을 줄 수 없을 때도 메모리 할당 안 된다.)

    		꼭 나가야 할 필욘 없다.

    		다만, 웹서버 등 어떠한 경우에도 계속 돌아가야한다면
    		오류처리라는 문법을 이용해서 다른 대안 찾음(다른 언어에서 공부)
    	*/
    }
    /*
    	동적할당 받은 메모리와 포인터를 동일시하지 말자
    	automatic은 scope 밖으로 가면 잃어버리므로
    	(주소를 적은 쪽지라고 생각)
    	(주소는 있지만 쪽지를 잃어버려서 찾을 수 없는 경우)

    	초보때 포인터를 잃어버렸는데도
    	동적할당을 반복하다가 heap이 꽉차면 문제가 생기는 경우가 있다.
    */

    printf("Before free %p\n", ptr);

    free(ptr);	// no action occurs when ptr is NULL

    printf("After free %p\n", ptr);
    /*
    	free이후에도 ptr의 값(주소)은 이전과 같은데
    	비유는 하면 친구집 주소를 쪽지로 적어서 가지고 있을때
    	친구가 이사를 해도 쪽지에 적힌 주소는 동일한 것으로 보면 된다.

    	그러므로 free 이후에 동적할당 메모리에 대한 포인터 변수는
    	NULL값으로 바꾸는 것이 안전하고 편하다.(optional)
    */
    ptr = NULL;	// optional

    /* Dynamic Allocated Array */
    // 동적할당 메모리는 배열처럼 사용 가능

    int n = 5;
    // n의 값은 runtime에 결정되어도 된다.
    ptr = (double*)malloc(n * sizeof(double));

    if (ptr != NULL)	// if(!ptr)
    {
    	for (int i = 0; i < n; ++i)
    		printf("%f ", ptr[i]);
    	printf("\n");
    	// 메모리를 할당 만 받고 초기화를 하지 않았기 때문에 쓰레기 값이 들어있다.

    	for (int i = 0; i < n; ++i)
    		* (ptr + i) = (double)i;	// 포인터 연산을 이용해 배열처럼 사용

    	for (int i = 0; i < n; ++i)
    		printf("%f ", ptr[i]);
    	printf("\n");
    }
    // 동적할당 메모리는 (malloc()함수로 받아왔을 때는) 초기화를 하지 않는다는 것을 기억

    free(ptr);
    ptr = NULL;

    /*
    	Comparision to VLA (가변길이배열과 비교)

    	VLA
    	- not supported by VS compilers.(gcc에서는 지원)(대부분의 프로그램은 VLA보단 동적할당 지원)
    	- automatic duration, cannot be resized	(동적할당은 다른 size의 메모리 다시 받아올 수 있음)
    	- limited by stack size (when compiler places VLA in stack segment)
    */

    return 0;

}

---

## 12.14 메모리 누수(Leak)와 free()의 중요성

(비주얼 스튜디오 진단 도구(Diagnostic Tool) 사용법)

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Dummy Output\n");	// debug point 찍기 위해

    /*
    	heap 공간을 더 크게 사용하려면 x64를 사용
    */

    {
    	int n = 100000000;
    	int* ptr = (int*)malloc(n * sizeof(int));
    	// ptr 자체는 block 안에서만 활성화(automatic)

    	if (!ptr)// if(ptr == NULL)
    	{
    		printf("Malloc() failed\n");
    		exit(EXIT_FAILURE);
    	}

    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;
    }

    // what happens ?

    // 메모리 자체는 살아있지만 ptr을 잃어버렸기 때문에 메모리에 접근 불가

    printf("Dummy Output\n");

    return 0;

}

---

block 나가기 전에 free()를 이용해서 메모리 없애기

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Dummy Output\n");	// debug point 찍기 위해

    /*
    	heap 공간을 더 크게 사용하려면 x64를 사용
    */

    {
    	int n = 100000000;
    	int* ptr = (int*)malloc(n * sizeof(int));
    	// ptr 자체는 block 안에서만 활성화(automatic)

    	if (!ptr)// if(ptr == NULL)
    	{
    		printf("Malloc() failed\n");
    		exit(EXIT_FAILURE);
    	}

    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;

    	free(ptr);
    	//ptr = NULL;
    }

    // what happens ?

    // free() 이용해서 heap에 있는 메모리 반납함

    printf("Dummy Output\n");

    return 0;

}

---

동적할당의 이러한 특성을 이용하기

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Dummy Output\n");	// debug point 찍기 위해

    // 동적할당 특성을 이용
    int* ptr_backup = NULL;
    {
    	int n = 100000000;
    	int* ptr = (int*)malloc(n * sizeof(int));
    	// ptr 자체는 block 안에서만 활성화(automatic)

    	if (!ptr)// if(ptr == NULL)
    	{
    		printf("Malloc() failed\n");
    		exit(EXIT_FAILURE);
    	}

    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;

    	printf("%d, %d\n", ptr[0], ptr[1]);

    	ptr_backup = ptr;
    	// 주소를 옮겨 적으면 block 밖을 나가도 메모리 데이터 그대로 사용 가능

    	//free(ptr);	// free()하면 runtime error 뜸
    	//ptr = NULL;
    }

    // what happens ?

    printf("%d, %d\n", ptr_backup[0], ptr_backup[1]);
    printf("Dummy Output\n");

    return 0;

}

---

메모리 누수(free하지 않는 경우에 계속 할당 만 받으면 어떻게 되는가)
(컴터 문제 생길 수 있으니 debug 조심히)

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Dummy Output\n");

    for(int k = 0; k < 1000000; ++k)
    {
    	int n = 100000000;
    	int* ptr = (int*)malloc(n * sizeof(int));

    	if (!ptr)// if(ptr == NULL)
    	{
    		printf("Malloc() failed\n");
    		exit(EXIT_FAILURE);
    	}

    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;

    	printf("%d, %d\n", ptr[0], ptr[1]);

    	//free(ptr);
    	//ptr = NULL;
    }

    // what happens ?

    printf("Dummy Output\n");

    return 0;

}

메모리 누수
Process Memory가 계속 증가한다.
컴퓨터 한도에 도달하면 문제 생김

---

위에서 free(ptr);를 추가하면 메모리 누수x

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Dummy Output\n");

    for(int k = 0; k < 1000000; ++k)
    {
    	int n = 100000000;
    	int* ptr = (int*)malloc(n * sizeof(int));

    	if (!ptr)// if(ptr == NULL)
    	{
    		printf("Malloc() failed\n");
    		exit(EXIT_FAILURE);
    	}

    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;

    	printf("%d, %d\n", ptr[0], ptr[1]);

    	free(ptr);
    	//ptr = NULL;
    }

    // what happens ?

    printf("Dummy Output\n");

    return 0;

}

할당받고 반납하고를 계속 반복하기 때문에 메모리 누수x

---

x86으로 돌리면 금방 프로그램 down된다.
x86일 때 컴퓨터가 가진 heap 메모리 전부 사용하는 것이 아니다.(한도가 낮다)

---

## 12.15 동적 할당 메모리를 배열처럼 사용하기

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    /*
    	One variable
    	동적 할당 메모리를 변수 하나처럼 사용
    	마치 어떤 변수에 대한 포인터를 알고 있는 것과 비슷
    */

    int* ptr = NULL;

    ptr = (int*)malloc(sizeof(int) * 1);
    if (!ptr) exit(1);

    *ptr = 1024 * 3;	// indirection
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;

}

---

1차원 배열
/_
1D array
_/

    int n = 3;
    int * ptr = (int*)malloc(sizeof(int) * n);
    if (!ptr) exit(1);

    ptr[0] = 123;	// 배열과 유사하게 사용 가능
    *(ptr + 1) = 456;	// 포인터 연산을 이용해서 값을 읽거나 저장 가능
    *(ptr + 2) = 789;
    // (int*)로 형변환을 했기 때문에 이런식으로 포인터 연산 가능

    free(ptr);
    ptr = NULL;

    /*
    	x64에서 heap 메모리가 매우 크기 때문에
    	어마어마하게 큰 메모리 다룰 때는
    	배열보다 동적할당 메모리 사용
    */

---

2차원 배열

    /*
    	2D array
    */

    int row = 3, col = 2;
    int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);	// constant 밖에 못 쓰면 동적 할당의 의미 퇴색
    //int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);	// VLA(col 변수로 하려면 compiler가 VLA 지원해줘야함)
    if (!ptr2d) exit(1);

    for (int r = 0; r < row; r++)
    	for (int c = 0; c < col; c++)
    		ptr2d[r][c] = c + col * r;

    for (int r = 0; r < row; r++) {

    	for (int c = 0; c < col; c++)
    		printf("%d ", ptr2d[r][c]);
    	printf("\n");
    }

    /*
    	실용적인 측면

    	Using 1D arrays as 2D arrays

    	row = 3, col = 2

    	(r, c)

    	2D
    	(0, 0) (0, 1)
    	(1, 0) (1, 1)
    	(2, 0) (2, 1)

    	1D(한 줄로 나열하면)
    	(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1)
    	0	   1	  2		 3	    4	   5	   = c + col * r
    	(밑에 숫자는 index)

    */

    int row = 3, col = 2;
    int* ptr = (int*)malloc(row * col * sizeof(int));
    if (!ptr) exit(1);

    for (int r = 0; r < row; r++)
    	for (int c = 0; c < col; c++)
    		ptr[c + col * r] = c + col * r;

    for (int r = 0; r < row; r++) {
    	for (int c = 0; c < col; c++)
    		printf("%d ", *(ptr + c + col * r));
    	printf("\n");
    }

---

다차원 배열

    /*
    	실용적인 측면(결국 우리가 사용하는 컴퓨터 메모리의 구조는 1차원이므로)

    	Using 1D arrays as 3D arrays

    	row = 3, col = 2, depth = 2

    	(r, c, d)

    	3D
    	-------------------
    	(0, 0, 0) (0, 1, 0)
    	(1, 0, 0) (1, 1, 0)
    	(2, 0, 0) (2, 1, 0)
    	-------------------
    	(0, 0, 1) (0, 1, 1)
    	(1, 0, 1) (1, 1, 1)
    	(2, 0, 1) (2, 1, 1)
    	-------------------

    	1D
    	(0, 0, 0) (0, 1, 0) (1, 0, 0) (1, 1, 0) (2, 0, 0) (2, 1, 0) (0, 0, 1) (0, 1, 1) (1, 0, 1) (1, 1, 1) (2, 0, 1) (2, 1, 1)
    	0		  1			2		  3			4		  5			6		  7			8		  9			10		  11
    	= c + col * r + (col*row) * d
    	= 1 + 2 * 1 + (3*2) * 1 = 1 + 2 + 6 = 9
    	(3차원 idexing을 1차원으로 바꾸기)
    	(4, 5차원 등등 다 가능)

    	if 4차원(4차원 부터는 그림으로 설명하기 어렵다. 머리 속으로 추상적으로 상상해야함)
    	row, col, depth, height
    	(r, c, d, h)
    	index = c + col * r + (col*row) * d + (row*col*depth) * h
    */

    int row = 3, col = 2, depth = 2;
    int* ptr = (int*)malloc(row * col * depth * sizeof(int));
    if (!ptr) exit(1);

    for (int d = 0; d < depth; d++)
    	for (int r = 0; r < row; r++)
    		for (int c = 0; c < col; c++)
    			ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;

    /*
    * 매번 위 처럼 코딩하기 쉽지 않으므로 함수를 만들어서 쓰자

    	int idx2(int c, int r)
    	{
    		return c + col * r;
    	}

    	int idx3(int c, int r, int d)
    	{
    		static const int cr = col * row;	// col * row하는 시간 아까우면(연산 시간 줄이고 싶으면) static 사용
    		return c + col * r + cr * d;
    	}
    */

    // 출력
    for (int d = 0; d < depth; d++) {
    	for (int r = 0; r < row; r++) {
    		for (int c = 0; c < col; c++)
    			printf("%d ", *(ptr + c + col * r + (col * row) * d));
    		printf("\n");
    	}
    	printf("\n");
    }

---

## 12.16 calloc(), realloc()

#define \_CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = 10;

    int* ptr = NULL;

    //ptr = (int*)malloc(sizeof(int) * n);
    ptr = (int*)calloc(n, sizeof(int));	// contiguous allocation
    // 연속된 n개의 int 메모리 받아라(parameter가 count, size 2개)
    if (!ptr)
    	exit(1);

    // calloc()은 전부 초기화를 해준다.
    for (int i = 0; i < n; ++i)
    	printf("%d ", ptr[i]);
    printf("\n");

    /*
    	realloc() KNK p. 422
    	- doesn't initialize the bytes added
    	- returns NULL if can't enlarge the memory block
    	- If first argument is NULL, it behaves like malloc()
    	- if second argument is 0, it frees the memory block.

    	이전에 동적할당으로 메모리를 받았는데
    	내가 필요로 하는 메모리의 사이즈가 달라져서
    	다시 할당을 받고 싶을 때 사용하는 함수
    	re-allocation(재할당)
    */

    for (int i = 0; i < n; ++i)
    	ptr[i] = i + 1;

    n = 20;	// n이 10에서 20으로 바뀜

    int* ptr2 = NULL;
    ptr2 = (int*)realloc(ptr, n * sizeof(int));	// 늘어난 공간으로 재할당 요청
    // 앞에 ptr은 이미 동적할당으로 가지고 있는 메모리 블럭에 대한 포인터

    //ptr = (int*)realloc(ptr, n * sizeof(int));
    // 실무에선 이렇게 원래 메모리가 늘어나는 것 처럼 써도 된다.

    printf("%p %p\n", ptr, ptr2);

    printf("%d\n", ptr[0]);

    if (!ptr2)
    	exit(1);
    else
    	ptr = NULL;	// 원래 포인터 사용하지 않도록 막아줌(ptr2 사용시에)

    for (int i = 0; i < n; ++i)
    	printf("%d ", ptr2[i]);		// copies data
    printf("\n");
    // 새로 추가가 된 값은 초기화 되지 않는다.(쓰레기 값 출력)

    free(ptr2);

    return 0;

}

---

## 12.17 동적 할당 메모리와 저장 공간 분류

#include <stdio.h>
#include <stdlib.h>

int g = 123;

void func() {
int i = 123;
printf("Local variable \t%lld\n", (long long)& i);
}

int main() {

    const char* message = "Banana";

    void (*f_ptr)() = func;	// address of a function

    printf("Local pointer	 \t%lld\n", (long long)&message);
    printf("Function pointer \t%lld\n", (long long)& f_ptr);
    printf("String data	     \t%lld\n", (long long)message);
    printf("Function address \t%lld\n", (long long)f_ptr);
    printf("Function address \t%lld\n", (long long)main);
    printf("Global variable	 \t%lld\n", (long long)& g);

    func();

    int* ptr = (int*)malloc(100 * sizeof(int));
    if (!ptr) exit(EXIT_FAILURE);

    printf("Allocated memory \t%lld\n", (long long)ptr);

    free(ptr);

    return 0;

}

---

## 12.18 자료형 한정자들(Type Qualifiers)

const, volatile, restrict

#define \_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy
#include "constants.h"

//const double gravity = 9.8;
//const double PI = 3.141592;

int main() {

    /*
    	Qualified types
    	const, volatile, restrict, _Atomic
    */

    /*
    	const
    */

    // C99 ideompotent	// 여러개 써도 된다는 뜻
    const const const int n = 6;	// const int n = 6;

    // type define
    typedef const int zip;	// const int를 zip이라는 type으로 내가 정의
    const zip q = 8;	// const const int zip
    // 이런 경우 대비해서 ideompotent

    //const int i;	// Not initialized!
    //i = 12;	// Error
    //printf("%d\n", i);	// Error

    const int j = 123;
    const int arr[] = { 1, 2, 3 };

    float f1 = 3.14f, f2 = 1.2f;

    const float* pf1 = &f1;
    //*pf1 = 5.0f;	// Error
    pf1 = &f2;		// Allowed
    // pf1이라는 포인터 변수 자체는 다른 값을 가질 수 있다

    float* const pf2 = &f1;
    *pf2 = 6.0f;	// Allowed
    //pf2 = &f2;	// Error

    const float* const pf3 = &f1;
    //*pf3 = 7.0f;	// Error
    //pf3 = &pf2;	// Error

    /*
    	Global constants

    	위에
    	const double gravity = 9.8;
    	const double PI = 3.141592;

    	constant를 header file에 넣어서 편리하게 사용 가능
    	#include "constants.h"
    */

    double area_circle = PI * 2.0f * 2.0f;

    /*
    	volatile
    	- Do not optimize	(컴파일러야 최적화 하지 마라) (임시공간 등으로 보내서 속도 빠르게 cashing)
    	- (ex: hardward clock)

    	휘발성, 불안정한 의미
    	컴파일러가 모르는 상황에서 값이 바뀔 수 있다고 표기
    	(컴파일러가 알 수 없는 이유로 값이 바뀔 수 있다는 의미)
    */

    volatile int vi = 1;	// volatile location
    volatile int* pvi = &vi;	// points to a volatile location

    int i1 = vi;

    // ...

    int i2 = vi;

    /*
    	restrict (__restrict in VS)
    	- sole initial means of accessing a data object
    	- compiler can't check this restriction
    */

    int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int* par = ar;


    int* __restrict restar = (int*)malloc(10 * sizeof(int));
    if (!restar)exit(1);
    /*
    	동적할당 받아 온 메모리를 다른 수단(다른 포인터 등)을 이용해서 접근하지 않겠다.
    	restar을 통해서만 접근하겠다. 라는 의미
    */

    // array를 통해서 값을 바꾸는 것과 pointer를 통해서 값을 바꾸는 것은 동일
    ar[0] += 3;
    par[0] += 5;
    // par[0] += 8;	// 위 2개를 합치면 8을 한 번에 더하는 것과 같음
    // 하지만 array와 pointer는 서로 다르기 때문에 한 번에 더하는 최적화 불가

    restar[0] += 3;
    restar[0] += 5;
    //restar[0] += 8;	// Equalivalent
    // 위와는 달리 컴파일러가 한 번에 8을 더하는 최적화를 해줄 수도 있다.
    // (__restrict가 최적화를 도와주는 역할)
    /*
    	하지만 컴파일러가 정말로 restrict가 지켜지고 있는지
    	(정말 restar만이 restrict인지) 확인할 수 없다.
    	compiler can't check this restriction
    */

    free(restar);

    return 0;

}

---

## 12.19 멀티 쓰레딩(Multi_Threading)

#define \_CRT*SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
/*
C언어 표준에는 멀티스레딩이 들어와 있지 않다.
대부분의 경우 운영체제에서 제공하는 API 사용
운영체제에 따라서 사용하는 프로그래밍 기술이 다르다.
\_/

//\_Atomic int acnt = 0; // NA

DWORD WINAPI ThreadFunc(void\* data) {

    int n = 1;
    Sleep(1000);

    //acnt += n;	// NA
    printf("Printing from Thread \n");
    return 0;

}

int main() {

    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

    if (thread)
    	WaitForSingleObject(thread, INFINITE);

}

// 이거보다 gcc에서 일반적으로 사용되는 코드가 있다.
// online gcc compiler 구글링
// www.onlinegdb.com/online_c_compiler
/\*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep().
#include <pthread.h>
#include <stdatomic.h>

\_Atomic int acnt = 0; // atomic type qualifer (C11)

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp) {

    int n = 1;	// thread storage duration
    for (int j = 0; j < 10; ++j) {

    	sleep(1);
    	acnt += n;
    	printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
    }

    return NULL;

}

int main() {
pthread_t thread_id1, thread_id2;

    printf("Before Thread\n");

    pthread_create(&thread_id1, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("After Thread\n");
    printf("Atomic %d\n", acnt);

    return 0;

}
\*/

/_
To compile
& gcc <file-name.c> -o <output-file-name> -lpthread
To run
& ./<output-file-name>
_/

---
