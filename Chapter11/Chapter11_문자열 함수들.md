# TBC-11 문자열 함수들

## 11.1 문자열(Strings)을 정의하는 방법

```c
#include <stdio.h>

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main() {

	char words[MAXLENGTH] = "A string in an array";	// 문자열 자체로 선언 // char type의 배열이 된다.
	const char* pt1 = "A pointer to a string.";	// 문자열의 포인터, 첫번째 주소를 가리킴

	puts("Puts() adds a newline at the end:"); // puts() add \n at the end
	puts(MESSAGE);
	puts(words);	// char words[21] removes this warning // MAXLENGTH 사용 시 모든 문자열 채워지지 않았기 때문에 warning뜸
	puts(pt1);
	words[3] = 'p';	// OK (저 위치에 있는 문자 p로 교체 원함)
	puts(words);
	//pt[8] = 'A';	// Error (그냥 char* pt1 일 때 build는 되는데 runtime error 발생)
	/*
		읽기 전용 메모리에 저장된 데이터의 값을 바꾸려고 시도하면 운영체제가 중단시킴
		그래서 앞에 const를 붙여야 좋음

		배열은 읽기/쓰기가 모두 가능한 메모리를 사용한다.
		문자열 리터럴은 프로그램의 일부이기 때문에
		읽기 전용 메모리에 저장되어 있다.
	*/

	char greeting[50] = "Hello, and"" How are" " you"
		" today!"; // 바로 밑과 동일하게 compiled

	//char greeting[50] = "Hello, and How are you today!";

	puts(greeting);

	printf("\" To be, or not to be\" Hamlet said.\n"); // "자체 출력

	printf("$s, %p, %c\n", "We", "are", *"excellent programmers"); // %p 배열의 첫 글자가 저장된 주소 출력, %c indirection하면 첫번째 글자 출력

	const char m1[15] = "Love you!";

	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m1[i]);	// Note the null characters // 남는 공간 모두 0으로 출력
	printf("\n");

	// 문자열이 아니라 문자의 배열로서 초기화(위와 같은 기능)
	const char m2[15] = { 'L', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '!', '\0' }; // ※주의 \0을 수동으로 써야함

	for (int i = 0; i < 15; ++i)
		printf("%d ", (int)m2[i]);	// Note the null characters // 남는 공간 모두 0으로 출력
	printf("\n");

	const char m3[] = "Love you, too!";	// compiler 알아서 세라

	int n = 8;
	char cookies[1] = { 'A', };
	char cakes[2 + 5] = { 'A', };
	char pies[2 * sizeof(long double) + 1] = { 'A', }; // [] 안에 실수가 들어가면 안 된다.
	//char crumbs[n]; // VLA

	// 배열의 이름 자체는 첫번째 원소의 주소
	char truth[10] = "Truths is ";
	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");
	if (*(truth + 1) == truth[1]) puts("true!");	// 포인터 연산
	if (truth[1] == 'r') puts("true!");

	return 0;
}
```

//

## 11.2 메모리 레이아웃(Memory Layout)과 문자열

이번
강의의 목표는
char arr[] = "Hello, World";

char\* str = "Hello, World";
//str[0] = 'M'; // ERROR!!!

이 두 가지의 차이를 이해하는 것이다.

---

```c
#include <stdio.h>
#include <stdlib.h> // malloc

void test_function() {
	int j;
	printf("Stack high \t%llu\n", (unsigned long long)&j);
}

int main() {

	/* Array Versus Pointer */
	const char* pt2 = "I am a string!.";
	const char* pt3 = "I am a string!.";	// 같은 문자열의 포인터는 주소가 같음
	const char* pt4 = "I am a string!!!!!!."; // <- different
	const char ar1[] = "I am a string!.";
	const char ar2[] = "I am a string!.";	// 배열이기 때문에 모두 주소를 따로 받는다.
	const char ar3[] = "I am a string!!."; // <- different

	//x64로 build, 16진수로 보기 불편해서 10진수로 형변환
	printf("rodata low \t%llu %llu %llu %llu\n",
		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
		(unsigned long long)"I am a string!.");
	/*
		포인터 변수들 pt2와 pt3에 저장되어 있는 주소값들이 동일한데
		pt4가 가리키고 있는 주소값은 다르다.
		마지막 문자열의 주소처럼 사용하고 있는 경우에도 pt2, pt3와 주소가 같다.
		compiler는 똑같은 것을 한 번만 써서 크기를 줄인다.
	*/

	printf("Stack high \t%llu %llu %llu\n", (unsigned long long)ar1,
		(unsigned long long)ar2, (unsigned long long)ar3); // check address number!
	/*
		배열은 배열 자체가 각각 메모리를 확보한다.
		그러므로 주소가 다 다르다.
	*/

	// window와 linux에서 high와 low의 주소값은 상대적으로 다를 수 있다.

	/* Memory address check */
	/* Local variables */

	printf("Stack high \t%llu %llu %llu\n",
		(unsigned long long) & pt2, (unsigned long long) & pt3, (unsigned long long) & pt4);
	// &pt2는 pt2 자체의 주소(포인터 자체에 대한 주소)

	int i;
	printf("Stack high \t%llu\n", (unsigned long long) & i);

	/* Local variable in a function */
	test_function();

	/* Dynamic allocation */
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p5);

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Heap middle \t%llu\n", (unsigned long long)p6);

	/* Array Versus Pointer (continued) */

	//ar1++;	// Error (ar1은 포인터가 아니라 배열의 이름)
	pt2++;		// OK (pointer는 증가연산자 사용 가능)
	puts(pt2);	// Check the first character

	/* Array and Pointer Differences */

	char heart[] = "I love Kelly!";
	const char* head = "I love Helly!";

	for (int i = 0; i < 6; i++)
		putchar(heart[i]);		//Note: putchar()
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(head[i]);		//Note: putchar()
	putchar('\n');

	// pointer addition
	for (int i = 0; i < 6; i++)
		putchar(head[i]);		//Note: putchar()
	putchar('\n');

	for (int i = 0; i < 6; i++)
		putchar(*(head + i));
	putchar('\n');

	while (*(head) != '\0')
		putchar(*(head++));

	head = heart;	// pointer에 배열의 이름 대입 가능(배열의 이름은 포인터와 호환 됨)
	//heart = head; // Error

	// Cannot change heart. Can change the elements of heart
	heart[7] = 'H';		// Note: character
	*(heart + 7) = 'K';

	putchar('\n');

	char* word = "Google";
	//word[2] = 'o';		// Run-time error! (컴파일은 되는데 막힌다)
	puts(word);
	/*
		포인터를 통해서 원소를 바꿀 수 없다.
		포인터는 stack의 메모리를 가리키는게 아니라 text segment에 있는 메모리를 가리킨다.
		후자들은 프로그램에 담겨있는 것이기 때문에 우리가 바꿀 수 없도록 운영체제가 막아버린다.
	*/
	//Note: const char * word = "Goggle"; is recommended

	const char *str1 = "When all the lights are low, ...";
	const char *copy;

	copy = str1;

	printf("%s %p %p\n", str1, str1, &str1);
	printf("%s %p %p\n", copy, copy, &copy);

	//Note: strcpy(), strncpy() // 문자열 데이터 자체를 복사하고 싶을 때 사용

	return 0;
}
```

---

## 11.3 문자열의 배열
```c
#include <stdio.h>

int main() {

    /* Arrays of Character Strings */

    const char* mythings[5] = {
    	"Dancing in the rain",
    	"Counting apples",
    	"Watching movies with friends",
    	"Writing sad letters",
    	"Studying the C language"
    };

    // 40개 짜리 배열을 5개
    char yourthings[5][40] = {
    	"Studying the C++ language",
    	"Eating",
    	"Watching Netflix",
    	"Walking around till dark",
    	"Deleting spam emails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);		// pointer라서 주소가 같다
    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
    //printf("%u %u\n", (unsigned)&yourthings[0][0], (unsigned)temp2);
    printf("\n");

    printf("%-30s %-30s\n", "My Things:", "Your Things:");
    for (int i = 0; i < 5; i++)
    	printf("%-30s %-30s\n", mythings[i], yourthings[i]);

    printf("\nsizeof mythings: %zd, sizeof your yourthings: %zd\n",
    	sizeof(mythings), sizeof(yourthings));

    // 메모리 구조 파악을 위해 실험 삼아 실행
    for (int i = 0; i < 100; i++)
    	printf("%c", mythings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; i++)
    	printf("%d", (int)yourthings[0][i]);
    printf("\n");

    for (int i = 0; i < 200; i++)
    	printf("%c", yourthings[0][i]);
    printf("\n");
    printf("\n");

    // Not a good idea to take advantage of this property

    return 0;
}
```
---

## 11.4 문자열을 입력 받는 다양한 방법들
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    /* Creating Space */

    //char* name = ""; // Error at RUN-TIME
    char name[128];
    int result = scanf("%s", name);	// 배열의 이름이 pointer와 비슷하게 작동하므로 앞에 *를 안 붙여줘도 된다.
    /*
    	입력받은 문자열을 저장할 공간을 확보한 다음에 입력을 받아야한다.
    */

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /*
    	scanf() vs gets()
    	scanf() reads one word
    	gets() reads one line and removes \n and add \0
    */

    char words[STRLEN] = "";	// Warning without initialization
    gets(words);		// gets receives pointer. No idea when string ends. (배열의 이름인 포인터만 받아서 어디서 끝나는 지를 모른다. 보완하기 위해서 gets_s 사용)
    //gets_s(words, sizeof(words));		// C11 (최근에 gets_s 사용하기 시작)
    //gets_s(words, STRLEN);
    //int result = scanf("%s", words);
    printf("START\n");
    printf("%s", words);	// no \n at the end
    puts(words);			// puts() adds \n at the end (줄 바꿈 알아서 함)
    puts("END.");

    //TODO: try char words[5];
    /*
    	사이즈가 입력한 값 사이즈보다 작을 때
    	runtime error가 발생한다.
    	이걸 극복하기 위해 fgets(), fputs() 사용
    */

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[5] = "";
    fgets(words, 5, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'

    return 0;
}
```
// 디버그하면 words에 \n이 같이 입력되는 걸 확인할 수 있는데 \n을 \0으로 바꿔보자
TODO: replace '\n' with '\0'

※ 내 코드
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    for (int i = 0; i < STRLEN; ++i) {
    	if (words[i] == '\n') {
    		words[i] = '\0';
    	}
    }

    return 0;
}
```
※ 교수님 코드
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    int i = 0;
    while (words[i] != '\n' && words[i] != '\0')
    	i++;
    if (words[i] == '\n')
    	words[i] = '\0';

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    int i = 0;
    while (words[i] != '\n' && words[i] != '\0')
    	i++;
    if (words[i] == '\n')
    	words[i] = '\0';

    fputs(words, stdout);			// does NOT add \n
    fputs("END", stdout);

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Small array */

    char small_array[5];
    puts("Enter long strings:");
    fgets(small_array, 5, stdin);	// FILE *_Stream
    //printf("%p\n", small_buffer);
    //printf("%p\n", fgets(small_buffer, 5, stdin));	// Return value of fgets
    fputs(small_array, stdout);
    /*
    	메모리 공간 초과해서 입력해도 공간 만큼 입력을 받는다.
    	그리고 runtime error가 일어나지 않는다.
    */

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Small array */

    char small_array[5];
    puts("Enter long strings:");
    //fgets(small_array, 5, stdin);	// FILE *_Stream
    printf("%p\n", small_array);
    printf("%p\n", fgets(small_array, 5, stdin));	// Return value of fgets
    fputs(small_array, stdout);

    return 0;
}
```
^z 입력시 null charcater 출력됨
(EOF: End of File)

---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Repeating short reading */

    char small_array[5];
    puts("Enter long strings:");
    while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    	fputs(small_array, stdout);
    	//puts(small_array);	// What if we use puts()
    /*
    	마치 한 번에 많이 입력 받아서 출력하는 것 처럼 보임
    	내부적으로 buffer를 사용하기 때문
    */

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* scanf() */

    char str1[6], str2[6];
    int count = scanf("%5s %5s", str1, str2);
    //int count = scanf("%6s %6s", str1, str2); // run-time error
    //int count = scanf_s("%5s %5s", str1, 6, str2, 6);
    printf("%s|%s \n", str1, str2);
    /*
    	scanf로 string 입력받을 때 글자 개수 제한 가능
    */

    return 0;
}
```
---
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main() {

    /* An example of custom input function */
    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

// 문자열 입력 함수 만들기
char* custom_string_input(char* st, int n) {
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr) {
    	while (st[i] != '\n' && st[i] != '\0')
    		i++;
    	if (st[i] == '\n')
    		st[i] = '\0';
    	else
    		while (getchar() != '\n')	// clear buffer
    			continue;
    }
    return ret_ptr;
}
```
---

## 11.5 문자열을 출력하는 다양한 방법들
```c
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
``
---
```c
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
```
---
```c
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
```
---
```c
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
```
---
```c
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
```
---

## 11.6 다양한 문자열 함수들
```c
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
```
---

※ 내 코드
```c
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
```
---

※ 교수님 코드
```c
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
```
---
```c
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
```
---
```c
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
```
---
```c
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
```
---
```c
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
```
---
```c
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
```
---

## 11.7 선택 정렬(Selection Sort) 문제 풀이

아래에 설명 된 정렬 알고리즘을 코드로 구현해보자⭐️
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

\*
    Selection Sort Algorithm
    https://www.geeksforgeeks.org/selection-sort/

    Youtube search "Selection Sort", "CS50"

    64 25 12 22 11	(min_idx = 0)
       64			(min_idx = 0)
       25			(min_idx = 1)
          25		(min_idx = 1)
    	  12		(min_idx = 2)
    	     12 	(min_idx = 2)
    		    12	(min_idx = 2)
    			11	(min_idx = 4)
    11 25 12 22 64	(swap arr[0] and arr[4])	// min index를 찾은 후에 swap(가장 작은 수와 가장 큰 수 자리 교체)

    11 25 12 22 64	(min_idx = 1)	// index 1부터 다시 비교 시작
          25		(min_idx = 1)
    	  12		(min_idx = 2)
    	     12 	(min_idx = 2)
    		    12	(min_idx = 2)
    11 12 25 22 64	(swap arr[1] and arr[2])

    11 12 25 22 64	(min_idx = 2)
    ...

    11 12 22 25 64	(min_idx = 3)
    ...

*/

/*
    알고리즘 이해할 때 추가자료 보는 게 좋다.
*/

void swap(int* xp, int* yp); //
void printArray(int arr[], int size); // 출력
void selectionSort(int arr[], int n); // 가장 중요

int main() {

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);	// ascending order

    printArray(arr, n);

    return 0;
}

// 원활한 진행을 위해 함수들의 일부를 보여줌

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	//TODO: fill blank(s)
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		//TODO: fill blank(s)
    	}

    	// Swap the found minimum element with the first element
    	//TODO: fill blank(s)
    }
}
```
---

※ 내 코드
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* xp, int* yp); //
void printArray(int arr[], int size); // 출력
void selectionSort(int arr[], int n); // 가장 중요

int main() {

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);	// ascending order

    printArray(arr, n);

    return 0;

}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		if (arr[min_idx] > arr[j])
    			min_idx = j;
    	}
    	// Swap the found minimum element with the first element
    	swap(&arr[i], &arr[min_idx]);
    }
}

/*
    알고리즘 구현하기 전에 어려울줄 알고 매우 쫄았었는데
    막상 풀어보니 매우 간단하다.
    물론 이번에 거의 다 힌트였지만 다음부터 쫄지말고 실행하자.
*/

※ 교수님 코드(거의 동일)
```c
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		if (arr[j] < arr[min_idx])
    			min_idx = j;
    	}
    	// Swap the found minimum element with the first element
    	swap(&arr[min_idx], &arr[i]);
    }
}
```
---

## 11.8 문자열의 포인터를 정렬하기
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;
}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/
```
문자열 정렬 해보자

---

※ 내 코드
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;

}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/

void printStringArray(char* arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%s\n", arr[i]);
    /*
        printf("%s\n", *arr[i]); // %s 인가 %c인가? %s는 왜 warning이 뜨는가?
        printf("%s\n", arr[i]); // *을 제거하니 제대로 출력된다.(포인터 개념 부족)⭐
    */
    printf("\n");
}

void swap(char** xp, char** yp) {
    char *temp = *xp; // 여기 char로 두면 안 되나? > 된다.
    *xp = *yp;
    _yp = temp;
    /*
        char temp를 char _temp로 바꾸니까 된다.
        https://stackoverflow.com/questions/3816233/swapping-two-string-pointers
        이중포인터 개념 복습하자⭐
    */
}

void selectionSort(char\* arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
    	min_idx = i;
    	for (j = i + 1; j < n; j++)
    	{
    		if (strcmp(arr[min_idx], arr[j]) == 1) {
    			min_idx = j;
    		}
    	}
    	swap(&arr[min_idx], &arr[i]);
    }
}
```
※ 교수님 코드
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;

}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/

void printStringArray(char\* arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    puts(arr[i]);
    printf("\n");
}

void swap(char** xp, char** yp) {
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(char\* arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++)
    	{
    		if (strcmp(arr[j], arr[min_idx]) < 0)	// 부호에 따라 오름차순, 내림차순 정렬 정할 수 있다.
    			min_idx = j;
    	}

    	// Swap the found minimum element with the first element(이중포인터 사용하지 않고 구현 가능)⭐
    	/*char* temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;*/
    	swap(&arr[min_idx], &arr[i]);
    }

}
```
---

## 11.9 문자 함수(ctype.h)를 문자열에 사용하기
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h> // toupper(), ispunct(), ...

#define NUM_LIMIT 1024

void ToUpper(char*); // 대문자로 바꿔줌
int PunctCount(const char*); // 기호가 몇 개인지 세줌

int main() {

    char line[NUM_LIMIT];
    char* new_line = NULL;
    fgets(line, NUM_LIMIT, stdin);
    new_line = strchr(line, '\n');	// find first newline
    /*
    	strchr이 '\n'이 나타나는 첫번째 포인터를 return 해준다.
    	그리고 그걸 밑에서 '\0'로 바꿔준다.
    */
    if (new_line)
    	* new_line = '\0';

    ToUpper(line);
    puts(line);
    printf("%d\n", PunctCount(line));

    return 0;
}

void ToUpper(char* str) // 문자열을 받기 위해서 문자의 포인터를 받음
{
    /*
    c코드를 볼 때, char(문자) type에 대한 포인터가 parameter로 사용되고 있다면
    대부분의 경우 문자에 대한 포인터라긴 보다 "문자열"을 받기 위해 사용되고 있다고 보면 된다.⭐
    */
    while (*str) {
        *str = toupper(*str);
        /* 코드를 좀 더 자세하게 만들고 싶다면(소문자인지 확인하고 대문자로 바꾸기)(퍼포먼스 아주 중요하다면)
        if (islower(*str))
        * str = toupper(*str);
        예전에는 이렇게 했지만 이제는 toupper()함수 안에 이런 기능이 있다.*/
        str++;
    }
}

int PunctCount(const char* str) {
int ct = 0;
while (*str) {
if (ispunct(\*str))
ct++;
str++;
}

    return ct;
}
```
---

## 11.10 명령줄 인수(Command-Line Arguments)
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char _ argv[]) // char pointer array의 용도는 문자열의 배열
/*
    arguments에 어떻게 넣을까?
    프로그램을 실행할 때 프로그래머나 사용자가 넣을 수 있다.
    command prompt에 입력
*/
{

    int count;

    printf("The command line has %d arguments:\n", argc);

    for (count = 0; count < argc; count++)
    	printf("Arg %d : %s\n", count, argv[count]);
    printf("\n");

    return 0;
}
```
---

command line에서 실행한 내용

---

** Visual Studio 2019 Developer Command Prompt v16.8.4
** Copyright (c) 2020 Microsoft Corporation

---

D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe
The command line has 1 arguments:
Arg 0 : D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe

D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe hello world 1234 3.14
The command line has 5 arguments:
Arg 0 : D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe
Arg 1 : hello
Arg 2 : world
Arg 3 : 1234
Arg 4 : 3.14

D:\dev\repository\C\Chapter_3\Chapter_3>

---

## 11.11 문자열을 숫자로 바꾸는 방법들
```c
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
```
In command line
D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe 3 hello
hello
hello
hello

---
```c
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
```
In command line
D:\dev\repository\C\Chapter_3\Chapter_3>D:\dev\repository\C\Chapter_3\Chapter_3\Debug\Lecture_3_6.exe 10 21
Sum = 31

---

좀 더 일반적인 경우(8진수, 16진수)
```c
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
```
---

숫자에서 문자로
```c
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
```
---
