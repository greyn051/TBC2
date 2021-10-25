/*
## 5.3 더하기, 빼기, 부호 연산자들(Addition, Subtraction, Sign)
*/

#include <stdio.h>

int main() {
printf("%d\n", 1 + 2);

	int income, salary, bonus;

	income = salary = bonus = 100;// triple assignment, 오른쪽 부터 값을 대입, 전체가 100됨, income = (salary = (bonus = 100));과 같음

	salary = 100;
	bonus = 30;

	income = salary + bonus;// l-value vs r-value

	int takehome, tax;
	tax = 20;
	takehome = income = tax;

	int a, b;
	a = -7;
	b = -a;
	b = +a;// + does nothing

	1.0f + 2;// ? float로 저장됨(실수 + 정수는 실수로 저장) promotion 승진 이라고 불림

	return 0;
}
