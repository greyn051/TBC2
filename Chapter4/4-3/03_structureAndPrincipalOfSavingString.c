#include <stdio.h>

int main() {

	int a = 1;
	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);

	printf("%i\n", int_arr[10000]); // 범위 넘어가면 오류 뜸

	return 0;
}

/*********************************************************
*********************************************************/

// 문자의 배열, /0(null)의 역할과 존재이유

int main() {

	char c = 'a';
	char str1[10] = "Hello"; // null character
	char str2[10] = { 'H', 'i' };

	printf("%c\n", c);
	printf("%s\n", str1);
	printf("%s\n", str2);

	pritnf("%hhi %hhi %hhi %hhi %hhi\n",
		str2[0], str2[1], str2[2], str2[3], str2[4]);

	return 0;
}

/*
pritnf는 문자 배열 내부에서 0을 만나면 더 이상 출력 x
str2[2] 이후 부터 모든 값 0
*/

/*********************************************************
*********************************************************/

/*
// 데이터 크기 넘어가는 만큼 저장 x

char str3[20] = "Hello, \0World";
중간에 null charcater 넣으면 이후에 출력 x, 무시당함(printf의 특성)
*/

int main() {

	char str3[10] = "Hello, World"; // array size is not enough
	char str3[20] = "Hello, \0World";
	printf("%s\n", str3);

	return 0;
}
