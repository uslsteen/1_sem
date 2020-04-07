#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma warning (disable : 4996)
enum command_name
{
	MOVI = 0,
	ADD = 1, 
	SUB = 2, 
	MUL = 3,
	DIV = 4, 
	IN = 5,
	OUT = 6,
};

enum reg
{
	A = 0,
	B = 1,
	C = 2,
	D = 3,
};

struct command_t
{
	enum command_name name;

	enum reg r_reg, l_reg;
	enum reg reg;

	int data;
	int cond;

};

const int FALSE = 0;
const int TRUE = 1;
const int STOP = 2;

int Read_asm_code(struct command_t* com);
int Read_regs(struct command_t* com);
int Read_reg(struct command_t* com);
int Convert_code(struct command_t* com);


int main()
{	
	struct command_t com; 

	while (1)
	{
		if (Read_asm_code(&com) == STOP)
		{
			break;
		}
		if (com.cond == FALSE)
		{
			printf("ERROR");
			break;
		}
		
		printf("0x%x ", Convert_code(&com));
	}

	return 0;
}


int Read_asm_code(struct command_t* com)
{
	char cmd_name[5] = { 0 };
	com->cond = TRUE;

	if (scanf("%s ", cmd_name) != 1)
	{
		return STOP;
	}

	if (strcmp(cmd_name, "MOVI") == 0)
	{
		com->name = MOVI;
		if (scanf("%d", &(com->data)) != 1)
		{
			com->cond = FALSE;
		}

		if ((com->data > 127) || (com->data < 0))
		{
			com->cond = FALSE;
		}
	}
	else if (strcmp(cmd_name, "ADD") == 0)
	{
		com->name = ADD;
		com->cond = Read_regs(com);
	}
	else if (strcmp(cmd_name, "MUL") == 0)
	{
		com->name = MUL;
		com->cond = Read_regs(com);
	}
	else if (strcmp(cmd_name, "SUB") == 0)
	{
		com->name = SUB;
		com->cond = Read_regs(com);
	}
	else if (strcmp(cmd_name, "DIV") == 0)
	{
		com->name = DIV;
		com->cond = Read_regs(com);
	}
	else if (strcmp(cmd_name, "IN") == 0)
	{
		com->name = IN;
		com->cond = Read_reg(com);
	}
	else if (strcmp(cmd_name, "OUT") == 0)
	{
		com->name = OUT;
		com->cond = Read_reg(com);
	}
	else
	{
		com->cond = FALSE;
	}

	return TRUE;
}


int Read_regs(struct command_t* com)
{
	char arg1 = 0, arg2 = 0;

	if (scanf("%c, ", &arg1) != 1 || (arg1 < 'A') || (arg1 >= 'A' + 4))
	{
		return FALSE;
	}

	com->l_reg = (enum reg)(arg1 - 'A');

	if (scanf("%c", &arg2) != 1 || (arg2 < 'A') || (arg2 >= 'A' + 4))
	{
		return FALSE;
	}

	com->r_reg = (enum reg)(arg2 - 'A');

	return TRUE;
}

int Read_reg(struct command_t* com)
{
	char arg = 0;

	if (scanf("%c", &arg) != 1 || (arg < 'A') || (arg >= 'A' + 4))
	{
		return FALSE;
	}

	com->reg = (enum reg)(arg - 'A');

	return TRUE;
}

int Convert_code(struct command_t* com)
{
	switch (com->name)
	{
	case MOVI:
		{
			return ((0x0 << 7) | (com->data));
		}
	case ADD:
		{
			return ((0x8 << 4) | (com->l_reg << 2) | (com->r_reg));
		}
	case SUB:
		{
			return ((0x9 << 4) | (com->l_reg << 2) | (com->r_reg));
		}
	case MUL:
		{
			return ((0xA << 4) | (com->l_reg << 2) | (com->r_reg));
		}
	case DIV:
		{
			return ((0xB << 4) | (com->l_reg << 2) | (com->r_reg));
		}
	case IN:
		{
			return ((0x30 << 2) | (com->reg));
		}
	case OUT:
		{
			return ((0x31 << 2) | (com->reg));
		}
	default:
		break;
	}

	return 0;
}