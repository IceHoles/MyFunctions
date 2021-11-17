#include "my_func.h"
#include <stdio.h>
#include <string.h>


int main()
{
	double eps;
	char function_name[6];
	double x = 0;
	int N = 0;

	printf("Enter a valid function name, x and N\nList of available functions:\nexp, ln, h_sin, h_cos, h_tan\n>>");
	scanf_s("%5s %lf %d", function_name, 6, &x, &N);


	if (strcmp(function_name, "exp") == false)
	{
		printf("e^%.15f = %.15f\n", x, myExp(x, N, &eps));
		printf("eps ~ %e\n", eps);
	}

	else if (strcmp(function_name, "ln") == false)
	{
		if (x > 1 or -x > 1)
		{
			printf("x should be in range of -1 < x < 1\n");
		}
		else
		{
			printf("ln(%.15f) = %.15f\n", x, myLn(x, N, &eps));
			printf("eps ~ %e\n", eps);
		}
	}

	else if (strcmp(function_name, "h_sin") == false)
	{
		printf("Hyperbolic sine of (%.15f) = %.15f\n", x, mySh(x, N, &eps));
		printf("eps ~ %e\n", eps);
	}

	else if (strcmp(function_name, "h_cos") == false)
	{
		printf("Hyperbolic cosine of (%.15f) = %.15f\n", x, myCh(x, N, &eps));
		printf("eps ~ %e\n", eps);
	}

	else if (strcmp(function_name, "h_tan") == false)
	{
		printf("Hyperbolic tangen of (%.15f) = %.15f\n", x, myTan(x, N, &eps));
		printf("eps ~ %e\n", eps);
	}

	else printf("%s... ? Enter a valid function name\n", function_name);

	int a = 0;
	scanf_s("%d", &a);
	return 0;
}