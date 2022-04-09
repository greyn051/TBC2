/*
## 11.7 선택 정렬(Selection Sort) 문제 풀이
*/

//아래에 설명 된 정렬 알고리즘을 코드로 구현해보자⭐️

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
    Selection Sort Algorithm
    https://www.geeksforgeeks.org/selection-sort/

    Youtube search "Selection Sort", "CS50"

    64 25 12 22 11	(min_idx = 0)
       64			(min_idx = 0)
       25			(min_idx = 1)
          25		(min_idx = 1)
    	  12		(min_idx = 2)
    	     12 	(min_idx = 2)
    		    12	(min_idx = 2)
    			11	(min_idx = 4)
    11 25 12 22 64	(swap arr[0] and arr[4])	// min index를 찾은 후에 swap(가장 작은 수와 가장 큰 수 자리 교체)

    11 25 12 22 64	(min_idx = 1)	// index 1부터 다시 비교 시작
          25		(min_idx = 1)
    	  12		(min_idx = 2)
    	     12 	(min_idx = 2)
    		    12	(min_idx = 2)
    11 12 25 22 64	(swap arr[1] and arr[2])

    11 12 25 22 64	(min_idx = 2)
    ...

    11 12 22 25 64	(min_idx = 3)
    ...

*/

/*
    알고리즘 이해할 때 추가자료 보는 게 좋다.
*/

void swap(int* xp, int* yp); //
void printArray(int arr[], int size); // 출력
void selectionSort(int arr[], int n); // 가장 중요

int main() {

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);	// ascending order

    printArray(arr, n);

    return 0;
}

// 원활한 진행을 위해 함수들의 일부를 보여줌

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	//TODO: fill blank(s)
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		//TODO: fill blank(s)
    	}

    	// Swap the found minimum element with the first element
    	//TODO: fill blank(s)
    }
}

// ---

// ※ 내 코드
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* xp, int* yp); //
void printArray(int arr[], int size); // 출력
void selectionSort(int arr[], int n); // 가장 중요

int main() {

    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);	// ascending order

    printArray(arr, n);

    return 0;

}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		if (arr[min_idx] > arr[j])
    			min_idx = j;
    	}
    	// Swap the found minimum element with the first element
    	swap(&arr[i], &arr[min_idx]);
    }
}

/*
    알고리즘 구현하기 전에 어려울줄 알고 매우 쫄았었는데
    막상 풀어보니 매우 간단하다.
    물론 이번에 거의 다 힌트였지만 다음부터 쫄지말고 실행하자.
*/

//※ 교수님 코드(거의 동일)
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) // Note n - 1
    {
    	// Find the minimum element in unsorted array
    	min_idx = i;
    	for (j = i + 1; j < n; j++) // Note i + 1
    	{
    		if (arr[j] < arr[min_idx])
    			min_idx = j;
    	}
    	// Swap the found minimum element with the first element
    	swap(&arr[min_idx], &arr[i]);
    }
}
