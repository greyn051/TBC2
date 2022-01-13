/*
## 9.9 이진수 변환 예제
*/

// 재귀 호출을 이용해서 십진수를 이진수로 변환하는 예제

/*
※ 내 코드
loop에서 printf 역으로 출력하는 방법은 모르겠네
*/
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
	1010(이진수)
*/

long print_binary(unsigned long n);
long print_binary_loop(unsigned long n);

int main() {

    unsigned long number = 10;

    print_binary(number);
    printf("\n");
    print_binary_loop(number);

    return 0;
}

long print_binary(unsigned long n) {
if (n > 0) {

    	print_binary(n / 2);
    }

    if(n != 0)
    	printf("%d", n % 2);

    return 0;
}

long print_binary_loop(unsigned long n) {

    while (n > 0) {

    	printf("%d", n % 2);

    	n = n / 2;
    }

    return 0;
}


/*********************************************************
*********************************************************/


// ※ 교수님 코드
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
	1010(이진수)
*/

long print_binary(unsigned long n);
long print_binary_loop(unsigned long n);

int main() {

    unsigned long num = 10;

    print_binary(num);
    print_binary_loop(num);

    printf("\n");

    return 0;
}

//Note: printing order is reversed!
long print_binary_loop(unsigned long num) {

    while (1) {

    	int quotient = num / 2;
    	int remainder = num % 2;

    	printf("%d", remainder); // remainder is 0 or 1

    	num = quotient;

    	if (num == 0) break;
    }

    printf("\n");
}

long print_binary(unsigned long num) {
/\*if (n > 0) {

    	print_binary(n / 2);
    }

    if(n != 0)
    	printf("%d", n % 2);*/

    int remainder = num % 2;

    if (num >= 2)
    	print_binary(num / 2);

    printf("%d", remainder);

    return;
}
