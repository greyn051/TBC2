#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in second.c

extern int g_int;	// referencing declaration

static void tool(void) {
	// 다른 파일에서 직접적으로 사용 막기 위해 static keyword 이용
}

//static void fun_second();	// prototype에 static붙여도 linking error 뜸

void fun_second(void) {

	tool();	// fun_second는 외부에서 사용 가능, tool()만 파일 내에서 사용 가능  

	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}

/*
static void fun_second(void) {

	g_int += 1;
	printf("g_int in fun_second() %d %p\n", g_int, &g_int);
}
// 이 경우에 linking error 발생
*/