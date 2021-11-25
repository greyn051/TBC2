/*
## 7.8 단어 세기 예제
*/

/*
ex) 입력 받은 문장에서 단어가 몇 개인지 세는 프로그램
characters
words
line
개수 다 나오게
.를 입력하면 개수 출력 후 종료
*/

/*
※ 내가 한 코드 1
(내가 작성했지만 참 주먹구구식이다..)
(bool 언제 쓸지 몰라서 안 씀)
(첫 번째 힌트만 보고 작성)
(작동은 됨)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> // islower()
#include <stdbool.h>

#define STOP '.'

int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 1;
    int n_words = 1;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {

    	if (c != ' ' && c != '\n') {
    		n_chars++;
    	}
    	else if (c == '\n') {
    		n_lines++;
    	}
    	else if (c == ' ') {
    		n_words++;
    	}
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;
}


/*********************************************************
*********************************************************/


/*
※ 내가 한 코드 2
(두 번째 힌트 본 후 작성)
*/
#define STOP '.'

int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 0;
    int n_words = 0;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {
    	if (!isspace(c))	// 빈칸이 아니라면 (isspace(c) == false)도 가능(실수 줄이기) !isspace처럼 간결한 것이 c코딩 스타일(컴퓨터에게 인간을 맞춰주기 위해 주의력을 기르자!)
    		n_chars++;	// count non-space characters

    	if (!isspace(c) && !line_flag) {
    		n_lines++;
    		line_flag = true;
    	}

    	if (c == '\n') {
    		line_flag = false;
    		word_flag = false; // 이건 내가 추가
    	}

    	// 위에 힌트 이용해서 words 구현

    	if (!isspace(c) && !word_flag) {
    		n_words++;
    		word_flag = true;
    	}

    	if (c == ' ')
    		word_flag = false;
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;
}


/*********************************************************
*********************************************************/


// ※ 교수님 코드
int main() {

    char c;
    int n_chars = 0;	// number of non-space characters
    int n_lines = 0;
    int n_words = 0;
    bool word_flag = false;
    bool line_flag = false;

    printf("Enter text : \n");

    while ((c = getchar()) != STOP) {
    	if (!isspace(c))
    		n_chars++;

    	if (!isspace(c) && !line_flag) {
    		n_lines++;
    		line_flag = true;
    	}

    	if (c == '\n') {
    		line_flag = false;
    	}

    	if (!isspace(c) && !word_flag) {
    		n_words++;
    		word_flag = true;
    	}

    	if (isspace(c))
    		word_flag = false;
    }

    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);

    return 0;
}
