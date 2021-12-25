/*
## 8.6 입력 확인하기
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return 0;
}


/*********************************************************
*********************************************************/

/*
여기서 숫자인지 확인하고
또 0이상 100이하인지 확인하는 프로그램으로 확장하기
(위 코드 재활용해야한다) > 함수로 만들기
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long get_long(void);

int main() {

    printf("Please input a integer between 1 and 100.\n"); // between은 1과 100을 포함하지 않음

    long number = get_long(); // 사용자가 정수를 입력할 때 까지 계속해서 받음

    if (number > 1 && number < 100) // between 1 and 100
    	printf("OK. Thank you.\n");
    else
    	printf("Wrong input.\n");

    return 0;
}

long get_long(void) {

    printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}

// 여기서 1~100 사이를 초과했을 때 어떻게 처리할까?

// ※ 교수님 코드

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long get_long(void);

int main() {

    long number;

    while (1) {
    printf("Please input a integer between 1 and 100.\n"); // between은 1과 100을 포함하지 않음

    number = get_long(); // 사용자가 정수를 입력할 때 까지 계속해서 받음

    if (number > 1 && number < 100) // between 1 and 100
    {
    	printf("OK. Thank you.\n");
    	break;
    }
    else
    	printf("Wrong input. Please try again.\n");
    }

    printf("Your input %d is between 1 and 100. Thank you.\n", number);

    return 0;
}

long get_long(void) {

    printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}
