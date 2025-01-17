/*
## 11.3 문자열의 배열
*/

#include <stdio.h>

int main() {

    /* Arrays of Character Strings */

    const char* mythings[5] = {
    	"Dancing in the rain",
    	"Counting apples",
    	"Watching movies with friends",
    	"Writing sad letters",
    	"Studying the C language"
    };

    // 40개 짜리 배열을 5개
    char yourthings[5][40] = {
    	"Studying the C++ language",
    	"Eating",
    	"Watching Netflix",
    	"Walking around till dark",
    	"Deleting spam emails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);		// pointer라서 주소가 같다
    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
    //printf("%u %u\n", (unsigned)&yourthings[0][0], (unsigned)temp2);
    printf("\n");

    printf("%-30s %-30s\n", "My Things:", "Your Things:");
    for (int i = 0; i < 5; i++)
    	printf("%-30s %-30s\n", mythings[i], yourthings[i]);

    printf("\nsizeof mythings: %zd, sizeof your yourthings: %zd\n",
    	sizeof(mythings), sizeof(yourthings));

    // 메모리 구조 파악을 위해 실험 삼아 실행
    for (int i = 0; i < 100; i++)
    	printf("%c", mythings[0][i]);
    printf("\n");
    printf("\n");

    for (int i = 0; i < 200; i++)
    	printf("%d", (int)yourthings[0][i]);
    printf("\n");

    for (int i = 0; i < 200; i++)
    	printf("%c", yourthings[0][i]);
    printf("\n");
    printf("\n");

    // Not a good idea to take advantage of this property

    return 0;
}
