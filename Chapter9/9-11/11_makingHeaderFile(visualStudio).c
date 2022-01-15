/*
## 9.11 헤더 파일(Header Files) 만들기 (비주얼 스튜디오)
*/

// <my_print_functions.h>
#pragma once // header guard

#include <stdio.h>

void print_hello() {

    printf("Hello\n");
    // many more lines

}

void print_hi() {

    printf("Hi\n");
    // many more lines

}

void print_str(char\* str) {

    printf("%s\n", str);

}

// assume that we have many more longer functions

// <main.c>
#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h> // 이미 "my_print_functions.h"에서 선언해줘서 없어도 됨
#include "my_print_functions.h"

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}


/*********************************************************
*********************************************************/


/*
헤더파일에는 선언만 남긴다
(헤더 파일과 이름이 같은 c파일 만들어서 정의를 그곳으로 옮긴다)
*/

// <my_print_functions.h>
#pragma once // header guard

#include <stdio.h>

void print_hello();
void print_hi();
void print_str(char\* str);

// assume that we have many more longer functions

// <my_print_functions.c>
#include "my_print_functions.h"

void print_hello() {

    printf("Hello\n");
    // many more lines
}

void print_hi() {

    printf("Hi\n");
    // many more lines
}

void print_str(char\* str) {

    printf("%s\n", str);
}

// <main.c>
#define _CRT_SECURE_NO_WARNINGS

#include "my_print_functions.h"

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}


/*********************************************************
*********************************************************/


/*
엄격하게 할려면 헤더파일에 stdio.h를 c파일로 옮긴다.
그러면 main.c에서 막히는데 다시 선언해줘야한다.
*/

// <my_print_functions.h>
#pragma once // header guard

void print_hello();
void print_hi();
void print_str(char\* str);

// assume that we have many more longer functions

// <my_print_functions.c>
#include "my_print_functions.h"

#include <stdio.h>

void print_hello() {

    printf("Hello\n");
    // many more lines

}

void print_hi() {

    printf("Hi\n");
    // many more lines

}

void print_str(char\* str) {

    printf("%s\n", str);

}

// <main.c>
#define _CRT_SECURE_NO_WARNINGS

#include "my_print_functions.h"
#include <stdio.h>

int main() {

    print_hello();
    print_hi();
    print_hello();
    print_hi();
    print_str("No one lives forever.");
    print_str("Valar morghulis");

    printf("Hellow!");

    return 0;
}

// 근데 현실에서는 크게 중요한 것은 아니다.
