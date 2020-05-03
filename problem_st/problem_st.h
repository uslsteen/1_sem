#ifndef __PROBLEM_ST__
#define __PROBLEM_ST__

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cassert>

#pragma warning (disable:4996)


class Syntax_Tree
{
private:
	int value;
	const char* str;

public:
	explicit Syntax_Tree(const char* string); //constructor of syntax_tree

	int GetNum();  // only integer numbers
	int GetTemp(); // operations like mul and div
	int GetExpr(); // operations like add and sub
	int GetSqr();

	int GetBrack(); //syntax separations parts of math expression

	void GetSpaces(); 

	int GetVal();


	//sqr
};

#endif

