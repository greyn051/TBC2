#include	<stdio.h>

void	func()
{
	int		i = 123;
	printf("%lld\n", (long long)&i);
}

int		main(void)
{
	const char	*message = "Banana";
	printf("Apple and %s", message);
	printf("\n");

	void	(*f_ptr)() = func;	// address of a function

	printf("%lld\n", (long long)&message);
	printf("%lld\n", (long long)&f_ptr);
	printf("%lld\n", (long long)message);
	printf("%lld\n", (long long)f_ptr);
	printf("%lld\n", (long long)main);

	func();

	return (0);
}
