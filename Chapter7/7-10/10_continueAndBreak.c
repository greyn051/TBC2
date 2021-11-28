/*
## 7.10 루프 도우미 continue와 break
*/

// continue

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    /* continue */
    for (int i = 0; i < 10; ++i) {
    	if (i == 5)
    		continue;

    	printf("%d ", i);	// i == 5에서 continue가 실행되면 여기 printf 실행 x

    	/*
    	if (i != 5)
    		printf("%d ", i); // 와 기능 같다.
    	*/
    }

    return 0;
}


/*********************************************************
*********************************************************/


// break

int main() {

    /* break */
    for (int i = 0; i < 10; ++i) {
    	if (i == 5)
    		break;

    	printf("%d ", i);
    }

    return 0;
}


/*********************************************************
*********************************************************/


int main() {

    /* while and continue */
    int count = 0;
    while (count < 5) {
    	int c = getchar();
    	if (c == 'a')
    		continue;
    	putchar(c);
    	count++;
    }

    return 0;
}


/*********************************************************
*********************************************************/


int main() {

    /* for and continue */
    for (int count = 0; count < 10; ++count) {
    	int c = getchar();
    	if (c == 'a')
    		continue;
    	putchar(c);
    }

    return 0;
}


/*********************************************************
*********************************************************/


// placeholder

int main() {

    /* continue as a placeholder */
    while (getchar() != '\n')
    	continue;

    return 0;
}


/*********************************************************
*********************************************************/


int main() {

    /* Need to use continue */
    char c;
    while ((c = getchar()) != '\n') {
    	if (c == 'a')
    		continue;
    	putchar(c);

    	//if (c != 'a')
    	//	putchar(c); // 이렇게 바꿔도 기능 동일

    	/*
    		위 2가지는 관점이 다르다. 늬앙스가 다르다.
    		(cotinue를 쓸 수도 안 쓸 수도 있다.)
    		밑이 간결하다.
    		하지만 나중에 실무에 가서 복잡한 코드를 작성하거나 유지보수할 때
    		continue를 사용하는 것이 좋다.
    	*/
    }

    return 0;
}


/*********************************************************
*********************************************************/


// ⭐while(1), break

int main() {

    /* break */
    char c;

    /*
    while ((c = getchar()) != '.') {
    	putchar(c);
    }
    같은 것을 아래와 같이 break를 이용해서 구현 가능
    */

    while (1) {
    	char c = getchar();

    	if (c == '.')
    		break;

    	putchar(c);
    } // 이렇게 구현하는 형태가 더 많다.
    // 이해하기 쉽다. ~하는데 ~할 때 그만둬!

    /*
    	while문의 조건에다가 기능을 수행하는 조건을 같이 넣으면
    	한 부분에 여러가지 기능(반복위해 비교, 글자 입력)을 같이
    	수행하기 때문에 헷갈릴 가능성이 높다.
    	(한 곳에 한 가지 기능을 수행하게 하는 것이 좋다.)
    */

    return 0;
}


/*********************************************************
*********************************************************/


// 다중 루프에서 break

int main() {

    for (int i = 0; i < 10; i++) {
    	for (int j = 0; j < 10; j++) {
    		if (j == 5)
    			break;

    		printf("(%d %d)", i, j);
    	}
    	printf("\n");
    }

    return 0;
}
