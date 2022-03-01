/*
## 10.11 배열 매개변수와 const
*/

// 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.

#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], int n, int val) // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); // 원소가 몇 개 인지

    print_array(arr, 5);
    add_value(arr, 5, 100); // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
    print_array(arr, 5);

    return 0;
}


/*********************************************************
*********************************************************/


// sum만 구하는게 목표였는데 배열의 값이 변했다.(의도하지 않음)

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], int n, int val) // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(int ar[], int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); // 원소가 몇 개 인지

    print_array(arr, 5);
    add_value(arr, 5, 100); // 함수를 배열로써 매개변수화 하면 그 배열을 '포인터'로 받는다.
    print_array(arr, 5);

    int s = sum(arr, n);

    printf("sum is %d\n", s);
    print_array(arr, 5);

    return 0;
}

// ++한 부분을 지우면 해결되겠지만 프로그래머들은 이러한 실수를 항상 할 수도 있다고 가정을 해야한다.


/*********************************************************
*********************************************************/


// 그래서 예비책으로 함수에 입력되는 배열에 const를 붙여준다.

int sum(const int ar[], const int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i] ++;	// wrong implementation

    return total;

}

// const를 썼기 때문에 compile이 안 된다. > 실수를 찾을 수 있다.


/*********************************************************
*********************************************************/


/*
sum 함수를 고쳐서 배열의 값이 변하지 않게 수정,
const를 붙일 수 있는 곳에 다 붙이기
*/

#include <stdio.h>

void print_array(const int arr[], const int n) {
    for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
    printf("\n");
}

void add_value(int arr[], const int n, const int val) // 배열의 값을 더하는 것이 목적이기 때문에 배열에 const를 붙이면 안 된다.
{
    int i;
    for (i = 0; i < n; i++)
    arr[i] += val;
}

int sum(const int ar[], const int n) {
    int i;
    int total = 0;

    for (i = 0; i < n; i++)
    	total += ar[i];

    return total;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 }; // add_value 함수 때문에 const를 붙이면 안 된다.
    const int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, 5);
    add_value(arr, 5, 100);
    print_array(arr, 5);

    int s = sum(arr, n);

    printf("sum is %d\n", s);
    print_array(arr, 5);

    return 0;
}
