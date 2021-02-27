#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	/*
		Object
		- "An object is simply a block of memory that can store a value." (KNK p. 487)
		- Object has more developed meaning in C++ and Object Oriented Programming (OOP)

		Identifiers
		- Names for variables, functions, macros, and other entitles. (KNK p. 25)
	*/

	int var_name = 3;		// creates an object called 'var_name'.

	int* pt = &var_name;	// pt is an identifier.
	*pt = 1;				// *pt is not an identifier. *pt designates an object.

	int arr[100];	// arr is an identifier. Is arr an object?(No, arr is address of first element of array)
	arr[0] = 7;		// arr[0] is an object.(Identifier는 아니지면 expression을 통해 메모리에 접근 가능하므로)
	// Identifier와 Object가 다른 개념으로 사용될 수 있다.
	

	/*
		lvalue is an expression 'referring' to an object. (K&R p.197)
		(refer을 또 다른 이름처럼 사용한다고 이해)

		L-value : left side of an assignment
		R-value : right side, variable, constant, expressions (KNK p. 67)
	*/

	var_name = 3;	// modifiable lvalue
	// 메모리의 공간을 referring해준다.(변수 이름이 메모리 공간x)
	int temp = var_name; // var_name에 있는 '값'을 복사해서 대입
	temp = 1 + 2;
	// L-value는 object다. 변수명이 R-value로 가면 가진 값만 가져오는 식이다

	pt = &var_name;		// 포인터에 변수의 주소값을 대입
	int* ptr = arr;		// 주소값 대입
	*pt = 7;	// *pt is not an identifier but an modifiable lvalue expression.

	int* ptr2 = arr + 2 * var_name; // address rvalue
	*(arr + 2 * var_name) = 456;	// lvalue expression(위의 형태에 *을 앞에 붙여줘서 rvalue expression(modifiable) 처럼 사용 가능

	const char* str = "Constant string";		// str is a modifiable lvalue.
	str = "Second string";	// "Constant string" = "Second String"	// impossible
	//str[0] = 'A'; // Error(위에 const 떼도 error 생김)
	//puts(str);

	char str2[] = "String in an array";
	/*
		Array로서 메모리 공간을 따로 할당 받고
		str2라는 identifier가 문자열이 저장되기 충분한 메모리 공간에 대한 식별자 역할을 한다.
		그러므로 위에 있는 str과 작동방식이 다르다. 차이점을 알고있자.
	*/
	str2[0] = 'A';	// OK
	//puts(str2);

	/*
		Identifiers have scope.(영역)	// Identifier는 Object의 이름 역할을 하는데 이름이 절대적인건 아니다.(이름이 없을 수도 있다.)
		Objects have storage duration.(저장공간의 지속기간)(메모리에 언제부터 언제까지 위치하는지)
		Variables and functions have one of the following linkages(연결):
			external linkage, internal linkage, or no linkage.
		다음 강의에 설명
	*/

	return 0;
}


