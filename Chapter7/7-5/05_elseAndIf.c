/*
## 7.5 else와 if 짝짓기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int number;
    scanf("%d", &number);

    if (number == 1)
    	printf("One");
    else if (number == 2)
    	printf("Two");
    else if (number == 3)
    	printf("Three");

    return 0;
}


/*********************************************************
*********************************************************/


int main() {

    int number;
    scanf("%d", &number);

    if (number == 1)
    	printf("One");
    else
    	if (number == 2)
    		printf("Two");
    	else
    		if (number == 3)
    			printf("Three");

    // minimun 127 levels of nestings

    return 0;
}


/*********************************************************
*********************************************************/


// 컴파일러는 인덴팅 무시함

int main() {

    int number;
    scanf("%d", &number);

    if (number > 5)
    	if (number < 10)
    		printf("Larger than 5 smaller than 10\n");
    else
    	printf("Less than or equal to 5");
    /*	else
    		printf("Less than or equal to 5"); */

    // Compilers ignore indenting

    return 0;
}

/*
밑 if에 else가 적용된다.
⭐else는 가까이 있는 if에 적용된다.
*/

/*********************************************************
*********************************************************/

/*
위 if에 else 붙이고 싶다면
⭐헷갈릴 여지가 있는 경우 중괄호{}를 쳐라
*/

int main() {

    int number;
    scanf("%d", &number);

    if (number > 5)
    {
    	if (number < 10)
    		printf("Larger than 5 smaller than 10\n");
    	else
    		printf("Larger 10\n");
    }
    else
    	printf("Less than or equal to 5");

    return 0;
}
