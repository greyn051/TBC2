/*
## 8.2 파일의 끝
*/

// EOF

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

    char c;

    while ((c = getchar()) != EOF) // End Of File
    	putchar(c);

    return 0;
}


/*********************************************************
*********************************************************/


// 과연 들어온게 EOF 맞는지 확인

int main() {

    char c;

    while ((c = getchar()) != EOF) // End Of File
    	putchar(c);

    while (1) {
    	c = getchar();
    	printf("%d\n", c);
    	if (c == EOF)
    		break;
    }

    return 0;
}
