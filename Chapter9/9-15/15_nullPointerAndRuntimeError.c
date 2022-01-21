/*
## 9.15 NULL 포인터와 런타임 에러
*/

//런타임 에러 나는 경우

#include <stdio.h>

int main() {

    /*
    int a = 1234;
    printf("%p\n", &a); // 주소값
    printf("%d\n", a);
    */

    int *ptr = 1234; // 그냥 int *ptr; 이면 컴파일도 안 해줌.

    printf("%p\n", ptr);
    printf("%d\n", *ptr);	// 정말 위의 1234 주소로 가서 가져오려고 시도 했음, 막상 가서 보니까 프로그램이 사용하도록 할당받은 공간이 아님, 그래서 강제 종료시킴

    return 0;
}


/*********************************************************
*********************************************************/


/*
런타임 에러 나는 경우2
b의 값에 따라서 포인터에 주소를 넣거나 안 넣는 경우 생각 가능
*/

#include <stdio.h>

int main() {

    int* safer_ptr; // = NULL;

    int a = 123;

    // safer_ptr = &a;

    // 런타임 에러 나는 경우
    int b;
    scanf("%d", &b);

    if (b % 2 == 0)
    	safer_ptr = &a;

    return 0;
}


/*********************************************************
*********************************************************/


/*
포인터에 NULL값을 넣어 초기화 하는 것이 일반적이다.
(그 포인터를 사용해도 되는지 확인, 런타임 에러 방지할 수 있다)
*/

#include <stdio.h>

int main() {

    int* safer_ptr = NULL;

    int a = 123;

    // safer_ptr = &a;

    int b;
    scanf("%d", &b);

    if (b % 2 == 0)
    	safer_ptr = &a;

    if (safer_ptr != NULL)
    	printf("%p\n", safer_ptr);

    if (safer_ptr != NULL)
    	printf("%d\n", *safer_ptr);

    return 0;
}
