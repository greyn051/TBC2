/*
## 9.6 재귀 호출(Recursion)
*/

#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, &n);

    my_func(n + 1);		// 자기 자신을 호출하는 구조

    //TODO: stop condition
    //TODO: tail recursion
}


/*********************************************************
*********************************************************/

/*
실전에서 사용하려면
종료 될 조건 같이 사용
*/


#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, &n);

    if(n <= 4)
    	my_func(n + 1);

    printf("Level %d, address of variable n = %p\n", n, &n);

    //TODO: stop condition
    //TODO: tail recursion
}


// 디버그 하면서 이해해봐
