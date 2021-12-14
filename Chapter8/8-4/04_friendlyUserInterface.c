/*
## 8.4 사용자 인터페이스는 친절하게
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    int count = 0;

    while (1) {
    	printf("Current count is %d. Continue? (y/n)\n", count);

    	if (getchar() == 'n')
    		break;

    	while (getchar() != '\n')
    		continue;

    	count++;
    }

    return 0;
}


/*
Current count is 0. Continue? (y/n)
y
Current count is 1. Continue? (y/n)
y
Current count is 2. Continue? (y/n)
yes
Current count is 3. Continue? (y/n)
n
끝

Current count is 0. Continue? (y/n)
dont
Current count is 1. Continue? (y/n)
cant
Current count is 2. Continue? (y/n)
what
Current count is 3. Continue? (y/n)
the
Current count is 4. Continue? (y/n)
*/

// 사용자는 예측하기 어렵다.


/*********************************************************
*********************************************************/


// 좀 더 꼼꼼하게 만들기

int main() {

    int count = 0;

    while (1) {
    	printf("Current count is %d. Continue? (y/n)\n", count);

    	int c = getchar();

    	if (c == 'n')
    		break;
    	else if (c == 'y')
    	{
    		while (getchar() != '\n')
    			continue;

    		count++;
    	}
    	else {
    		printf("Please input y or n\n");

    		while (getchar() != '\n')
    			continue;
    	}
    }

    return 0;
}


// 위에 중복되는 것을 아래와 같이 바꿀 수 있다.

int main() {

    int count = 0;

    while (1) {
    	printf("Current count is %d. Continue? (y/n)\n", count);

    	int c = getchar();

    	if (c == 'n')
    		break;
    	else if (c == 'y')
    		count++;
    	else
    		printf("Please input y or n\n");

    		while (getchar() != '\n')
    			continue;

    }

    return 0;
}
