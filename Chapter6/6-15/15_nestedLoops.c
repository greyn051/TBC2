/*
## 6.15 중첩된(nested) 루프들
*/

/*
ex 1)
원하는 첫글자부터 원하는 마지막 글자까지
원하는 횟수만큼 출력하기.
예를 들어
A B C D E F G H I J K 5줄 쓰는 것 구현하기.
*/

// ※ 내 코드
#include <stdio.h>

int main() {

    int i = 0;
    char c = 'A';
    int num = 5;

    for (i = 0; i < num; i++) {
    	for (c = 'A'; c <= 'K'; c++) {
    		printf("%c ", c);
    	}
    printf("\n");
    }

    return 0;
}


// ※ 교수님 코드
#include <stdio.h>

#define NUM_ROWS 5
#define FIRST_CHAR 'A'
#define LAST_CHAR 'K'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r) // outer row loop
    {
    	for (c = FIRST_CHAR; c <= LAST_CHAR; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}


/*********************************************************
*********************************************************/

/*
ex 2)
A
A B
A B C
...
이런 식으로
원하는 개수만큼 쌓이도록 출력
*/

// ※ 내 코드
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop
    int column = FIRST_CHAR;

    for (r = 0; r < NUM_ROWS; ++r) // outer row loop
    {
    	for (c = FIRST_CHAR; c <= column; ++c)
    		printf("%c ", c);
    	printf("\n");
    	column++;
    }

    return 0;
}


// ※ 교수님 코드
#include <stdio.h>

#define NUM_ROWS 10
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR; c <= FIRST_CHAR + r; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}

/*
outer loop의 변수가
inner loop의 변수에 연결돼 있는 경우가 상당히 많다.
*/


/*********************************************************
*********************************************************/


/*
ex 3)
A B C D E F G H I J K L
B C D E F G H I J K L
C D E F G H I J K L
...
L
처럼 점점 내려가기 구현
*/

// ※ 내 코드
#include <stdio.h>

#define NUM_ROWS 12
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}


// ※ 교수님 코드
#include <stdio.h>

#define NUM_ROWS 12
#define FIRST_CHAR 'A'

int main() {

    int r;// row loop
    int c;// character loop

    for (r = 0; r < NUM_ROWS; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + NUM_ROWS; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}

/*
내가 위 쪽 예제 코드를 기반으로 만들어서 그런지
교수님 코드와 내 코드가 같다.
*/

// or
#include <stdio.h>

#define FIRST_CHAR 'A'

int main() {

    const char last_char = 'L'; //TODO: use scanf()
    const int num_rows = last_char - FIRST_CHAR + 1;

    int r;// row loop
    int c;// character loop

    for (r = 0; r < num_rows; ++r)
    {
    	for (c = FIRST_CHAR + r; c < FIRST_CHAR + num_rows; ++c)
    		printf("%c ", c);
    	printf("\n");
    }

    return 0;
}
/*
이와 같이 const를 쓰는 식으로 만들어도 된다.
scanf를 사용해서 좀 더 interactive하게도 가능
*/
