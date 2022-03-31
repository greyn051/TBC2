/*
## 11.4 문자열을 입력 받는 다양한 방법들
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    /* Creating Space */

    //char* name = ""; // Error at RUN-TIME
    char name[128];
    int result = scanf("%s", name);	// 배열의 이름이 pointer와 비슷하게 작동하므로 앞에 *를 안 붙여줘도 된다.
    /*
    	입력받은 문자열을 저장할 공간을 확보한 다음에 입력을 받아야한다.
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /*
    	scanf() vs gets()
    	scanf() reads one word
    	gets() reads one line and removes \n and add \0
    */

    char words[STRLEN] = "";	// Warning without initialization
    gets(words);		// gets receives pointer. No idea when string ends. (배열의 이름인 포인터만 받아서 어디서 끝나는 지를 모른다. 보완하기 위해서 gets_s 사용)
    //gets_s(words, sizeof(words));		// C11 (최근에 gets_s 사용하기 시작)
    //gets_s(words, STRLEN);
    //int result = scanf("%s", words);
    printf("START\n");
    printf("%s", words);	// no \n at the end
    puts(words);			// puts() adds \n at the end (줄 바꿈 알아서 함)
    puts("END.");

    //TODO: try char words[5];
    /*
    	사이즈가 입력한 값 사이즈보다 작을 때
    	runtime error가 발생한다.
    	이걸 극복하기 위해 fgets(), fputs() 사용
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[5] = "";
    fgets(words, 5, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'

    return 0;
}


/*********************************************************
*********************************************************/


// 디버그하면 words에 \n이 같이 입력되는 걸 확인할 수 있는데 \n을 \0으로 바꿔보자
// TODO: replace '\n' with '\0'

// ※ 내 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    for (int i = 0; i < STRLEN; ++i) {
    	if (words[i] == '\n') {
    		words[i] = '\0';
    	}
    }

    return 0;
}

// ※ 교수님 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    int i = 0;
    while (words[i] != '\n' && words[i] != '\0')
    	i++;
    if (words[i] == '\n')
    	words[i] = '\0';

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* fgets() and fputs() */

    char words[STRLEN] = "";
    fgets(words, STRLEN, stdin);	// does NOT remove \n

    //TODO: replace '\n' with '\0'
    int i = 0;
    while (words[i] != '\n' && words[i] != '\0')
    	i++;
    if (words[i] == '\n')
    	words[i] = '\0';

    fputs(words, stdout);			// does NOT add \n
    fputs("END", stdout);

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Small array */

    char small_array[5];
    puts("Enter long strings:");
    fgets(small_array, 5, stdin);	// FILE *_Stream
    //printf("%p\n", small_buffer);
    //printf("%p\n", fgets(small_buffer, 5, stdin));	// Return value of fgets
    fputs(small_array, stdout);
    /*
    	메모리 공간 초과해서 입력해도 공간 만큼 입력을 받는다.
    	그리고 runtime error가 일어나지 않는다.
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Small array */

    char small_array[5];
    puts("Enter long strings:");
    //fgets(small_array, 5, stdin);	// FILE *_Stream
    printf("%p\n", small_array);
    printf("%p\n", fgets(small_array, 5, stdin));	// Return value of fgets
    fputs(small_array, stdout);

    return 0;
}

/*
^z 입력시 null charcater 출력됨
(EOF: End of File)
*/

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* Repeating short reading */

    char small_array[5];
    puts("Enter long strings:");
    while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
    	fputs(small_array, stdout);
    	//puts(small_array);	// What if we use puts()
    /*
    	마치 한 번에 많이 입력 받아서 출력하는 것 처럼 보임
    	내부적으로 buffer를 사용하기 때문
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main() {

    /* scanf() */

    char str1[6], str2[6];
    int count = scanf("%5s %5s", str1, str2);
    //int count = scanf("%6s %6s", str1, str2); // run-time error
    //int count = scanf_s("%5s %5s", str1, 6, str2, 6);
    printf("%s|%s \n", str1, str2);
    /*
    	scanf로 string 입력받을 때 글자 개수 제한 가능
    */

    return 0;
}

/*********************************************************
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

char* custom_string_input(char* st, int n);

int main() {

    /* An example of custom input function */
    char word[11];
    puts(custom_string_input(word, 11));

    return 0;
}

// 문자열 입력 함수 만들기
char* custom_string_input(char* st, int n) {
    char* ret_ptr;
    int i = 0;

    ret_ptr = fgets(st, n, stdin);
    if (ret_ptr) {
    	while (st[i] != '\n' && st[i] != '\0')
    		i++;
    	if (st[i] == '\n')
    		st[i] = '\0';
    	else
    		while (getchar() != '\n')	// clear buffer
    			continue;
    }
    return ret_ptr;
}
