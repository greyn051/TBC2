#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	Storage duration:
	- static storage duration // ������ �� ���� ���� �� ���� �޸� �ڸ� ����������	// ���⼭ ���ϴ� static�� '����'�̶�� �ǹ� �� ��ü
	(Note: 'static' keyword indicates the linkage type, not the storage duration)
	- automatic storage duration
	- allocated storage duration
	- thread storage duration

	duration�� �޸��� ���ӱⰣ�� �ǹ�
*/

void count() {

	int ct = 0;
	printf("count = %d\n", ct);
	ct++;
}

void static_count() {

	static int ct = 0;
	/*
		�տ� static�� ������ ���α׷��� ���۵� �� �޸𸮿� ������
		������ ���� �޸𸮿� �����ȴ�.(�Լ��� ������ �������� ����)
		(�ٽ� ����x)
	*/
	printf("static count = %d\n", ct);
	ct++;
}

int main() {

	count();
	count();
	static_count();
	static_count();

	return 0;
}