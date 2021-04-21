#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<string.h>
#define	FUNDLEN	50

struct fortune
{
	char	bank_name[FUNDLEN];
	double	bank_saving;
	char	fund_name[FUNDLEN];
	double	fund_invest;
};

//double	sum(double, double);
double	sum(const struct fortune *my_fortune);

int		main(void)
{
	struct fortune	my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		//sum(my_fortune.bank_saving, my_fortune.fund_invest)
		sum(&my_fortune)
	);

	return (0);
}

/*
double	sum(struct fortune mf)	//구조체가 복사된다.(그래서 주소 다름)
{
	return mf.bank_saving + mf.fund_invest;
}
*/

double	sum(const struct fortune *mf)	//복사되면 시간도 걸리고 용량도 차지하기 때문에 포인터를 많이 쓴다.
{
	return mf->bank_saving + mf->fund_invest;
}
// 값을 바꾸려고 하는게 아니기 때문에 const를 쓰는 것이 좋다.

/*
double	sum(double x, double y) // TODO: try pointers
{
	return x + y;
}
*/
/*
double	sum(const double *x, const double *y)
{
	return *x + *y;
}
*/