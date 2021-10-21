/*
## 4.8 변환 지정자의 수식어들(Modifiers)
*/

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
