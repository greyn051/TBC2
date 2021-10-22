/*
## 4.9 printf() 함수가 인자들을 해석하는 과정
*/

#include <stdio.h>

int main() {

	float	n1 = 3.14;  // 4 bytes
	double	n2 = 1.234; // 8 bytes
	int		n3 = 1024;  // 4 bytes

	printf("%f %f %d\n\n", n1, n2, n3); // 정상 출력

	//Note the warnings in output window // 밑에는 모두 비정상 출력
	printf("%d %d %d\n\n", n1, n2, n3);		// 4, 4, 4 (N, N, N) // 연쇄적으로 오류가 생겨서 전부 다 이상한 값이 나옴
	printf("%lld %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (N, N, Y) // 부동소수점 수를 강제로 integer로 해석하려해서 오류, 앞에 2개 오류 났어도 마지막은 데이터 타입이 잘 맞아서 잘 나옴
	printf("%f %d %d\n\n", n1, n2, n3);		// 8, 4, 4 (Y, N, N)
	printf("%f %lld %d\n\n", n1, n2, n3);	// 8, 8, 4 (Y, N, Y)

	return 0;
}
