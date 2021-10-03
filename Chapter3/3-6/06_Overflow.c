#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    unsigned int i = 0;

    printf("%u\n", sizeof(unsigned int));
    printf("%u", sizeof(i));

    return 0;
}

/*
#include <stdio.h>

int main()
{
    unsigned int i = 0b11111111111111111111111111111111;

    printf("%u\n", i);

    return 0;
}
*/

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int i = 0b11111111111111111111111111111111;
    unsigned int u = UINT_MAX;

    printf("%u\n", i);
    printf("%u\n", u);

    return 0;
}
*/

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int u_max = UINT_MAX;
    unsigned int u_min = 0;
    signed int i_max = INT_MAX;
    signed int i_min = INT_MIN;

    printf("max of uint = %u\n", u_max);
    printf("min of uint = %u\n", u_min);
    printf("max of int = %d\n", i_max);
    printf("min of int = %d\n", i_min);

    return 0;
}
*/

/*************************
 * overflow 실행
*************************/

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int u_max = UINT_MAX + 1;
    printf("%u", u_max);

    return 0;
}
*/

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int u_max = UINT_MAX;

    // i to binary representation
    char buffer[33];
    _itoa(u_max, buffer, 2);

    // print decimal and binary
    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
*/

// or

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int u_max = UINT_MAX + 1;

    char buffer[33];
    _itoa(u_max, buffer, 2);

    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
*/

// or

/*
#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int u_max = 0 - 1;

    char buffer[33];
    _itoa(u_max, buffer, 2);

    printf("decimal: %u\n", u_max);
    printf("binary: %s\n", buffer);

    return 0;
}
*/
