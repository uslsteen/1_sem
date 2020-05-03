#include "problem_st.h"

int main()
{
	Syntax_Tree tree1("         (    2    ^   2   +     6   )       * 5    +    7         ");

	int res = tree1.GetVal();

	printf("%d", res);
}