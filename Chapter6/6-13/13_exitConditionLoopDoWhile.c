/*
## 6.13 탈출조건 루프(Exit-Condition Loop) do while
*/

/*
비밀번호를 미리 설정해 놓고 그 비밀번호를 여러번 쳐서
알맞는 숫자를 입력하면 끝나는 프로그램 만들어보자
*/

// ※ 내 코드

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    const unsigned int secret_code = 337;
    unsigned int input = 0;

    while (input != secret_code) {
    	printf("Enter secret code : ");
    	scanf("%d", &input);
    }
    printf("Good!");

    return 0;
}


// ※ 교수님 코드

int main() {

    const int secret_code = 337;
    int guess = 0;

    printf("Enter secret code : ");
    scanf("%d", &guess);

    while (guess != secret_code) {
    	printf("Enter secret code : ");
    	scanf("%d", &guess);
    }

    printf("Good!");

    return 0;
}


/*
똑같은 코드를 while 이전에 무조건 한 번 해야하는 경우
중복된 코드를 줄이기 위해서 do while문을 사용
*/

int main() {

    const int secret_code = 337;
    int guess = 0;

    do {
    	printf("Enter secret code : ");
    	scanf("%d", &guess);
    }
    while (guess != secret_code);

    printf("Good!");

    return 0;
}

// 동일하게 작동하지만 훨씬 간결하다.
