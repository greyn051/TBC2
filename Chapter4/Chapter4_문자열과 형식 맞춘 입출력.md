#4.1

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	char fruit_name; // stores only one character.

	printf("What is your favorate fruit?\n");

	scanf("%c", &fruit_name); // be careful with &

	printf("You like %c!\n", fruit_name);

	return 0;
}

위와 같이 하고 Banana 입력하면
You like B!
이래 뜸
//
배열을 사용하자 > name[40], %s
int main() {

	char fruit_name[40]; // stores only one character.

	printf("What is your favorate fruit?\n");

	scanf("%s", fruit_name); // be careful with &

	printf("You like %s!\n", fruit_name);

	return 0;
}

//
#4.2
// sizeof(), size_t

#include <stdio.h>
#include <stdlib.h> // malloc()

int main() {

	/* 1. sizeof basic types */

	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);
	printf("Size of float type is %zu bytes.\n", float_size);

	return 0;
}

// 배열을 직접 sizeof하면 전체 배열의 크기가 나오고(120byte)
포인터를 sizeof 하면 그 주소에 해당된 크기만 나온다.(4byte)
(그런데 프로그래밍 할 때 배열 자체도 주소로 생각하는게 편할 때가 많다)(이건 예외라고 생각하자)

int main() {

	/* 2. sizeof arrays */

	int int_arr[30]; // int_arr[0] = 1024; ...
	int* int_ptr = NULL;
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ...

	printf("Size of array = %zu bytes\n", sizeof(int_arr));
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));

	return 0;
}

// string에서 null을 저장공간으로 하나 가짐

int main() {

	/* 3. sizeof character array */

	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null charater)

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of string type is %zu bytes.\n", str_size);

	return 0;
}

//구조체 struct의 크기

struct MyStruct {
	
	int i;
	float f;
};


int main() {

	/* 4. sizeof structure */

	printf("%zu\n", sizeof(struct MyStruct));
	
	return 0;
}

//
#4.3 문자열이 메모리에 저장되는 원리

// 배열의 index
#include <stdio.h>

int main() {

	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	printf("%i\n", int_arr[10000]); // 범위 넘어가면 오류 뜸
	
	return 0;
}

//문자의 배열, /0(null)의 역할과 존재이유

int main() {

	char c = 'a';
	char str1[10] = "Hello"; // null character
	char str2[10] = { 'H', 'i' };

	printf("%c\n", c);
	printf("%s\n", str1);
	printf("%s\n", str2);

	pritnf("%hhi %hhi %hhi %hhi %hhi\n",
		str2[0], str2[1], str2[2], str2[3], str2[4]);

	return 0;
}

pritnf는 문자 배열 내부에서 0을 만나면 더 이상 출력 x
str2[2] 이후 부터 모든 값 0

//
데이터 크기 넘어가는 만큼 저장 x

char str3[20] = "Hello, \0World";
중간에 null charcater 넣으면 이후에 출력 x, 무시당함(printf의 특성)

int main() {

	char str3[10] = "Hello, World"; // array size is not enough
	char str3[20] = "Hello, \0World";
	printf("%s\n", str3);

	return 0;
}

//
#4.4 strlen() 함수

//
#include <stdio.h>
#include <string.h> // strlen and more

int main() {

	char str1[100] = "Hello";
	char str2[] = "Hello";
	char str3[100] = "\0";
	char str4[100] = "\n";

	printf("%zu %zu\n", sizeof(str1), strlen(str1));
	printf("%zu %zu\n", sizeof(str2), strlen(str2));
	printf("%zu %zu\n", sizeof(str3), strlen(str3));
	printf("%zu %zu\n", sizeof(str4), strlen(str4));

	return 0;
}

// 동적할당 맛보기

int main() {

	/* Extra */
	char *str5 = (char*)malloc(sizeof(char) * 100);
	str5[0] = 'H'; str5[1] = 'e'; str5[2] = '1'; str5[3] = '1'; str5[4] = 'o';
	str5[5] = '\0';
	
	printf("%zu %zu\n", sizeof(str5), strlen(str5));

	return 0;
}

//
#4.5 기호적 상수와 전처리기 #define

// 원의 넓이, 원 둘레 구하기
#include <stdio.h>

int main() {

	float radius, area, circum;

	printf("Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * 3.141592f * radius; // circum = 2.0 * pi * r

	// sphere area, sphere volume, ....

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}

// 원 공식 만들 때 pi를 사람이 계속 입력하면 실수가 나오기 쉽다.
그래서 PI를 기호적 상수로 미리 정의해서 쓰자.

#include <stdio.h>
#define PI 3.141592f

int main() {

	float radius, area, circum;

	printf("Input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}

// 문자열도 define해보자(AI 이름)

#include <stdio.h>
#define PI 3.141592f
#define AI_NAME "Jarvis" // 언제든 편리하게 수정 가능

int main() {

	float radius, area, circum;

	printf("I'm %s.\n", AI_NAME);
	printf("Please, input radius\n");

	scanf("%f", &radius);

	area = PI * radius * radius; // area = pi*r*r
	circum = 2.0f * PI * radius; // circum = 2.0 * pi * r

	printf("Area is %f\n", area);
	printf("Circumference is %f\n", circum);

	//TODO: wrong usage, strings, const

	return 0;
}

//
#4.6 명백한 상수들(Manifest Constants)
//
#include <stdio.h>
#include <limits.h> // INT_MAX, ..., etc.
#include <float.h>  // FLT_MAX, ..., etc.

#define PI 3.141592f // manifest constants, symbolic constants

int main() {

	printf("PI is %f\n", PI);
	printf("Biggest int: %d\n", INT_MAX);
	printf("One byte in this system is %d bits\n", CHAR_BIT);
	printf("Smallest normal float %e\n", FLT_MIN);

	return 0;
}
//
#4.7 printf() 함수의 변환 지정자들(Conversion Specifiers)
//

#include <stdio.h>
#include <limits.h> // INT_MAX, ..., etc.
#include <float.h>  // FLT_MAX, ..., etc.

int main() {

	double d = 3.1415926536897932384626433832795028841971;
	// double에 담을 수 있는 양만 들어가고 나머진 짤려서 사라짐
	// 마우스 갖다대면 어디까지 표시되는지 알 수 있음

	printf("%c\n", 'A'); // 한 글자 표현할 때 작은따옴표'
	printf("%s", "I love you\n");
	printf("Even if there's a small chance, \
we owe this to everyone who's not in this room to try.\n");
	// 표시할 문자열 아주 길 경우 줄바꿈하고 \ 넣으면 됨, 보기 편하다

	printf("\n");
	printf("%d %i %i %i\n", 1004, 1234, INT_MAX, UINT_MAX);//Note overflow, signed에 unsigned 들어감
	printf("%u %u %u\n", 1024, -1, UINT_MAX);			   //Note overflow, unsigned에 -1

	printf("\n");
	printf("%f %f %lf\n", 3.141592f, d, d); // l in %lf is ignored
	printf("%a %A\n", d, d);
	printf("%e %E\n", d, d);

	printf("\n");
	printf("%g %g\n", 123456.789, 1234567.89);
	printf("%G %G\n", 123456.789, 1234567.89);
	printf("%g %g\n", 0.00012345, 0.000012345);
	printf("%G %G\n", 0.00012345, 0.000012345);

	printf("\n");
	printf("%o\n", 9);
	printf("%p\n", &d); // pointer-of operator (d메모리가 사용하고 있는 주소)

	printf("\n");
	printf("%x %X\n", 11, 11);
	printf("%%\n", d); // Note the warning. d is ignored.

	printf("\n");
	printf("%9d\n", 12345); // 자릿수를 맞춰줄 때 유용하게 쓰일 수 있음
	printf("%09d\n", 12345);
	printf("%.2f\n", 3.141592); // 소숫점 2자리 까지 출력
	printf("%.20f %.20lf\n", d, d); // double 타입이 담지 못해서 짤림

	printf("\n");
	int n_printed = printf("Counting!"); // 프린트 함수의 return 값은 출력한 개수다.
	printf("%u\n", n_printed);

	return 0;
}

//
#4.8 변환 지정자의 수식어들(Modifiers)
//

#include <stdio.h>
#include <limits.h>

int main() {

	printf("%10i\n", 1234567);
	printf("%-10i\n", 1234567); // -frag를 붙이면 왼쪽으로 숫자를 붙여줌
	printf("%+i %+i\n", 123,-123); // 앞에 기호를 붙여줌
	printf("% i \n% i\n", 123, -123); // frag가 빈칸일 경우, +는 표시, -는 표시해줌
	printf("%X\n", 17); // 16진수로 출력
	printf("%#X\n", 17); // 0X11로 출력
	printf("%05i\n", 123); // 남는 자리 0으로 채우고, 5자리 까지(파일 이름을 이런식으로 만들 경우 많이 쓰임, 그런 경우 많다)
	printf("%*i\n", 7, 456); // *에 7이 들어가서, %7i와 동일하게 작동(width를 parameter에서 바꾸고 싶은 경우, 유용함)

	printf("\nPrecision\n"); // 정밀도 관련
	printf("%.3d\n", 1024); // 최소 숫자 3자리, 1024는 4자리라서 ㄱㅊ
	printf("%.5d\n", 1024); // 최소 숫자 5자리인데 하나 부족해서 01024로 출력됨
	printf("%.3f\n", 123456.1234567); // float에서는 .이 소수점 이하에 적용, 여기서는 소수점 3자리까지 출력
	printf("%.3f\n", 123456.1235); // .3까지 출력되기 때문에 .4에서는 반올림한다.
	printf("%10.3f\n", 123.45678); // 전체자리수:10, 소수점자리수:3, 반올림 된다, 나머지 3자리는 빈칸으로 출력
	printf("%010.3f\n", 123.45678); // 000123.457로 출력됨
	printf("%.5s\n", "ABCDEFGHIJKLMN"); // 문자개수 5개로 제한, ABCDE 출력
	printf("%.s\n", "ABCDEFGHIJKLMN");// assumes .0 // 숫자 0이 들어있는 것과 동일하게 작동, 출력 안 보임

	printf("\nLength\n");
	printf("%hhd %hd %d\n", 257, 257, 257); // h는 짧다는 뜻, hh이면 char(unsigned char일 경우 256까지 있음) 
	printf("%d %lld %lld\n", INT_MAX + 1, INT_MAX + 1, 2147483648LL); // switch to x64
	//lld를 넣으면 정상적으로 나온다, 숫자 뒤에 LL을 붙여서 long long이라는 것을 표현, 단 x86에서 작동시키면 다르게 나온다

	return 0;
}

//
#4.9 printf() 함수가 인자들을 해석하는 과정
//

#include <stdio.h>

int main() {

	float	n1 = 3.14;  // 4 bytes
	double	n2 = 1.234; // 8 bytes
	int		n3 = 1024;  // 4 bytes

	printf("%f %f %d\n\n", n1, n2, n3); // 정상 출력

	//Note the warnings in output window // 밑에는 모두 비정상 출력
	printf("%d %d %d\n\n", n1, n2, n3);		// 4, 4, 4 (N, N, N) // 연쇄적으로 오류가 생겨서 전부 다 이상한 값이 나옴
	printf("%lld %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (N, N, Y) // 부동소수점 수를 강제로 integer로 해석하려해서 오류, 앞에 2개 오류 났어도 마지막은 데이터 타입이 잘 맞아서 잘 나옴
	printf("%f %d %d\n\n", n1, n2, n3);		// 8, 4, 4 (Y, N, N)
	printf("%f %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (Y, N, Y)

	return 0;
}

//
#4.10 scanf() 함수의 사용법
//

#include <stdio.h>
#include <inttypes.h> // intmax_t

int main() {

	/* multiple inputs with blank separators */
	int i;
	float f;
	char str[30];
	scanf("%d %f %s", &i, &f, str); //Note % is absent in front of str
	printf("%d %f %s\n", i, f, str);

	return 0;
}

//

int main() {

	/* character */
	char c;
	scanf("%c", &c);	// try blank
	printf("%i\n", c); // blank is 32
	// 위에서 '문자열'에서는 빈칸을 입력하면 구분을 하는데, 문자에서는 빈칸을 문자로 인식한다.

	return 0;
}

// 
unsigned 임에도 불구하고 signed 값을 받아서 반환한다.
(이런 트릭을 사용하는 코딩은 좋지 않다)

int main() {

	/* Unsigned as signed */
	unsigned i;
	scanf("%i", &i);	// try negative number
	printf("%i\n", i);

	return 0;
}

// 
%u는 unsigned 만 받기 때문에 음수를 넣으면 overflow 발생

int main() {

	/* Unsigned as unsigned */
	unsigned i2;
	scanf("%u", &i2);	// try negative number
	printf("%u\n", i2);

	return 0;
}

//
scanf에서 double은 %lf로 받아들인다.(%f 받으면 오류 생김)
printf에서 double은 %f로 출력한다.

int main() {

	/* floating point numbers */
	// l for double for %f, %e, %E, %g
	double d = 0.0;  // 만약 float면 scanf에 %f 가능하다
	scanf("%lf", &d);	// lf, try E notation
	printf("%f\n", d);  // f

	return 0;
}

//

int main() {

	/* Width */
	char str[30];
	scanf("%5s", str);	// width // %5s, 5글자 까지만 입력 받음
	printf("%s\n", str);

	return 0;
}

//

int main() {

	/* h modifier */
	char i;
	scanf("%hhd", &i);	// try large numbers // char 타입은 hh붙이고, short타입은 h만 붙인다.
	printf("%i\n", i);

	return 0;
}

//

int main() {

	/* integer with characters */
	int i;
	scanf("%i", &i);	// try '123ab', '123a456' // 문자를 만나면 더 이상 해석 중단
	printf("%i\n", i);	

	return 0;
}

//

int main() {

	/* j modifier */
	intmax_t i;		// 가장 큰 정수형 타입, long long이다.
	scanf("%ji", &i);	// intmax_t를 받아들인다는 앞에 의미로 j를 붙인다.
	printf("%ji\n", i);	

	return 0;
}

//

int main() {

	/* Regular characters */
	int a, b;
	scanf("%d,%d", &a, &b); 	// try blank separator only // 입력할 때 ,를 같이 입력해야 구분해서 인식함 but 빈칸 넣으면 문제 생김
	//scanf("%d ,%d", &a, &b);  // 중간에 빈칸 넣어도 인식 문제 없음
	//scanf("%d, %d", &a, &b);
	//scanf("%d,%d", &a, &b);
	/*scanf("%d-%d", &a, &b);   // , 외 다른 문자도 가능
	scanf("%dA%d", &a, &b);*/
	printf("%d %d\n", a, b);	

	return 0;
}

//

int main() {

	/* char receives blank */
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b); // try 123 456 (blank) or 123A456
	printf("%d|%c|%d\n", a, c, b);	 // | is separator (그냥 출력할 때 구분하려고 넣음)

	return 0;
}

//

int main() {

	/* return calue of scanf() */
	int a, b;
	int i = scanf("%d%d", &a, &b); // scanf의 return 값 : item을 몇 개 입력 받았는가
	printf("%d\n", i);

	return 0;
}

//

int main() {

	/* *modifier for scanf() */
	int i;
	scanf("%*d%*d%d", &i); // 입력 받기는 3개 다 받는데 i에는 %d 꺼만 넣어준다 // 빈칸 또는 줄바꿈을 찾아서 구분
	printf("Your third input = %d", i); // *은 입력은 받는데 무시(suppress)

	return 0;
}

//






