/*
## 11.8 문자열의 포인터를 정렬하기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;
}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/

//문자열 정렬 해보자

//---

//※ 내 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;

}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/

void printStringArray(char* arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%s\n", arr[i]);
    /*
        printf("%s\n", *arr[i]); // %s 인가 %c인가? %s는 왜 warning이 뜨는가?
        printf("%s\n", arr[i]); // *을 제거하니 제대로 출력된다.(포인터 개념 부족)⭐
    */
    printf("\n");
}

void swap(char** xp, char** yp) {
    char *temp = *xp; // 여기 char로 두면 안 되나? > 된다.
    *xp = *yp;
    *yp = temp;
    /*
        char temp를 char _temp로 바꾸니까 된다.
        https://stackoverflow.com/questions/3816233/swapping-two-string-pointers
        이중포인터 개념 복습하자⭐
    */
}

void selectionSort(char\* arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
    	min_idx = i;
    	for (j = i + 1; j < n; j++)
    	{
    		if (strcmp(arr[min_idx], arr[j]) == 1) {
    			min_idx = j;
    		}
    	}
    	swap(&arr[min_idx], &arr[i]);
    }
}


/*********************************************************
*********************************************************/


// ※ 교수님 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp() // 문자열 간의 순서를 정할 수 있다.

void swap(char** xp, char** yp); //Note: Optional
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main() {

    char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);	// ascending order

    printStringArray(arr, n);

    return 0;

}
/*
    문자열의 '포인터'를 정렬해야한다.
    문자열 자체를 정렬하면 문자열들을 정렬하면서 계속 복사를 해야한다.
    값 자체를 복사하면 연산량이 많아지므로 연산량을 조금이라도 줄이기 위해
    (앞에 선택정렬에서 index를 이용했던 것 처럼 이번에는 포인터를 이용한다.)
*/

void printStringArray(char\* arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    puts(arr[i]);
    printf("\n");
}

void swap(char** xp, char** yp) {
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(char\* arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++)
    	{
    		if (strcmp(arr[j], arr[min_idx]) < 0)	// 부호에 따라 오름차순, 내림차순 정렬 정할 수 있다.
    			min_idx = j;
    	}

    	// Swap the found minimum element with the first element(이중포인터 사용하지 않고 구현 가능)⭐
    	/*char* temp = arr[min_idx];
    	arr[min_idx] = arr[i];
    	arr[i] = temp;*/
    	swap(&arr[min_idx], &arr[i]);
    }

}
