/*
## 6.8 for 루프 소개
*/

// while은 indefinite loop를 목적으로 설계

#include <stdio.h>

int main() {
    // Indefinte loop vs. Counting loop
    while (1) {
    // do something
    }

    /*
    	Counting Loop
    	1. Counter initialization
    	2. Counter check
    	3. Counter change
    */

    int i;

    i = 1;

    while (i <= 10)			//Note: <=
    {
    	printf("%d ", i);
    	i++;
    }

    return 0;
}


/*********************************************************
*********************************************************/


/*
counting loop 목적인 for문

위와 같은 기능을 for문으로 구현하자
*/

#include <stdio.h>

int main() {
int i;

    for (i = 1; i <= 10; i++)
    	printf("%d ", i);

    /* or
    for (int i = 1; i <= 10; i++)
    	printf("%d ", i);
    와 같다*/

    return 0;
}


/*********************************************************
*********************************************************/


int main() {
    for (int i = 1; i <= 10; i++) {
    printf("dummy ");
    printf("%d ", i);
    }

    return 0;
}
