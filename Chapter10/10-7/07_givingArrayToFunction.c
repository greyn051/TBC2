/*
## 10.7 배열을 함수에게 전달해주는 방법
*/


#include <stdio.h>

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    //double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    printf("Avg = %f\n", avg);

    return 0;
}


/*********************************************************
*********************************************************/


// avg2 만들기 위해 함수 만들자

#include <stdio.h>

double average(double arr1[5]) {

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;
}

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    //double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different // 만약 arr2의 배열이 3개라면 avg함수 안 된다.

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));

    printf("Avg = %f\n", average(arr1));
    printf("Avg = %f\n", average(arr2));

    return 0;
}


/*********************************************************
*********************************************************/


// 함수에 들어가는 배열의 사이즈 확인

#include <stdio.h>

double average(double arr1[5]) {

    printf("Size = %zd in function average\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;
}

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));

    printf("Avg = %f\n", average(arr1));
    printf("Avg = %f\n", average(arr2));

    return 0;
}


/*********************************************************
*********************************************************/


// ⭐함수에서 배열을 받을 때는 포인터로 받는다!

double average(double *arr1) // (double arr1)해도 된다.
{
printf("Size = %zd in function average\n", sizeof(arr1));

    double avg = 0.0;
    for (int i = 0; i < 5; ++i) {
    	avg += arr1[i];
    }
    avg /= (double)5;

    return avg;

}


/*********************************************************
*********************************************************/


/*
완벽하게 입력한 경우
(함수에 매개변수 사용해서 일반화, 함수에 들어가는 배열에 index 안 씀)
*/

#include <stdio.h>

double average(double data_array[], int n);

int main() {

    double arr1[5] = { 10, 13, 12, 7, 8 };
    //double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
    double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different

    printf("Address = %p\n", arr1);
    printf("Size = %zd\n", sizeof(arr1));
    printf("Address = %p\n", arr2);
    printf("Size = %zd\n", sizeof(arr2));

    printf("Avg = %f\n", average(arr1, 5));
    printf("Avg = %f\n", average(arr2, 3));

    return 0;
}

double average(double data_array[], int n) {

    printf("Size = %zd in function average\n", sizeof(data_array));

    double avg = 0.0;
    for (int i = 0; i < n; ++i) {
    	avg += data_array[i];
    }
    avg /= (double)n;

    return avg;
}

/*
    위 함수를 선언할 때 이렇게 4가지 경우로 선언할 수 있다.

    double average(double *arr, int n); // 보통 이렇게 포인터로 쓴다
    double average(double _, int n); // 보통 이렇게 하면 알아본다.(뒤에 변수 들어온거 보고 배열인거 알 수 있음)
    double average(double arr[], int n);
    double average(double [], int n);
*/
