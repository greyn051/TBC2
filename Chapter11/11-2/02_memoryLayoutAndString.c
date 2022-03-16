/*
## 11.2 메모리 레이아웃(Memory Layout)과 문자열
*/

/*
이번
강의의 목표는
char arr[] = "Hello, World";

char\* str = "Hello, World";
//str[0] = 'M'; // ERROR!!!

이 두 가지의 차이를 이해하는 것이다.
*/

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
