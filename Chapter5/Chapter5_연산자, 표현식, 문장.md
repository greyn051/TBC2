# TBC-5 연산자, 표현식, 문장

## 5.1 반복 루프와의 첫 만남

### 이제 거의 안 쓰는 goto 문

```c
#include <stdio.h>

int main() {

	int n = 1;

label:
	printf("%d\n", n);
	n = n + 1;

	if (n == 10) goto out;

	goto label;

out:

	return 0;
}
```

### while문으로 바꿔서 쓰기

```c
int main() {

	int n = 1;

	while (n < 11) {
		printf("%d\n", n);
		n = n + 1;
	}

	return 0;
}
```

## 5.2 대입 연산자와 몇 가지 용어들(Object, L-value, 피연산자)

-

## 5.3 더하기, 빼기, 부호 연산자들(Addition, Subtraction, Sign)

```c
#include <stdio.h>

int main() {
printf("%d\n", 1 + 2);

	int income, salary, bonus;

	income = salary = bonus = 100;// triple assignment, 오른쪽 부터 값을 대입, 전체가 100됨, income = (salary = (bonus = 100));과 같음

	salary = 100;
	bonus = 30;

	income = salary + bonus;// l-value vs r-value

	int takehome, tax;
	tax = 20;
	takehome = income = tax;

	int a, b;
	a = -7;
	b = -a;
	b = +a;// + does nothing

	1.0f + 2;// ? float로 저장됨(실수 + 정수는 실수로 저장) promotion 승진 이라고 불림

	return 0;
}
```

## 5.4 곱하기 연산자

### 복리 계산 프로그램 만들기

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
double seed_money, target_money, annual_interest;

    printf("Input seed money : ");
    scanf("%lf", &seed_money);

    printf("Input target money : ");
    scanf("%lf", &target_money);

    printf("Input annual interest (%%) : ");
    scanf("%lf", &annual_interest);

    double fund = seed_money;
    int year_count = 0;

    while (fund < target_money) {
    	fund = fund * (1 + annual_interest / 100.0);
    	// fund += fund * annual_interest / 100.0; // 코드 줄이고 싶을 때
    	year_count = year_count + 1;
    	// year_count += 1; // 코드 줄이고 싶을 때
    	// year_count++; // C에서만 이렇게 더 줄일 수 있다(증가연산자)

    	printf("Year %d, fund %f\n", year_count, fund);
    }

    printf("It takes %d years\n", year_count);

    return 0;
}
```

//

#5.5 나누기 연산자

//

#include <stdio.h>

int main() {
printf("Integer divisions\n");
printf("%d\n", 14 / 7);
printf("%d\n", 7 / 2);// 3.5 in floating division // 정수에서는 소수점 잘라내서 3이 출력된다
printf("%d\n", 7 / 3);// 2.333 in floating division
printf("%d\n", 7 / 4);// 1.75 in floating division
printf("%d\n", 8 / 4);// 2

    printf("Truncating toward zero (C99)\n");
    printf("%d\n", -7 / 2);// -3.5 in floating division // 정수에서는 소수점 잘라내서 -3이 출력된다
    printf("%d\n", -7 / 3);// -2.333 in floating division
    printf("%d\n", -7 / 4);// -1.75 in floating division
    printf("%d\n", -8 / 4);// -2

    printf("\nFloating divisions\n");
    printf("%f\n", 9.0 / 4.0);
    printf("%f\n", 9.0 / 4);// Note: 4 is integer // 컴파일러가 4를 double로 바꿔서 계산한 결과(다른 자료형끼리는 계산 불가), 가급적 같은 자료형끼리 계산하자

    return 0;

}

//

#5.6 연산자 우선순위와 표현식 트리(Operator Precedence, Expression Tree)
//

#5.7 나머지 연산자(Modulus Operator)
//

#include <stdio.h>

int main() {
int seconds = 0, minutes = 0, hours = 0;

    printf("Input seconds : ");
    scanf("%d", &seconds);

    //TODO: seconds -> hours, minutes, seconds
    minutes = seconds / 60;
    seconds %= 60; //seconds = seconds % 60;

    hours = minutes / 60;
    minutes %= 60; //minutes = minutes % 60;

    // printf result
    printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    printf("Good bye\n");

    return 0;

}

//
반복해서 사용할 수 있도록 while문 사용해보자(음수가 나오면 종료)

int main() {
int seconds = 0, minutes = 0, hours = 0;

    while (seconds >= 0) {
    	printf("Input seconds : ");
    	scanf("%d", &seconds);

    	minutes = seconds / 60;
    	seconds %= 60; //seconds = seconds % 60;

    	hours = minutes / 60;
    	minutes %= 60; //minutes = minutes % 60;

    	// printf result
    	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    }

    printf("Good bye\n");

    return 0;

}

//
음수 입력하면 계산값 생략하고 바로 goodbye 나올 수 있게

int main() {
int seconds = 0, minutes = 0, hours = 0;

    printf("Input seconds : ");
    scanf("%d", &seconds);

    while (seconds >= 0) {
    	minutes = seconds / 60;
    	seconds %= 60; //seconds = seconds % 60;

    	hours = minutes / 60;
    	minutes %= 60; //minutes = minutes % 60;

    	// printf result
    	printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    	printf("Input seconds : ");
    	scanf("%d", &seconds);
    }

    printf("Good bye\n");

    return 0;

}

//
음수에서 나머지 연산자의 결과는?

int main() {
int div, mod;

    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod);

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / -5;
    mod = -11 % -5;// first operand is negative // 앞에 있는 피연산자가 음수면 나머지 연산자의 결과도 음수다
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / 5;
    mod = -11 % 5;// first operand is negative
    printf("div = %d, mod = %d\n", div, mod);

    return 0;

}

//

#include <stdio.h>

int main() {
int a = 0;
a++; // a = a + 1 or a += 1;
printf("%d\n", a);

    ++a; // a = a + 1 or a += 1;
    printf("%d\n", a);

    return 0;

}

//

int main() {
double b = 0; // 실수형에서도 1.0을 더해주는 효과
b++;
printf("%f\n", b);

    ++b;
    printf("%f\n", b);

    return 0;

}

//
while에서 ++

int main() {
int count = 0;
while (count < 10) // ++count or count++
{
printf("%d ", count); // ++count or count++
count ++; // ++count or count++ 현재 상태에서 기능은 같다.
}

    return 0;

}

//
※ while()안에 ++
//
++count

int main() {
int count = 0;
while (++count < 10) // ++count or count++
{
printf("%d ", count); // ++count or count++
//++count;
}

    return 0;

}

1 더하고 시작
결과 : 1~9
//
count++

int main() {
int count = 0;
while (count++ < 10) // ++count or count++
{
printf("%d ", count); // ++count or count++
//++count;
}

    return 0;

}

결과 : 1~10
비교 후 ++가 적용된다(예약하는 형태)
//
printf 안에서 ++

int main() {
int count = 0;
while (count < 10) // ++count or count++
{
printf("%d ", ++count); // ++count or count++
//++count;
}

    return 0;

}

결과 : 1~10
//

int main() {
int count = 0;
while (count < 10) // ++count or count++
{
printf("%d ", count++); // ++count or count++
//++count;
}

    return 0;

}

결과 : 0~9
printf 적용하고 ++적용
//
★

int main() {
int i = 1, j = 1;
int i_post, pre_j;

    i_post = i++;
    pre_j = ++j;

    printf("%d %d\n", i, j);
    printf("%d %d\n", i_post, pre_j);

    return 0;

}

//

int main() {
int i = 3;
int l = 2 \* --i;
printf("%d %d\n", i, l);

    i = 1;
    l = 2 * i--;
    printf("%d %d\n", i, l);

    return 0;

}

//

int main() {
/_ very high precedence _/
int x, y, z;
x = 3, y = 4;
z = (x + y++) \* 5; // (x+y)++ or x+(y++) ?
printf("%d %d %d", x, y, z);

    return 0;

}

//

int main() {
/_ ++ and -- affect modifiable lvalues _/ // literal이나 const에 사용 불가
int x = 1, y = 1, z;
z = x _ y++; // (x) _ (y++), not (x*y)++ // (x*y)는 일시적으로 r-value이기 때문에 안됨(메모리 공간 갖지 못함, 일시적임)
//z = (x \* y)++; //error
//z = 3++; //error

    return 0;

}

//
주의사항

int main() {
/_ Bad practices _/ // n++를 너무 남발해서 복잡해 보이지 않도록 하자(명확한 경우에만 사용하자)
int n = 1;
printf("%d %d", n, n _ n++); // 여러번 사용할 때, 시스템마다 결과가 다르게 나올 수 있다.(안전하지 않음)
int x = n / 2 + 5 _ (1 + n++); // 이 경우도 마찬가지, 이럴 때에는 식을 쪼개는 게 좋다.(의도를 명확하게 반영할 수 있도록)
int y = n++ + n++; // 헷갈리고 의도가 무엇인지 헷갈린다.

    return 0;

}

//

#5.9 표현식과 문장(Expressions, Statements)

//

#5.10 순서도(Flowcharts)

//

int main() {
int i = 0;
while (i < 10)
// an example of compound statements
// (block)
{
i++;
printf("%d\n", i);
}

    return 0;

}

{ }를 compound statements나 block으로 부름
//

#5.11 자료형 변환(Type Conversions)

#include <stdio.h>

int main() {
/_ promotions in assignments _/
short s = 64;
int i = s;

    float f = 3.14f;
    double d = f;

    /* demotion in assignments */
    d = 1.25;
    f = 1.25; // 1.25는 0.25가 1/4 즉 2배수에 대한 역수이므로 문제 없다.
    //f = 1.123; // 1.123은 double과 float일 때 미묘하게 값이 차이가 난다.(truncation(절삭) 오류)

    /* ranking of types in operations */ // 밑으로 내려갈 수록 ranking이 낮다
    // long double > double > float
    // unsigned long long, long long
    // unsigned long, long
    // unsigned, int
    // short int, unsigned short int
    // signed char, char, unsigned char
    // _Bool
    //Ref: Google 'Integer conversion rank'
    d = f + 1.234;
    f = f + 1.234; // r-value는 double이 된다. 그래서 truncation 오류 뜬다

    /* automatic promotion of function arguments */
    // 1. Functions without prototypes
    // 2. Variadic functions (ellipsis)

    /* casting operators */ // 형변환을 할 거라고 의도적으로 표현
    d = (double)3.14f; // (double)을 해주면 이 expression의 값은 double이 된다.
    i = 1.6 + 1.7; // truncation 되면서 i = 3이 된다.
    i = (int)1.6 + (int)1.7; // 1 + 1되고 i =2이 된다.

    /* more examples */
    char c;
    //int i;
    //float f;
    f = i = c = 'A'; // 65
    printf("%c %d %f\n", c, i, f);
    c = c + 2; // 'C', 67
    i = f + 2 * c; // 65.0f + 2 * 67
    printf("%c %d %f\n", c, i, f); // 199
    c = 1106; // demolition(강등된다), 1106 = 0b10001010010(이진수),	(앞부분 잘라내고 1byte=8bit만 남김, 이게 마치 나머지 연산자 적용한 것과 같음)0b01010010 = 1106 % 256 = 82 = 'R'
    printf("%c\n", c);
    c = 83.99; // truncation, 83
    printf("%c\n", c);

    return 0;

}

//

#5.12 함수의 인수와 매개변수(Arguments vs. Parameters)

//

숫자에 따라 그 개수만큼 별이 출력되는 프로그램 만들기
(별을 출력하는 부분을 함수로 만들어서 반복해서 사용을 하는 것이 이 프로그램의 가장 중요한 점)
and argument와 parameter의 차이

#include <stdio.h>

void draw(int n); // ANSI function prototype declaration

int main() {
int i = 5;
char c = '#'; // 35
float f = 7.1f;

    draw(i); /* 함수를 호출하는 측면에서 실제로는 5(i에 들어있는 값)를 넣는 것이므로 argument, value라고 부른다.
    draw((int)c); // draw(c); // promotion은 문법상 문제가 없지만 의도를 확실히 하기 위해서 draw((int)c);라고 써주는 것이 좋다.
    draw((int)f); // draw(f); // demotion warning을 방지하려면 draw((int)f); 라고 써야한다.

    /* Arguments vs. Parameters */ // (argument, parameter가 수식어까지 붙으며 너무 혼용된다고 생각해서 C99에서 정리)
    // actual argument, actual parameter(실 인수, 실 매개변수) -> argument (values)(C99에서 정리)
    // formal argument, formal parameter(형식 인자, 형식 매개변수) -> parameter (variables)

    /* 요약하면 함수를 호출하는 측면에서 볼 때는 i를 argument(value)라고 부르고,
       draw함수를 정의하는 입장에서 볼 때는 변수 n이 parameter(variable)가 된다.*/

    return 0;

}

void draw(int n) /_ n에 어떠한 값이 들어와도 함수를 수행할 수 있어야한다. n을 변수로 받아들인다.(function draw가 variable n에 대해서 parameterization(매개변수화)되어있다.) _/
{
//TODO: print stars (asterisks)
while (n-- > 0)
printf("\*");
printf("\n");
}

※ 내가 한 함수 코드
void draw(int n) {
//TODO: print stars (asterisks)
int m = 0;
while (m++ < n) {
printf("\*");
}

    printf("\n");

}

//
