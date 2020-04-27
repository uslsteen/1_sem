#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>



double a = 0, b = 0, c = 0;

struct func_deriv
{
	double func;
	double deriv;
};

static struct func_deriv func(double num);

typedef struct func_deriv (*func_t)(double);

static double Newton_method(func_t f, double x, double accuracy);

enum
{
	MAX_ITERCOUNT = 1000,
};


#pragma warning (disable : 4996)


int main()
{
	double x = 0, sol = 0;
	double accuracy = 1e-5;
	int check = 0;

	check = scanf("%lf%lf%lf%lf", &a, &b, &c, &x);

	assert(check == 4);

	sol = Newton_method(func, x, accuracy);

	printf("%.5lf\n", sol);
}


static double Newton_method(func_t f, double x, double accuracy)
{
	struct func_deriv fval = f(x);
	int itercount = 0;

	while (fabs(fval.func) > accuracy)
	{
		x = x - ((fval.func) / (fval.deriv));
		fval = f(x);

		itercount++;

		if ((itercount > MAX_ITERCOUNT) || fabs(fval.deriv) < DBL_EPSILON)
		{
			printf("0.0");
			exit(0);
		}
	}

	return x;
}


static struct func_deriv func(double x)
{
	struct func_deriv res;

	res.func = a * x * x * sin(x) + b * x * cos(x) + c;
	res.deriv = 2 * a * x * sin(x) + a * x * x * cos(x) + b * cos(x) - b * x * sin(x);

	return res;
}