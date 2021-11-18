/*
## 7.1 분기문 if
*/

/*
ex)
TODO: print even or odd
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int number;

	printf("Input a positive integer : ");
	scanf("%d", &number);

	//TODO: print even or odd

	if (number % 2 == 0)
		printf("Even");

	if (number % 2 != 0)
		printf("Odd");

	return 0;
}

// if else문 써보자
int main() {

	int number;

	printf("Input a positive integer : ");
	scanf("%d", &number);

	//TODO: print even or odd

	if (number % 2 == 0)
		printf("Even");
	else // if (number % 2 != 0)
		printf("Odd");

	return 0;
}
