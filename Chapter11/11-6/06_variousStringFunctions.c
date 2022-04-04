/*
## 11.6 다양한 문자열 함수들
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char\*, unsigned int);

int main() {

    /*
    	strlen() : returns length of the string
    */

    //TODO: use debugger
    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));
    //TODO: implement fit_str() function

    return 0;
}

/*********************************************************
*********************************************************/

//※ 내 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char\*, unsigned int);

int main() {

    /*
    	strlen() : returns length of the string
    */

    //TODO: use debugger
    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));
    //TODO: implement fit_str() function

    return 0;
}

void fit_str(char\* ptr, unsigned int n) {

    *(ptr + n) = '\0';
    //*(ptr + n) = "\0"; // ""를 넣으면 안 된다.(내가 하다가 발견)
    /*
    	※참고
    	https://www.inflearn.com/questions/142917
    	https://www.inflearn.com/questions/80454
    */
}

/*********************************************************
*********************************************************/

//※ 교수님 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fit_str(char\*, unsigned int);

int main() {

    /*
    	strlen() : returns length of the string
    */

    //TODO: use debugger
    char msg[] = "Just,"" do it!";
    puts(msg);
    printf("Length %d\n", strlen(msg));
    fit_str(msg, 4);
    puts(msg);
    printf("Length %d\n", strlen(msg));
    //TODO: implement fit_str() function

    return 0;
}

void fit_str(char\* str, unsigned int size) {

    if (strlen(str) > size)	// 문자열 사용 시 크기 확인하는 것이 중요
    	str[size] = '\0';
}

/*********************************************************
*********************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    /*
    	strcat() and strncat() : string concatenation(cat을 만나면 거의 다 concatenation)
    */

    char str1[100] = "First string";	// 뒤에 문자열 추가하므로 많은 공간 할당
    char str2[] = "Second string";

    strcat(str1, ", ");
    strcat(str1, ", ");
    //strncat(str1, str2, 2);	// Append 2 character
    puts(str1);

    //TODO: implement my_strcat() function!⭐(꼭 해볼 것)(뒤에 다른 문자열 함수들도)
    //strcat()와 동일하게 작동하는 함수 구현해보자 (Implement strcat() function in C 구글링하면 정답 알 수 있음)

    return 0;
}

/*********************************************************
*********************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    /*
    	strcmp() and strncmp() : compare strings (not characters) // cmp는 compare의 약자
    */
    // "문자열"끼리 비교하는 것이지 '문자'끼리 비교하는 것은 아니다.

    printf("%d\n", strcmp("A", "A"));	// 간결하게 설명하기 위해서 한 글자 짜리 문자열을 대입함
    printf("%d\n", strcmp("A", "B"));
    printf("%d\n", strcmp("B", "A"));
    printf("%d\n", strcmp("Hello", "Hello"));
    printf("%d\n", strcmp("Banana", "Bananas"));	// 뒤에 \0과 s를 비교하면 s가 더 큼
    printf("%d\n", strcmp("Bananas", "Bananas"));
    printf("%d\n", strcmp("Bananas", "Banana", 6));	// 글자수 정할 수 있다.
    //TODO: implement strcmp!⭐
    /*
    	strcmp(), strncmp()의 반환값은 특이하다.
    	같으면 0을 반환한다.
    	앞에 있는 문자가 ASCII코드로 반환했을 때 더 빠르면 -1을 출력,
    	반대인 상황에서는 1을 출력
    */

    return 0;
}

/*********************************************************
*********************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    /*
    	strcpy() and strncpy()	// 내용물을 한 글자, 한 글자 다 돌면서 복사
    */

    char dest[100] = "";	// make sure memory is enough
    char source[] = "Start programming!";
    //dest = source;	// Error (이유는 앞에 배열 강의에)
    //dest = "Start something";// Error
    strcpy(dest, source);
    /*
    	마우스 갖다대면 strcpy(char*_Destination, const char*_Source)
    	source(원본)를 destination(목적지)에 갖다 복사하는 것이다.
    	dest는 아주 많이 보게 될 용어다.
    */
    strncpy(dest, source, 5);	// '\0' is NOT added
    strcpy(dest, source + 6);	// 포인터 연산 사용
    strcpy(dest, source);
    strcpy(dest + 6, "coding");
    puts(dest);

    return 0;
}

/*********************************************************
*********************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    /*
    	sprintf()⭐
    */

    char str[100] = "";
    int i = 123;
    double d = 3.14;
    sprintf(str, "%05d.png %f", i, d);	// 문자열에 printf()한 것을 대입
    puts(str);
    // capture00000.png, capture00001.png, ...

    return 0;
}

/*********************************************************
*********************************************************/

#include <stdio.h>
#include <string.h>

int main() {

    /*
    	There are more functions...
    */

    printf("%s\n", strchr("Hello, World", 'W'));	// W가 시작되는 위치를 찾아서 포인터를 return 해준다. 그걸 다시 spring으로 표현

    printf("%s\n", strpbrk("Hello, World", "ABCDE"));	// 이 중(ABCDE)에 하나로 시작되는 부분을 찾는다. 없으면 (null) 출력
    printf("%s\n", strpbrk("Hello, World", "abcde"));

    printf("%s\n", strchr("Hello, World, Hello, World", 'l'));// last occurrence	// 글자가 나타내는 가장 마지막 포인터를 return 해준다.

    printf("%s\n", strstr("Hello, World", "wor"));	// strstr은 문자열 끼리 비교, 그 문자열이 나타내는 첫번째 포인터 return
    printf("%s\n", strstr("Hello, World", "Wor"));

    return 0;
}
