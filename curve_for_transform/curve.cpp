#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#pragma warning (disable: 4996 4090) //disable for VisualStudio

typedef struct
{
	double param_a, param_b, param_p;
	double Ax, Ay;
	double angle;
	int type;
} Second_Order_Curve;

enum
{
	ELLIPSE = 1,
	HYPERBOLA = 2,
	PARABOLA = 3,
};

int Checking_type(Second_Order_Curve* curve, char* array);

void Input(Second_Order_Curve* curve);

void Transform_The_Line(Second_Order_Curve* curve, double* A, double* B2, double* C, double* D, double* E, double* F);

int main()
{
	char name[15];

	int check_type = 0, check_snf = 0; // variables for checking
	double A = 0, B2 = 0, C = 0, D = 0, E = 0, F = 0; // coeffs of curve

	Second_Order_Curve curve1;

	printf("Enter the name:\n");

	check_snf = scanf("%s", &name);
	assert(check_snf == 1);

	check_type = Checking_type(&curve1, name);

	if (check_type == 0)
	{
		printf("Error with writing type of curve.\n");
	}

	printf("Please, input param_s for curve.\n");

	Input(&curve1);

	Transform_The_Line(&curve1, &A, &B2, &C, &D, &E, &F);

	printf("A = %lf, 2B = %lf, C = %lf, D = %lf E = %lf, F = %lf\n", A, B2, C, D, E, F);

	return 0;
}

int Checking_type(Second_Order_Curve* curve, char* array)
{
	assert(curve);
	assert(array);

	if (strcmp(array, "Ellipse") == 0)
	{
		curve->type = ELLIPSE;
		return ELLIPSE;
	}

	else
		if (strcmp(array, "Hyperbola") == 0)
		{
			curve->type = HYPERBOLA;
			return HYPERBOLA;
		}

		else
			if (strcmp(array, "Parabola") == 0)
			{
				curve->type = PARABOLA;
				return PARABOLA;
			}

	return 0;
}


void Input(Second_Order_Curve* curve)
{
	int check_snf = 0;
	double param_a = 0, param_b = 0, param_p = 0, Ax = 0, Ay = 0, angle = 0;

	if (curve->type == ELLIPSE || curve->type == HYPERBOLA)
	{
		check_snf = scanf("%lf%lf%lf%lf%lf", &param_a, &param_b, &Ax, &Ay, &angle);
		assert(check_snf == 5);

		curve->param_a = param_a;
		curve->param_b = param_b;
		curve->Ax = Ax;
		curve->Ay = Ay;
		curve->angle = angle;
	}
	else

		if (curve->type == PARABOLA)
		{
			check_snf = scanf("%lf%lf%lf%lf", &param_p, &Ax, &Ay, &angle);
			assert(check_snf == 4);

			curve->param_a = param_p;
			curve->Ax = Ax;
			curve->Ay = Ay;
			curve->angle;
		}
}


void Transform_The_Line(Second_Order_Curve* curve, double* A, double* B2, double* C, double* D, double* E, double* F)
{
	double param_a2 = (curve->param_a) * (curve->param_a), param_b2 = (curve->param_b) * (curve->param_b), param_p = curve->param_p; // param_a2 == (param_a)^2
	double Ax = curve->Ax, Ay = curve->Ay;
	double sin_ = 0, cos_ = 0;
	double angle = curve->angle;

	sin_ = sin(angle) * sin(angle);
	cos_ = cos(angle) * cos(angle);

	if (curve->type == ELLIPSE)
	{
		*A = param_a2 * sin_ + param_b2 * cos_;

		*B2 = param_a2 * sin(2 * angle) - param_b2 * sin(2 * angle);

		*C = param_a2 * cos_ + param_b2 * sin_;

		*D = 2 * param_a2 * Ay * sin(angle) + 2 * param_b2 * Ax * cos(angle);

		*E = 2 * param_a2 * Ay * cos(angle) - 2 * param_b2 * Ax * sin(angle);

		*F = Ax * Ax * param_b2 + Ay * Ay * param_a2 - param_a2 * param_b2;
	}

	else
		if (curve->type == HYPERBOLA)
		{
			*A = param_b2 * cos_ - param_a2 * sin_;

			*B2 = - (param_a2 * sin(2 * angle)) - param_b2 * sin(2 * angle);

			*C =  param_b2 * sin_ - param_a2 * cos_;

			*D = 2 * param_b2 * Ax * cos(angle) - 2 * param_a2 * Ay * sin(angle);

			*E = - 2 * param_a2 * Ay * cos(angle) - 2 * param_b2 * Ax * sin(angle);

			*F = Ax * Ax * param_b2 - Ay * Ay * param_a2 - param_a2 * param_b2;
		}

		else
			if (curve->type == PARABOLA)
			{
				*A = sin_;

				*B2 = sin(2 * angle);

				*C = cos_;

				*D = 2 * Ay * sin(angle) - 2 * param_p * cos(angle);

				*E = 2 * Ay * cos(angle) + 2 * param_p * sin(angle);

				*F = 2 * Ay * Ay - 2 * Ax * param_p;
			}
}