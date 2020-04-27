#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <fenv.h>

#pragma warning (disable : 4996)

unsigned as_uint(float num);
float as_float(unsigned num);
void print_exp_frac(float num);


enum
{
	SGN_OFFSET = 31,
	SGN_MASK = 1,

	
	EXP_OFFSET = 23,
	EXP_MASK = 0xFF,

	
	FRAC_OFFSET = 0,
	FRAC_MASK = 0x7FFFFF,

	INV_MASK = 0xAAAAAAAA
};


int main()
{
	int check = 0;
	float num1 = 0, num2 = 0, upquot = 0, quot = 0;
	unsigned u_num = 0, sign = 0, exp = 0, frac = 0;


	check = scanf("%f%f", &num1, &num2);
	assert(check == 2);

	fesetround(FE_UPWARD);
	upquot = num1 / num2;

	fesetround(FE_DOWNWARD);
	quot = num1 / num2;

	print_exp_frac(quot); //if you can convert the number exactly

	if (upquot != quot) 
	{ 
		upquot = nextafterf(quot, num1);
		print_exp_frac(upquot);
	}

	return 0;
}

void print_exp_frac(float f)
{
	unsigned num = as_uint(f), exp = 0, frac = 0;
	
	exp = ((num >> EXP_OFFSET) & EXP_MASK);
	frac = ((num >> FRAC_OFFSET) & FRAC_MASK);

	printf("0x%x 0x%x ", exp, frac);
}

unsigned as_uint(float num)
{
	return *(unsigned*)&num;
}

float as_float(unsigned num)
{
	return *(float* )& num;
}