/*
## 9.1 함수가 필요할 때
*/

/*
이름, 사는 곳이 적힌 명함을 출력하는 프로그램 만들기
별은 20개
이름과 주소는 가운데 출력
*/

// 초보는 이렇게 한다
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	printf("********************\n");
	printf("Name\n");
	printf("Adress\n");
	printf("********************\n");

	return 0;
}


/*********************************************************
*********************************************************/


// 2개 이상 반복하면 함수로

#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	20
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_bar(int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("*");
	printf("\n");

	//printf("********************\n");
}

int main() {

	print_bar(WIDTH);

	printf("   %s\n", NAME);
	printf("   %s\n", ADDRESS);

	print_bar(WIDTH);

	return 0;
}


/*********************************************************
*********************************************************/


// 별의 개수가 변해도 가운데에 위치하도록 코드 수정하기

// 😃내 코드
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	30
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_bar(int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("*");
	printf("\n");

	//printf("********************\n");
}

void justify(int n_stars) {
	for (int i = 0; i < ((n_stars / 2) - 7); ++i)
		printf(" ");
}

int main() {

	print_bar(WIDTH);

	justify(WIDTH);
	printf("%s\n", NAME);

	justify(WIDTH);
	printf("%s\n", ADDRESS);

	print_bar(WIDTH);

	return 0;
}

// 😎 교수님 코드
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	30
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)
}

int main() {

	int n_blanks = 0;

	print_multiple_chars('*', WIDTH);
	printf("\n");

	n_blanks = (WIDTH - strlen(NAME)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", NAME);

	n_blanks = (WIDTH - strlen(ADDRESS)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", ADDRESS);

	print_multiple_chars('*', WIDTH);

	return 0;
}


/*********************************************************
*********************************************************/


// 위 함수에서 빈칸 생성하는 코드가 중복되니 함수로 바꿔봐

// 함수에 문자열을 어떻게 받지?

// 😎교수님 코드
#include <stdio.h>
#include <string.h> // strlen()

#define WIDTH	25
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)
}

void print_centered_str(char str[])		// width가 코드 전체에서 접근할 수 있으므로 여기선 따로 안 넣어도 됨
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks);
	printf("%s\n", str);
}

int main() {

	print_multiple_chars('*', WIDTH);
	printf("\n");		// 이거 거슬리면 위에 함수 print_multiple_chars('*', WIDTH, '\n'); 이런 식으로 입력하면 뒤에 추가하도록 바꿀 수도 있음

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH);

	return 0;
}


// str[] 이용해서 문자열을 받는다.


/*********************************************************
*********************************************************/


// 위에 printf("\n"); 없애고 깔끔하게 만들어 보자

#include <stdio.h>
#include <string.h> // strlen()
#include <stdbool.h>

#define WIDTH	25
#define NAME	"Jeong-Mo Hong"
#define ADDRESS	"Seoul, Korea"

void print_multiple_chars(char c, int n_stars, bool print_newline) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);	// putchar(c)

	if (print_newline)
		printf("\n");
}

void print_centered_str(char str[])		// width가 코드 전체에서 접근할 수 있으므로 여기선 따로 안 넣어도 됨
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}

int main() {

	print_multiple_chars('*', WIDTH, true);

	print_centered_str(NAME);
	print_centered_str(ADDRESS);
	print_centered_str("I love you");

	print_multiple_chars('*', WIDTH, false);

	return 0;
}
