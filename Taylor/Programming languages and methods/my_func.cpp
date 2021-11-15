#include "my_func.h"
#include <stdio.h>


// exp ^x
double myExp(double x, int N, double* eps) 
{
	double res = x;
	double c = 1;
	res += c;

	for (double n = 1; n < N; n++)
	{
		c *= x / (n + 1);
		res += c;
	}
	*eps = c < 0.0 ? -c : c;

	return res;
}

// ln(1+x) for -1 < x < 1
double myLn(double x, int N, double* eps) 
{
	double res = 0;
	double c = x;
	res += c;

	for (double n = 1; n < N; n++)
	{
		c *= -(x / (n + 1)) * n;
		res += c;
	}
	*eps = c < 0.0 ? -c : c;

	return res;
}

// hyperbolic sine
double mySh(double x, int N, double* eps) 
{
	double res = 0;
	double c = x;
	res += c;

	for (double n = 1; n < N; n++)
	{
		c *= (x / (4 * n * n + 2 * n)) * x;
		res += c;
	}
	*eps = c < 0.0 ? -c : c;

	return res;
}

// hyperbolic cosine
double myCh(double x, int N, double* eps)
{
	double res = 0;
	double c = 1;
	res += c;

	for (double n = 0; n < N; n++)
	{
		c *= (x / (4 * n * n + 6 * n + 2.0)) * x;
		res += c;
	}
	*eps = c < 0.0 ? -c : c;

	return res;
}

// hyperbolic tangen
double myTan(double x, int N, double* eps)
{
	return mySh(x, N, eps) / (myCh(x, N, eps));
}