#include <stdio.h>

#define MAX 1000

// 3. Use local in smaller function
void func() {

	int l_arr[MAX] = { 0, };
}

int main() {

/*
	Call func()
	...
	Call func()
	...
*/

	return 0;
}


