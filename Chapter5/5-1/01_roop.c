/*
## 5.1 반복 루프와의 첫 만남
*/

//### 이제 거의 안 쓰는 goto 문

#include <stdio.h>

int main() {

	int n = 1;

label:
	printf("%d\n", n);
	n = n + 1;

	if (n == 10) goto out;

	goto label;

out:

	return 0;
}


/*********************************************************
*********************************************************/


//### while문으로 바꿔서 쓰기

int main() {

	int n = 1;

	while (n < 11) {
		printf("%d\n", n);
		n = n + 1;
	}

	return 0;
}
