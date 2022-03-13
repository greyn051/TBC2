/*
## 11.1 문자열(Strings)을 정의하는 방법
*/

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
