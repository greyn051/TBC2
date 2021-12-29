/*
## 8.8 메뉴 만들기 예제 \* retry!
*/

// 예제를 보고 처음부터 끝까지 구현해봐

/*
※ 내 코드
(망한 코드)
(getchar 사용법 연습하자!\*)
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    char input = 0;
    int i = 0;

    while (1) {

    printf("Enter the letter of your choice:\n");
    printf("a. avengers		b. beep\n");
    printf("c. count        q. quit\n");
    scanf("%c", &input);

    if (input == 'a') {
    	printf("Avengers assemble!\n");
    }
    else if (input == 'b') {
    	printf("\b\n");
    }
    else if (input == 'c') {
    	printf("Enter an integer : \n");
    	scanf("%d", &i);
    	for (int j = 1; j <= i; ++j) {
    		printf("%d\n", j);
    	}
    }
    else if (input == 'q')
    	break;
    else {
    	printf("Please type word only in this menu.\n");
    }
    }

    return 0;
}

/*
일부 힌트보기(구조만)
예제에 메뉴와 다른 문자를 입력하면 다시 입력하라 나와야함
*/

// ※ 내 코드(힌트 봐도 대참사)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);

int main() {

    int user_choice;

    while ((user_choice = get_choice()) != 'q') {
    	switch (user_choice) {
    	case 'a':
    		printf("Avengers assemble!\n");
    		break;
    	case 'b':
    		putchar('\a'); //Beep
    		break;
    	case 'c':
    		count();
    		break;
    	//default :
    	//	printf("Error with %d.\n", user_choice);
    	//	exit(1); // 개발과정에서 실행이 되면 절대 안 되는 코드를 바로 나가게 한다면 디버깅 할 때 시간을 아낄 수 있다.(명확하게 오류 발견)(but 실제는 빼야함)
    	//	break;
    	}

    }

    return 0;
}

char get_choice(void) {
char input;

    printf("Enter the letter of your choice:\n");
    printf("a. avengers		b. beep\n");
    printf("c. count        q. quit\n");

    scanf("%c", &input);

    return input;
}

char get_first_char(void) {

}

int get_integer(void) {

}

void count(void) {
int i = 0;

    printf("Enter an integer : \n");
    scanf("%d", &i);

    for (int j = 1; j <= i; ++j) {
    	printf("%d\n", j);
    }
}

// ※ 교수님 코드
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

char get_choice(void);
char get_first_char(void);
int get_integer(void);
void count(void);

int main() {

    int user_choice;

    while ((user_choice = get_choice()) != 'q') {
    	switch (user_choice) {
    	case 'a':
    		printf("Avengers assemble!\n");
    		break;
    	case 'b':
    		putchar('\a'); //Beep
    		break;
    	case 'c':
    		count();
    		break;
    	default :
    		printf("Error with %d.\n", user_choice);
    		exit(1); // 개발과정에서 실행이 되면 절대 안 되는 코드를 바로 나가게 한다면 디버깅 할 때 시간을 아낄 수 있다.(명확하게 오류 발견)(but 실제는 빼야함)
    		break;
    	}

    }

    return 0;
}

void count(void) {

    int n, i;

    printf("Enter an integer:\n");
    n = get_integer();
    for (i = 1; i <= n; ++i)
    	printf("%d\n", i);
    while (getchar() != '\n')
    	continue;
}

char get_choice(void) {
char user_input;

    printf("Enter the letter of your choice:\n");
    printf("a. avengers\tb. beep\n");	// 메뉴 줄 맞춤 \t 사용
    printf("c. count\tq. quit\n");

    user_input = get_first_char();

    //while ((user_input < 'a' || user_input > 'c') && user_input != 'q')
    while ((user_input != 'a' || user_input != 'c') && user_input != 'c' && user_input != 'q')
    //while (!(user_input == 'a' || user_input == 'b' || user_input == 'c' || user_input == 'q'))
    {
    	printf("Please try again.\n");
    	user_input = get_first_char();
    }

    return user_input;
}

char get_first_char(void) {

    int ch;

    ch = getchar();
    while (getchar() != '\n')
    	continue;

    return ch;
}

int get_integer(void) {

    int input;
    char c;

    while (scanf("%d", &input) != 1) {

    	while ((c = getchar()) != '\n')
    		putchar(c);
    	printf(" is not an integer. \nPlease try again.");
    }

    return input;
}
