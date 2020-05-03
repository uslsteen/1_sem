#include "problem_st.h"


Syntax_Tree::Syntax_Tree(const char* string) :

	str(string),
	value(0)
{
	value = GetExpr();

	if (*str != '\0')
	{
		printf("ERROR");
		assert(0);
	}
}

int Syntax_Tree::GetExpr()
{
	char cur_oper = 0;

	GetSpaces();
	int cur_value = GetTemp();
	GetSpaces();

	int new_value = 0;

	while (*str == '+' || *str == '-')
	{
		cur_oper = *str;
		str++;

		GetSpaces();
		new_value = GetTemp();
		GetSpaces();

		if (cur_oper == '+')
		{
			cur_value += new_value;
		}
		else if (cur_oper == '-')
		{
			cur_value -= new_value;
		}
	}

	return cur_value;
}

int Syntax_Tree::GetTemp()
{
	char cur_oper = 0;

	GetSpaces();
	int cur_value = GetSqr();
	GetSpaces();

	int new_value = 0;

	while (*str == '*' || *str == '/')
	{
		cur_oper = *str; 
		str++;

		GetSpaces();
		new_value = GetSqr();
		GetSpaces();

		if (cur_oper == '*')
		{
			cur_value *= new_value;
		}
		else if (cur_oper == '/')
		{
			cur_value /= new_value;
		}	
	}

	return cur_value;
}

int Syntax_Tree::GetNum()
{
	char cur_value = 0;


	while (*str >= '0' && *str <= '9')
	{
		cur_value = cur_value * 10 + (*str - '0');
		str++;
	}

	return cur_value;
}


int Syntax_Tree::GetVal()
{
	return value;
}


int Syntax_Tree::GetBrack()
{
	int cur_value = 0;

	if (*str == '(')
	{
		str++;

		GetSpaces();
		cur_value = GetExpr();
		GetSpaces();

		if (*str != ')')
		{
			printf("ERROR");
		}

		str++;
		return cur_value; 
	}

	return GetNum();
}


int Syntax_Tree::GetSqr()
{
	char cur_oper = 0;
	int new_value = 0;
	
	GetSpaces();
	int cur_value = GetBrack();
	GetSpaces();

	while (*str == '^')
	{
		cur_oper = *str;
		str++;

		GetSpaces();
		new_value = GetBrack();
		GetSpaces();

		cur_value = pow(cur_value, new_value);
	}

	return cur_value;
}

void Syntax_Tree::GetSpaces()
{
	while (*str == ' ' || *str == '\n')
	{
		str++;
	}
}