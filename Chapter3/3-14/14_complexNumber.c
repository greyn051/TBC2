#include <stdio.h>
#include <complex.h>

int main() {

    _Dcomplex z;
    z._Val[0] = 1.0;
    z._Val[1] = 1.0;

    return 0;
}

/*
vsc, gcc 에서
vsc는 복소수 지원 좀 더 잘 해줌

#include <stdio.h>
#include <complex.h>

int main()
{
    //double _Imaginary i = 3;
    double _Complex z = 1 + 2 \* I;

    z = 1 / z;

    printf("1 / (1.0 + 2.0i) = %.1f%+.1fi", creal(z), cimag(z));

    return 0;
}

I는 허수 부분을 의미한다(Imaginary number)
creal(z)는 실수 부분
cimag(z)는 허수 부분을 가져와서 출력
복소수의 나누기도 구현
원래 표준에는 \_Imaginary도 있어야 하는데 gcc에서도 조차 구현되어 있지 않다.

*/