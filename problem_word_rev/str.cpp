#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <assert.h>

#pragma warning (disable: 4996 4090)

char* StrRev(char* string, int size);

void swap(char* str_input, char* str_find);

void Input_array(char* text, int size);


int main()
{
	char* str_input;
	char* str_find;
	char* str_ptr;
	int size_input = 0, size_find = 0, i = 0;
	int length = 0;

	scanf("%d%*c", &size_input);

	str_input = (char*)calloc(size_input + 1, sizeof(str_input[0]));
	assert(str_input);

	Input_array(str_input, size_input + 1);

	scanf("%d%*c", &size_find);

	str_find = (char*)calloc(size_find + 1, sizeof(str_find[0]));
	assert(str_find);

	Input_array(str_find, size_find + 1);

	length = 0;

	while ((str_ptr = strstr(str_find + length , str_input)) != NULL)
	{
		StrRev(str_ptr, size_input);
		length += size_input;
	}

	for (i = 0; i < size_find; i++)
	{
		printf("%c", str_find[i]);
	}

	return 0;
}

char* StrRev(char* string, int size)
{
	int i = 0;

	for (i = 0; i < size / 2; i++)
	{
		swap(&string[i], &string[size - i - 1]);
	}

	return string;
}

void swap(char* str_input, char* str_find)
{
	char temp;

	assert(str_input);
	assert(str_find);

	temp = *str_input;
	*str_input = *str_find;
	*str_find = temp;
}

void Input_array(char* text, int size)
{
	int i = 0;

	assert(text != NULL);
	assert(size != 0);
	
	for (i = 0; i < size - 1; i++)
	{
		scanf("%c", &text[i]);
	}

	text[size] = '\0';
}