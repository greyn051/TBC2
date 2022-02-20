/*
## 10.8 두 개의 포인터로 배열을 함수에게 전달해주는 방법
*/

#include <stdio.h>

double average(double*, double*);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };

    printf("Avg = %f\n", average(arr1, arr1 + 5)); 	// 포인터 산술 연산

    return 0;
}

double average(double* start, double* end) {

    int count = 0;
    double avg = 0.0;
    while (start < end) {
    	avg += *start++;
    	count++;
    }
    avg /= (double)count;

    return avg;
}


/*********************************************************
*********************************************************/


/*
while문에서 개수 세는게 부담스러울 수 있으니
함수 안에서 포인터끼리 빼서 구한다.
*/

#include <stdio.h>

double average(double*, double*);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };

    printf("Avg = %f\n", average(arr1, arr1 + 5));

    return 0;
}

double average(double* start, double* end) {

    int count = end - start;
    double avg = 0.0;
    while (start < end) {
    	avg += *start++;
    	//count++;
    }
    avg /= (double)count;
    printf("%d\n", count);
    return avg;
}
