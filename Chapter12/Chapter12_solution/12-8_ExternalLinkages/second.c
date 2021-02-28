#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	// printf() in second.c

extern int g_int;	
// file scope에서는 초기화 가능(단, 처음 전역변수 선언 시 내가 초기화하지 않아야 함)(file scope중 한 곳에서만 초기화 가능하다는 뜻)
// 가급적 extern이 붙은 곳에서는 초기화 안 하는 것이 좋다.

void temp() {

	// extern int g_int;	// 여기서 초기화는 불가(block scope에서 초기화는 불가능)(BSS data segment를 다뤄야하므로 적절치 않음)

	g_int += 1000;
}

void fun_sec() {

	temp();

	extern int g_int;

	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);	// 전역변수 사용 가능
}



