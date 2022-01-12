/*
## 9.8 팩토리얼(Factorial) 예제
*/

// loop와 recursive를 이용해서 둘 다 구현해봐

// ※ 내 코드
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;

}

long loop_factorial(int n) {
long factorial = 1;

    for (n; (n > 0); --n) {
    	factorial *= n;
    }

    return factorial;

}

long recursive_factorial(int n) {

    long factorial = 1;

    factorial *= n;

    if (n > 0)
    	recursive_factorial(n - 1);

    return factorial;

}

/*
loop_factorial은 구현했는데
recursive_factorial은 어떻게 factorial 계산 식을 넣어야 할지 모르겠음 gg
*/


/*********************************************************
*********************************************************/

/*
(힌트를 봐도 모르겠다)
아니다 힌트를 보고 직접 풀었다.(이거 안 풀어봤으면 꼭 풀어보라고 하셔서)
*/

/*
뭔가 감이 와서 코드를 작성했는데
될 것 같지만 구체적으로 생각을 하기 힘들어서(뇌로만 하니까 과부하와서)
직접 종이에 그리면서 구현해보니 되었다.(아주 좋아)
(Don't Panic의 성과)
*/

// ※ 힌트를 보고 한 내 코드
#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!		// 이 성질이 recursive에서 힌트
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n) {
long ans;

    for (ans = 1; n > 1; n--) {
    	ans *= n;
    }

    return ans;
}

long recursive_factorial(int n) {

    long ans = n;

    if (n > 0) {
    	//TODO: return ...;

    	ans *= recursive_factorial(n - 1);

    	return ans;		// 여기까지 하고 직접 종이에 그려보았는데 맞는 것 같다.
    }
    else
    	return 1;
}

// ※ 교수님 코드
#include <stdio.h>

/*
	loop vs recursion
	factorial : 3! = 3 * 2 * 1, 0! = 1
	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!		// 이 성질이 recursive에서 힌트
*/

long loop_factorial(int n);
long recursive_factorial(int n);

int main() {

    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n) {
long ans;

    for (ans = 1; n > 1; n--) {
    	ans *= n;
    }

    return ans;
}

long recursive_factorial(int n) {

    if (n > 0) {
    	//TODO: return ...;
    	return n * recursive_factorial(n - 1); // tail (end) recursion
    }
    else
    	return 1;
}
