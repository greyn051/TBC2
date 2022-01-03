/*
## 9.4 변수의 영역(Scope)과 지역 변수(Local Variable)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a;

int int_max(int i, int j);

int int_max(int i, int j) {

    //a = 456;
    int m; // stack frame
    m = i > j ? i : j;
    return m;

}

int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	//int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}

// 여기서 변수 a는 모두 같은 변수인 걸 알 수 있다.


/*********************************************************
*********************************************************/


int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}

/*
큰 영역 안에 다른 영역을 만들고 그 안에 똑같은 이름의 변수를 선언해버리면
각각 다른 변수이다.(메모리 주소가 다르다)
*/

/*********************************************************
*********************************************************/

// 추가 예제

int main() {

    //m = 123;

    int a;

    a = int_max(1, 2);

    printf("%d\n", a);
    printf("%p\n", &a);

    {
    	int a;
    	a = int_max(4, 5);

    	printf("%d\n", a);
    	printf("%p\n", &a);

    	int b = 123;
    }

    b = 456; // int b 영역 밖으로 나왔기 때문에 invisible 하다.

    printf("%d\n", a);
    printf("%p\n", &a);

    return 0;
}
