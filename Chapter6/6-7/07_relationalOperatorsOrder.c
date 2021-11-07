/*
## 6.7 관계 연산자의 우선순위
*/

#include <stdio.h>

int main() {
    int x = 1, y = 2, z;

    x > y + 2;		// +가 > 우선순위 높아서 밑과 같다.
    x > (y + 2);	// 지금 붙어 있는 statement들은 같은 의미라는 뜻이다.

    x = y > 2;
    x = (y > 2);

    z = x > y;
    z = (x > y);

    x != y == z;	// 우선순위가 같으면 왼쪽에서 오른쪽 순서로 진행
    (x != y) == z;

    return 0;
}
