/*
## 6.17 for 루프를 배열과 함께 사용하기
*/

#include <stdio.h>

#define SIZE 5

int main() {

    int my_arr[SIZE];

    // prepare for array data
    for (int i = 0; i < SIZE; ++i) // []안은 index
    	my_arr[i] = i; // my_arr[i] = i * i;도 가능

    // print array data
    for (int i = 0; i < SIZE; ++i)
    	printf("%d ", my_arr[i]);

    // for 1개에 대입, 출력을 다 처리하면 될 것 같지만, 데이터 사이즈가 매우 커지면 아닐 수 있다.(오히려 쪼개는 것이 장기적으로 더 효율적)

    //TODO: try debugger

    return 0;
}


/*********************************************************
*********************************************************/

/*
ex)
숫자를 5개 입력받고
입력받은 숫자들의 합을
배열과 for 루프를 함께 사용해서
구현을 해보자.
(입력받는 개수도 define으로 바꿀 수 있으면 더 좋음)
*/

// ※ 내 코드
#include <stdio.h>

#define SIZE 5

int main() {
    int input[SIZE];
    int sum = 0;

    printf("Enter 5 numbers : ");

    for (int i = 0; i < SIZE; ++i) {
    	scanf("%d", &input[i]);
    	sum += input[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}


// ※ 교수님 코드
#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE];
    int sum = 0;
    int i;

    printf("Enter %d numbers : ", SIZE);

    for (i = 0; i < SIZE; ++i)
    	scanf("%d", &numbers[i]); // &(numbers[i])

    for (i = 0; i < SIZE; ++i)
    	sum += numbers[i];

    /* for문을 쪼갠 이유는 최근의 컴퓨팅 기법에서는 멀티쓰레딩, GPU 발달되어있고,
    예전과 달리 데이터 양이 많기 때문에 for loop를 여러개 쪼개는 것이 효율적인 경우가 많다. */

    //TODO: average

    printf("Sum = %d\n", sum);

    return 0;
}
