/*
## 11.11 문자열을 숫자로 바꾸는 방법들
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char _ argv[])
{
    /*
        string to integer, double, long
        atoi(), atof(), atol()
        문자열을 숫자로 바꾸는 함수들(stdlib.h 안에 정의가 되어 있다.)
    */

    if (argc < 3)
    	printf("Wrong Usage of %s\n", argv[0]);
    else {
    	/* Example 1 */

    	int times = atoi(argv[1]);
    	// atof(), atol()

    	for (int i = 0; i < times; i++)
    		puts(argv[2]);
    }

    return 0;
}

/*
In command line
D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe 3 hello
hello
hello
hello
*/


/*********************************************************
*********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char _ argv[])
{
    /*
        string to integer, double, long
        atoi(), atof(), atol()
        문자열을 숫자로 바꾸는 함수들(stdlib.h 안에 정의가 되어 있다.)
    */

    if (argc < 3)
    	printf("Wrong Usage of %s\n", argv[0]);
    else {
    	/* Example 2 */

    	printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
    }

    return 0;
}

/*
In command line
D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe 10 21
Sum = 31
*/


/*********************************************************
*********************************************************/


//좀 더 일반적인 경우(8진수, 16진수)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char _ argv[])
{
    /*
        string to long, unsigned long, double
        strtol(), strtoul(), strtod()

    	strtod() converts base 10 only

    	10진수 이외에 8진수나 16진수를 변환할 때 사용하는 함수(좀 더 일반적)
    */

    char str1[] = "1024Hello";
    char* end;
    long l = strtol(str1, &end, 10);	// 앞에 &가 붙었다는 얘기는 이중포인터라는 의미다
    printf("%s %ld %s %d\n", str1, l, end, (int)*end);
    /*
    	strtol에서 숫자로 변환하다가 변환할 수 없는 것을 만나면 end에 넣어준다
    	음수도 가능
    	ex) -1024Hello

    	음엄밀히 말하면 unsigned long으로 받아야한다. strtoul()
    	unsigned long l = strtoul(str1, &end, 10);
    	마우스 갖다대면 반환 자료형이 unsigned long이므로

    	이건 10진수의 경우였다.(10진수에서는 숫자만 변환이 됐다)
    */

    char str2[] = "10FFHello";
    l = strtol(str2, &end, 16);	// 16진수의 경우(FF도 숫자다, 문자 중의 일부가 숫자로 변환)
    printf("%s %ld %s %d\n", str2, l, end, (int)* end);

    return 0;
}


/*********************************************************
*********************************************************/


// 숫자에서 문자로

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char _ argv[])
{
    /*
        Numbers to strings
        Use sprintf() instead of itoa(), ftoa()
        숫자를 문자로 바꾸는 함수

    	itoa(), ftoa()는 표준이 아니기 때문에 사용을 권장하지 않는다.
    */

    char temp[100];
    puts(_itoa(10, temp, 16));	// 10을 16진수로 바꿔서 문자열로 출력
    /*
    	그냥 itoa로 빌드하면 에러 뜬다.
    	표준에서 _itoa로 이름이 바뀌었기 때문
    */

    sprintf(temp, "%x", 10);	// 실무에서 sprintf()를 더 많이 사용함
    puts(temp);

    return 0;
}
