# TBC-8 문자 입출력과 입력 유효성 검증

## 8.1 입출력 버퍼

gethchar(), putchar()는 분명 한 글자씩 입력을 받고 있는데
마치 작동하는 것은 덩어리처럼 한 번에 보낸다.

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h> // Windows, _getch(), _getche()

int main() {

	char c;

	while ((c = getchar()) != '.')
		putchar(c);

	return 0;
}
```

//
버퍼 작동하지 않는 경우

```c
#include <stdio.h>
#include <conio.h> // Windows, _getch(), _getche() // 버퍼 사용x

int main() {

	char c;

	while ((c = _getche()) != '.') // e는 echo의 약자, _getch를 쓰면 입력한거 출력x
		putchar(c);

	return 0;
}
```

//

## 8.2 파일의 끝

EOF

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    char c;

    while ((c = getchar()) != EOF) // End Of File
    	putchar(c);

    return 0;
}
```

//
과연 들어온게 EOF 맞는지 확인

```c
int main() {

    char c;

    while ((c = getchar()) != EOF) // End Of File
    	putchar(c);

    while (1) {
    	c = getchar();
    	printf("%d\n", c);
    	if (C == EOF)
    		break;
    }

    return 0;
}
```

//

## 8.3 입출력 방향 재지정(Redirection)

출력 redirection

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    printf("I love apple.\n");

    return 0;
}
```

```
D:\>cd D:\dev\repository\C\Chapter_3\Chapter_3\Debug

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>dir
D 드라이브의 볼륨: 새 볼륨
볼륨 일련 번호: 0C27-6DC3

D:\dev\repository\C\Chapter_3\Chapter_3\Debug 디렉터리

2021-01-28 오후 05:13 <DIR> .
2021-01-28 오후 05:13 <DIR> ..
2021-02-01 오전 11:35 39,936 Lecture_3_6.exe
2021-02-01 오전 11:35 642,772 Lecture_3_6.ilk
2021-02-01 오전 11:35 593,920 Lecture_3_6.pdb
3개 파일 1,276,628 바이트
2개 디렉터리 207,875,551,232 바이트 남음

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture3_6.exe
'Lecture3_6.exe'은(는) 내부 또는 외부 명령, 실행할 수 있는 프로그램, 또는
배치 파일이 아닙니다.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6.exe
I love apple.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6.exe > output.txt

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>output.txt

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>explorer .

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>notepad output.txt
```

//
입력 redirection

```c
int main() {

    char str[100];
    scanf("%s", str);
    printf("I love %s\n", str);

    return 0;
}
```

```
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6 < input.txt
I love Melon.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6<input.txt>output.txt
```

//
기존 output에 내용 추가

```
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>Lecture_3_6>>output.txt
Banana
```

//
좀 더 복잡하게

test.exe의 결과가
Lecture3.exe로 파이프를 통해 흘러가게 하기

- test.exe

```c
  int main() {

      printf("Programming");

      return 0;
  }
```

- Lecture_3_6.exe

```c
  int main() {

      char str[100];
      scanf("%s", str);
      printf("I love %s\n", str);

      return 0;
  }
```

```
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>copy Lecture_3_6.exe test.exe
1개 파일이 복사되었습니다.

D:\dev\repository\C\Chapter_3\Chapter_3\Debug>test.exe
Programming
D:\dev\repository\C\Chapter_3\Chapter_3\Debug>test.exe | Lecture_3_6.exe
I love Programming
```

//

## 8.4 사용자 인터페이스는 친절하게

```c
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
```

```
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
```

사용자는 예측하기 어렵다.

//
좀 더 꼼꼼하게 만들기

```c
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
```

// 위에 중복되는 것을 아래와 같이 바꿀 수 있다.

```c
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
```

//

## 8.5 숫자와 문자를 섞어서 입력 받기

A 3 2를 입력하면
AA
AA
AA
이렇게 출력하는 프로그램 완성하기

※ 내 코드

```c
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
```

※ 교수님 코드

```c
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
```

getchar와 scanf를 섞어서 문자와 숫자를 따로따로 입력받아 보았다.
//

## 8.6 입력 확인하기

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return 0;
}
```

//

여기서 숫자인지 확인하고
또 0이상 100이하인지 확인하는 프로그램으로 확장하기
(위 코드 재활용해야한다) > 함수로 만들기

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long get_long(void);

int main() {

    printf("Please input a integer between 1 and 100.\n"); // between은 1과 100을 포함하지 않음

    long number = get_long(); // 사용자가 정수를 입력할 때 까지 계속해서 받음

    if (number > 1 && number < 100) // between 1 and 100
    	printf("OK. Thank you.\n");
    else
    	printf("Wrong input.\n");

    return 0;
}

long get_long(void) {

    printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}
```

// 여기서 1~100 사이를 초과했을 때 어떻게 처리할까?

※ 교수님 코드

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long get_long(void);

int main() {

    long number;

    while (1) {
    printf("Please input a integer between 1 and 100.\n"); // between은 1과 100을 포함하지 않음

    number = get_long(); // 사용자가 정수를 입력할 때 까지 계속해서 받음

    if (number > 1 && number < 100) // between 1 and 100
    {
    	printf("OK. Thank you.\n");
    	break;
    }
    else
    	printf("Wrong input. Please try again.\n");
    }

    printf("Your input %d is between 1 and 100. Thank you.\n", number);

    return 0;
}

long get_long(void) {

    printf("Please input an integer and press enter.\n");

    long input;		// 숫자가 큰 정수가 들어올 수 있어서 long
    char c;

    while (scanf("%ld", &input) != 1) {
    	printf("Your input - ");

    	while ((c = getchar()) != '\n')
    		putchar(c); // input left in buffer

    	printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}
```

//

## 8.7 입력 스트림과 숫자

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    /*
    Assume that your input is :
    Hello 123 3.14
    */

    char str[255];
    int i, i2;
    double d;

    scanf("%s %d %lf", str, &i, &d);
    printf("%s %d %f\n", str, i, d);

    // or (see the difference)

    scanf("%s %d %lf", str, &i, &d);
    printf("%s %d %f\n", str, i, d);

    // or (see the difference)

    char c;
    while ((c = getchar()) != '\n')
    	putchar(c);
    printf("\n");

    return 0;
}
```

//

## 8.8 메뉴 만들기 예제 \* retry!

예제를 보고 처음부터 끝까지 구현해봐
※ 내 코드
(망한 코드)
(getchar 사용법 연습하자!\*)

```c
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
```

일부 힌트보기(구조만)
예제에 메뉴와 다른 문자를 입력하면 다시 입력하라 나와야함
※ 내 코드(힌트 봐도 대참사)

```c
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
```

※ 교수님 코드

```c
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
```

//

## 8.9 텍스트 파일 읽기

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // exit()

int main() {

    int c;
    FILE* file = NULL;
    char file_name[] = "my_file.txt"; //TODO: use scanf(...)

    file = fopen(file_name, "r"); // read or write
    if (file == NULL) {
    	printf("Failed to open file.\n");
    	exit(1);
    }

    while ((c = getc(file)) != EOF)
    	putchar(c);
    fclose(file);

    return 0;
}
```

텍스트 파일을 읽어들이는 기본적인 방법
//
