/*
## 4.7 printf() 함수의 변환 지정자들(Conversion Specifiers)
*/

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
