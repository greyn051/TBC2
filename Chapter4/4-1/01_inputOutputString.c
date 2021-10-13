#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	char fruit_name; // stores only one character.

	printf("What is your favorate fruit?\n");

	scanf("%c", &fruit_name); // be careful with &

	printf("You like %c!\n", fruit_name);

	return 0;
}

/*
위와 같이 하고 Banana 입력하면
You like B!
이래 뜸
*/

/*********************************************************
*********************************************************/

/*
배열을 사용하자 > name[40], %s
*/

int main() {

	char fruit_name[40]; // stores only one character.

	printf("What is your favorate fruit?\n");

	scanf("%s", fruit_name); // be careful with &

	printf("You like %s!\n", fruit_name);

	return 0;
}
