/*
## 4.10 scanf() 함수의 사용법
*/

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

/*********************************************************
*********************************************************/

int main() {

	/* character */
	char c;
	scanf("%c", &c);	// try blank
	printf("%i\n", c); // blank is 32
	// 위에서 '문자열'에서는 빈칸을 입력하면 구분을 하는데, 문자에서는 빈칸을 문자로 인식한다.

	return 0;
}

/*********************************************************
*********************************************************/

/*
unsigned 임에도 불구하고 signed 값을 받아서 반환한다.
(이런 트릭을 사용하는 코딩은 좋지 않다)
*/

int main() {

	/* Unsigned as signed */
	unsigned i;
	scanf("%i", &i);	// try negative number
	printf("%i\n", i);

	return 0;
}


/*********************************************************
*********************************************************/

/*
%u는 unsigned 만 받기 때문에 음수를 넣으면 overflow 발생
*/

int main() {

	/* Unsigned as unsigned */
	unsigned i2;
	scanf("%u", &i2);	// try negative number
	printf("%u\n", i2);

	return 0;
}


/*********************************************************
*********************************************************/

/*
scanf에서 double은 %lf로 받아들인다.(%f 받으면 오류 생김)
printf에서 double은 %f로 출력한다.
*/

int main() {

	/* floating point numbers */
	// l for double for %f, %e, %E, %g
	double d = 0.0;  // 만약 float면 scanf에 %f 가능하다
	scanf("%lf", &d);	// lf, try E notation
	printf("%f\n", d);  // f

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* Width */
	char str[30];
	scanf("%5s", str);	// width // %5s, 5글자 까지만 입력 받음
	printf("%s\n", str);

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* h modifier */
	char i;
	scanf("%hhd", &i);	// try large numbers // char 타입은 hh붙이고, short타입은 h만 붙인다.
	printf("%i\n", i);

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* integer with characters */
	int i;
	scanf("%i", &i);	// try '123ab', '123a456' // 문자를 만나면 더 이상 해석 중단
	printf("%i\n", i);

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* j modifier */
	intmax_t i;		// 가장 큰 정수형 타입, long long이다.
	scanf("%ji", &i);	// intmax_t를 받아들인다는 앞에 의미로 j를 붙인다.
	printf("%ji\n", i);

	return 0;
}


/*********************************************************
*********************************************************/


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


/*********************************************************
*********************************************************/


int main() {

	/* char receives blank */
	int a, b;
	char c;
	scanf("%d%c%d", &a, &c, &b); // try 123 456 (blank) or 123A456
	printf("%d|%c|%d\n", a, c, b);	 // | is separator (그냥 출력할 때 구분하려고 넣음)

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* return calue of scanf() */
	int a, b;
	int i = scanf("%d%d", &a, &b); // scanf의 return 값 : item을 몇 개 입력 받았는가
	printf("%d\n", i);

	return 0;
}


/*********************************************************
*********************************************************/


int main() {

	/* *modifier for scanf() */
	int i;
	scanf("%*d%*d%d", &i); // 입력 받기는 3개 다 받는데 i에는 %d 꺼만 넣어준다 // 빈칸 또는 줄바꿈을 찾아서 구분
	printf("Your third input = %d", i); // *은 입력은 받는데 무시(suppress)

	return 0;
}
