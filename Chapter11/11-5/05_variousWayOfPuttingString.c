/*
## 11.5 문자열을 출력하는 다양한 방법들
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

int main() {

    /*
    	puts() : add \n at the end
    */

    char str[60] = "String array initialized";
    const char* ptr = "A pointer initialized";

    puts("String without \\n");
    puts("END");
    puts(TEST);
    puts(TEST + 5);
    puts(&str[3]);
    //puts(str[3]);// Error
    puts(ptr + 3);

    return 0;
}


/*********************************************************
*********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

int main() {

    /*
    	string without \0
    */

    char str[] = { 'H', 'I', '!' }; // No \0 at the end.
    puts(str);	// VS warns you!
    /*
    	null character를 찾을 수 없어서 계속 출력
    	메모리에 우연히 만나는 null character를 만날 때 까지 계속 출력함
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

int main() {

    /*
    	puts() and fputs()
    */

    //char line[100];
    //while (gets(line))	// while (gets(line) != NULL)
    //	puts(line);

    char line[100];
    while (fgets(line, 100, stdin))
    	fputs(line, stdout);

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    /*
    	printf()
    */

    char str[] = "Just do it, do it!";
    printf("%s\n", str);	// \n added (의도적으로 \n을 추가해줘야 생김)
    puts(str);

    char input[100] = "";
    int ret = scanf("%10s", input); // Input : "Just do it, do it!\n" (Note %10s)
    printf("%s\n", input);	// Output : "Just" // scanf는 빈칸을 만나면 더 이상 읽지 않는다
    ret = scanf("%10s", input);		// Reads remaining buffer
    printf("%s\n", input);			// Output : "do"
    /*
    	scanf의 장점: 여러가지 자료형이 섞여있을 때 입력받기 편하다.
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEST "A string from #define."

/*
    puts() which doesn't add a new line at the end
    Use pointer increment operator and putchar() ⭐ 다시 혼자 해보기
*/
void custom_put(const char* str); // Only two lines
int custom_put2(const char* str); // Add \n, return # of characters(몇 글자인지 return)

int main() {

    /*
    	Custom function
    */

    custom_put("Just ");
    custom_put("Do it!");

    printf("%d\n", custom_put2("12345"));

    return 0;

}
// ⭐
void custom_put(const char\* str) {

    while (*str != '\0') // while(*str) (이렇게 줄여서 쓸 수도 있다.)
    	putchar(*str++);
}
// Only two lines
// ⭐
int custom_put2(const char\* str) {

    int count = 0;
    while (*str) {
    	putchar(*str++);
    	count++;
    }
    putchar('\n');

    return count;
}
// Add \n, return # of characters
