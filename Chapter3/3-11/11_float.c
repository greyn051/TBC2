#include <stdio.h>
#include <float.h>

int main() {
    printf("%u\n", sizeof(float));
    printf("%u\n", sizeof(double));
    printf("%u\n", sizeof(long double));

    float f = 123.456f;
    double d = 123.456;

    float f2 = 123.456;
    double d2 = 123.456f;

    int i = 3;
    float f3 = 3.f; // 3.0f 홍교수님은 이래 쓴다(이런식으로 쓰면 알아보기 쉬우니)
    double d3 = 3.; // 3.0

    float f4 = 1.234e10f;

    float f5 = 0xb.ap1;
    double d5 = 1.0625e0;

    printf("%f %F %e %E\n", f, f, f, f);
    printf("%f %F %e %E\n", d, d, d, d);
    printf("%a %A\n", f5, f5);
    printf("%a %A\n", d5, d5);

    return 0;
}
