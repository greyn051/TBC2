// sizeof(), size_t

#include <stdio.h>
#include <stdlib.h> // malloc()

int main() {

	/* 1. sizeof basic types */

	int a = 0;
	unsigned int int_size1 = sizeof a;
	unsigned int int_size2 = sizeof(int);
	unsigned int int_size3 = sizeof(a);

	size_t int_size4 = sizeof(a);
	size_t float_size = sizeof(float);

	printf("Size of int type is %u bytes.\n", int_size1);
	printf("Size of int type is %zu bytes.\n", int_size4);
	printf("Size of float type is %zu bytes.\n", float_size);

	return 0;
}

/*********************************************************
*********************************************************/

/*
배열을 직접 sizeof하면 전체 배열의 크기가 나오고(120byte)
포인터를 sizeof 하면 그 주소에 해당된 크기만 나온다.(4byte)
(그런데 프로그래밍 할 때 배열 자체도 주소로 생각하는게 편할 때가 많다)(이건 예외라고 생각하자)
*/

int main() {

	/* 2. sizeof arrays */

	int int_arr[30]; // int_arr[0] = 1024; ...
	int* int_ptr = NULL;
	int_ptr = (int*)malloc(sizeof(int) * 30); // int_ptr[0] = 1024; ...

	printf("Size of array = %zu bytes\n", sizeof(int_arr));
	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));

	return 0;
}

/*********************************************************
*********************************************************/

// string에서 null을 저장공간으로 하나 가짐

int main() {

	/* 3. sizeof character array */

	char c = 'a';
	char string[10]; // maximally 9 character + '/0' (null charater)

	size_t char_size = sizeof(char);
	size_t str_size = sizeof(string);

	printf("Size of char type is %zu bytes.\n", char_size);
	printf("Size of string type is %zu bytes.\n", str_size);

	return 0;
}

/*********************************************************
*********************************************************/

//구조체 struct의 크기

struct MyStruct {

	int i;
	float f;
};


int main() {

	/* 4. sizeof structure */

	printf("%zu\n", sizeof(struct MyStruct));

	return 0;
}
