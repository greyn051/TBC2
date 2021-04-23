#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>

// TODO: try increasing/decreasing order
int		compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second) // <
		return (1);
	else if (*(int *)first < *(int *)second) // >
		return (-1);
	else
		return (0);
}

int		main(void)
{
	int	arr[] = { 8, 2, 5, 3, 6, 11 };
	//float	arr[] = { 8.1f, 2.4f, 5.6f, 3.2f, 6.1f, 11.0f };	// 하면 여기 모든 int를 float으로 바꿔주고 돌리면 된다.
	int	n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return (0);
}

