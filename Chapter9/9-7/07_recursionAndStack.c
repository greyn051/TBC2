/*
## 9.7 재귀 호출(Recursion)과 스택(Stack)
*/

#include <stdio.h>

void my_func(int);

int main() {

    my_func(1);

    return 0;
}

void my_func(int n) {
printf("Level %d, address of variable n = %p\n", n, (int)& n); // ptr -> int casting

    if(n <= 4)
    	my_func(n + 1);

    printf("Level %d, address of variable n = %p\n", n, (int)& n); // ptr -> int casting
}
