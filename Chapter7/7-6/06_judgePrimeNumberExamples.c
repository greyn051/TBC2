/*
## 7.6 소수 판단 예제
*/

/*
소수인지 아닌지 판별하는 프로그램 만드는 예제
prime number : 소수
*/

// ※ 내가 한 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {

    unsigned num;
    bool isPrime = 0; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    if (num == 2) {
    	isPrime = 1;
    }

    for (unsigned i = 2; i < num; ++i) {
    	if (num % i == 0) {
    		isPrime = 0;
    		break;
    	}
    	else {
    		isPrime = 1;
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;
}


// ※ 교수님 코드
int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; div < num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;
}


/*********************************************************
*********************************************************/


// 위 프로그램을 좀 더 업그레이드해서 약수까지 찾게 만들기

int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; div < num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;
    		printf("%u is divisible by %u.\n", num, div);
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;
}


/*********************************************************
*********************************************************/


/*
중복되는 약수 줄이기
ex) 2로 나누어지면 4나 8로도 나누어진다고 출력x
*/

int main() {

    unsigned num, div;
    bool isPrime; // flag, try bool type // 상태 판별할 때 사용(보통 int쓰지만 bool을 쓰는 것도 좋음)

    scanf("%u", &num);

    /*
    	TODO: Check if num is a prime number
    	ex) num is 4, try num % 2, num % 3
    	ex) num is 5, try num % 2, num % 3, num % 4
    */

    isPrime = true;

    for (div = 2; (div*div) <= num; ++div) {
    	if (num % div == 0) {
    		isPrime = false;

    		if (num == div * div)
    			printf("%u is divisible by %u.\n", num, div);
    		else
    			printf("%u is divisible by %u and %u.\n", num, div, num/div);
    	}
    }

    if (isPrime)
    	printf("%u is a prime number.\n", num);
    else
    	printf("%u is not a prime number.\n", num);

    return 0;
}
