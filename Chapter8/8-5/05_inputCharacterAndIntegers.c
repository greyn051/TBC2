/*
## 8.5 숫자와 문자를 섞어서 입력 받기
*/

/*
A 3 2를 입력하면
AA
AA
AA
이렇게 출력하는 프로그램 완성하기
*/

// ※ 내 코드

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// display 함수 완성하자
void display(char cr, int lines, int width);

int main() {

    char c;
    int rows, cols;

    while (1) {
    	scanf("%c %d %d", &c, &rows, &cols);
    	display(c, rows, cols);
    	if (c == '\n')
    		break;		// doesn't work well
    }

    return 0;
}

void display(char cr, int lines, int width) {

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < width; ++j) {
        printf("%c", cr);
        }
    printf("\n");
    }
}


/*********************************************************
*********************************************************/


// ※ 교수님 코드

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// display 함수 완성하자
void display(char cr, int lines, int width);

int main() {

    char c;
    int rows, cols;

    /*
    while (1) {
    	scanf("%c %d %d", &c, &rows, &cols);
    	while (getchar() != '\n') continue; // scanf 입력시 빈칸이 왕창 출력되는 경우 방지
    	display(c, rows, cols);
    	if (c == '\n')
    		break;		// doesn't work well
    }
    // \n입력하면 종료되게 만들기 어려움 (scanf는 값을 확실히 다 받아야 하므로)
    */

    printf("Input one character and two integers:\n");
    while ((c = getchar()) != '\n') // 줄바꿈하면 종료하고 싶다는 것을 이렇게 쉽게 표현가능
    {
    	scanf("%d %d", &rows, &cols);
    	while (getchar() != '\n') continue; // scanf 입력 후에 buffer에 남아있는 것 깔끔하게 지우기*

    	display(c, rows, cols);
    	printf("Input another character and two integers:\n");
    	printf("Press Enter to quit.\n");
    }

    return 0;
}

void display(char cr, int lines, int width) {

    int row, col;

    for (row = 1; row <= lines; row++) {
    	for (col = 1; col <= width; col++)
    		putchar(cr);
    	putchar('\n');
    }

}

// getchar와 scanf를 섞어서 문자와 숫자를 따로따로 입력받아 보았다.
