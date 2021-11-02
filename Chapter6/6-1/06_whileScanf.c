/*
## 6.1 while 반복 루프에서 scanf()의 반환값 사용하기
*/
/*
여러개의 값을 받다가 q를 입력하면
이전에 입력했던 값들을 모두 더한 합을 보여주고 종료 하는 프로그램 만들기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num, sum = 0;
	int status;		// scanf함수의 반환값 저장할 변수 선언

	printf("Enter an integer (q to quit) : ");

	status = scanf("%d", &num);		// return value of scanf() // scanf의 반환값은 입력받은 변수의 개수를 return 값으로 돌려줌
    /*
        정수를 입력하면 num이라는 변수에 하나를 입력받았기 때문에 status 변수에 1이라는 값이 저장됨.
        만약 숫자가 아니라 q라는 문자를 입력했다면 그 때는 정수로 입력을 받을 수가 없기 때문에 입력을 받지 않는다.
        그럼 입력받은 변수의 개수가 0이므로 status의 값도 0이다.
    */

	while (status == 1)				// equality operator (==)
	{
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d", num);

	//TODO: C-style shortcut

	return 0;
}

/*
※ 내가 한 코드(실패)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;

	printf("Enter an integer (q to quit) : ");
	scanf("%d", &n);

	while (n != 113 ) {

		sum += n;
		printf("Enter next integer (q to quit) : ");
		scanf("%d", &n);

	}

	printf("%d", sum);

	return 0;
}
*/


/*********************************************************
*********************************************************/

// ⭐반복되는 코드 줄이기(status 부분) //TODO: C-style shortcut

int main() {
    int num, sum = 0;
    printf("Enter an integer (q to quit) : ");

    while (scanf("%d", &num) == 1)	// 장점: 코드가 깔끔해짐, 단점: 코드를 주의깊게 봐야함
    {
    	sum = sum + num;

    	printf("Enter next integer (q to quit) : ");
    }

    printf("Sum = %d", num);

    //TODO: C-style shortcut

    return 0;
}
