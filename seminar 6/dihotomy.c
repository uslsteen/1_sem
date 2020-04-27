#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <fenv.h>

double a = 0, b = 0, c = 0;

static double func(double x);

typedef double (*func_t)(double);

static double dihotomy(func_t f, double xl, double xr, double prec);

static void swap(double* x1, double* x2);

#pragma warning (disable : 4996)


int main()
{
	double N = 0, sol = 0;
	double accuracy = 1e-6;

	scanf("%lf%lf%lf%lf", &a, &b, &c, &N);

	if (signbit(func(-N)) == signbit(func(N))) //determinate sign of num
	{
		printf("%s\n", "0.0");
		return 0;
	}

	sol = dihotomy(func, -N, N, accuracy);

	printf("%.5lf\n", sol);
}

static double func(double x)
{
	return a * x * x * sin(x) + b * x * cos(x) + c;
}

typedef double (*func_t)(double);

static double dihotomy(func_t f, double xl, double xr, double prec)
{
	double fval = 0, xmid = 0;

	if (f(xl) > 0)
	{
		swap(&xl, &xr);
	}

	fval = f(xl);

	assert(fval < 0);
	assert(f(xr) > 0);

	while (fabs(fval) > prec)
	{
		xmid = (xl + xr) / (2.0);
		fval = f(xmid);

		if (fval > 0.0)
		{
			xr = xmid; 
		}
		else
			xl = xmid;
	}

	return xl;
}

static void swap(double* x1, double* x2)
{
	double temp = *x2;
	*x2 = *x1;
	*x1 = temp;
}