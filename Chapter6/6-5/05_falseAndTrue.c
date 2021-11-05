/*
## 6.5 사실과 거짓
*/

#include <stdio.h>

int main() {
    int tv, fv;
    tv = (1 < 2); // true value
    fv = (1 > 2); // false value

    printf("True is %d\n", tv);
    printf("False is %d\n", fv);

    return 0;
}


/*********************************************************
*********************************************************/


int main() {
    int i = -5;
    while (i)
    printf("%d is true\n", i++);
    printf("%d is false\n", i);

    return 0;
}
