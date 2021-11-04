/*
## 6.4 관계 연산자(Relational Operator)
*/

#include <stdio.h>

int main() {

    /*
       Relational Operators
       <	   is less than
       <=      is less than
       ==	   is less than
       >=	   is less than
       >	   is less than
       !=	   is less than
    */

    int n = 0;
    while (n++ < 5)		// n++ < 5 is a relational expression
    	printf("%d", n);

    printf("\n");

    char c = 'A';
    while (c != 'Z')
    	printf("%c ", c++);

    return 0;
}


/*********************************************************
*********************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> //fabs()

int main() {
    // 상수 정의 할 때 const 사용 권장
    const double PI = 3.1415026535897932384626433832795;
    double guess = 0.0;

    printf("Input pi : ");
    scanf("%lf", &guess);
    //while (guess != PI)		// 실수 끼리 비교 할 때 != 잘 안 쓴다.(매우 정확하게 일치해야하므로) 그래서 math.h 쓰자!
    while (fabs(guess - PI) > 0.01)		// 차이가 0.01보다 작으면 ok
    {
    	printf("Fool! Try again.\n");
    	scanf("%lf", &guess);
    }

    printf("Good!");

    return 0;
}
