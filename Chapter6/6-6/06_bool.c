/*
## 6.6 \_Bool 자료형
*/

#include <stdio.h>

int main() {
    int i;
    //i = 5; // 대입
    //i == 5; // 비교
    //5 = i;
    //5 == i; // 문법 오류가 없음(비교이기 때문)

    while (i = 5) {/*do something*/ };
    // i에 5가 대입되고, expression이 5가 되어 true로 간주됨 but 이렇게 작성한 것은 90%이상 실수한 것일 거임.(실제로 이렇게 사용x, 밑에처럼 사용함)
    while (i == 5) {/*do something*/ };

    return 0;
}


/*********************************************************
*********************************************************/


int main() {
    _Bool boolean_true = (2 > 1); // 이전에 boolean 타입 쓰던 사람들이 bool이라고 지정해서 사용해왔기 때문에 호환성을 유지하려고 _Bool로 지음
    _Bool boolean_false = (1 > 2); // Bool 자료형도 내부적으로는 '정수형'으로 처리된다.

    printf("True is %d\n", boolean_true);
    printf("False is %d\n", boolean_false);

    printf(boolean_true ? "true" : "false");
    printf("\n");
    printf(boolean_false ? "true" : "false");

    return 0;
}


/*********************************************************
*********************************************************/


#include <stdbool.h> 추가하고 나서

#include <stdio.h>
#include <stdbool.h>

int main() {
    bool bt = true; // 키워드는 아니라서 파란색이 아니다
    bool bf = false; // 예전에 프로그래머들이 bool 만들어서 쓰던거 표준화한 것임

    printf("\n");
    printf("True is %d\n", bt);
    printf("Flase is %d\n", bf);

    return 0;
}
