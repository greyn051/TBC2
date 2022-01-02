/*
## 9.3 함수의 자료형과 반환값
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int int_min(int, int);

int main() {

    int i1, i2;

    while (1) {

    	printf("Input two integers : ");

    	if (scanf("%d %d", &i1, &i2) != 2) break;

    	int lesser = int_min(i1, i2);
    	// int lesser = min;
    	printf("The lesser of %d and %d is %d\n", i1, i2, lesser);

    	//printf("The lesser of %d and %d is %d\n", i1, i2, int_min(i1, i2));
    }

    printf("End.\n");

    return 0;
}

int int_min(int i, int j)
//int_min(int i, int j)
{
    int min;
    if (i < j)
    min = i;
    else
    min = j;

    return min;

    // return (i < j) ? i : j; // 이거랑 위랑 기능 같음(능숙한 프로그래머는 이것을 선호)

    // return (float)min; // int를 float로 강제로 바꾸는 실험, 하지만 warning이 뜨는 것은 flaot를 int로 바꿀 때 뜬다(return하는 자료형이 int이기 때문)
    ////마치 return (int)((float)min);와 같다.

    /*if (i < j)
    	return i;
    else
    	return j;

    printf("ERROR");
    exit(1);
    */

    //return; // return with no value
}
