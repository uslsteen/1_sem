#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#pragma warning (disable : 4996)

bool Input_array(char* text, int text_size);

char* My_strcat(char* str_beg, const char* str_end, int* size_str_beg);

#define CHECK_INPUT(COND) if (!COND)					   \
							{								\
								printf("Error with input\n");\
								return 0;					  \
							}

int main()
{
	char* str_beg; 
	char* str_end;
	char* str_result;
	int beg_size = 0, real_beg_size = 0, end_size = 0, real_end_size = 0, size_for_cat = 0, check_input = 0, i = 0;

	printf("Please, enter beg_buf size for calloc (with null_terminated).\n");
	scanf("%d%*c", &beg_size);

	printf("Please, enter real beg_buf size for inut\n");
	scanf("%d%*c", &real_beg_size);

	str_beg = (char*)calloc(beg_size, sizeof(str_beg[0]));
	assert(str_beg);

	printf("Please, enter beg_buf\n");
	check_input = Input_array(str_beg, real_beg_size);

	CHECK_INPUT(check_input);

	printf("Please, enter end_buf size for calloc (with null_terminated).\n");
	scanf("%d%*c", &end_size);

	printf("Please, enter end_buf size for input.\n");
	scanf("%d%*c", &real_end_size);

	str_end = (char*)calloc(end_size, sizeof(str_end[0]));
	assert(str_end);

	printf("Please, enter end_buf.\n");
	check_input = Input_array(str_end, real_end_size);
	CHECK_INPUT(check_input);

	size_for_cat = beg_size;

	str_result = My_strcat(str_beg, str_end, &size_for_cat);

	for (i = 0; i < size_for_cat; i++)
	{
		printf("%c", str_result[i]);
	}
	//printf("%s\n", str_result);

	//Output_array(str_result, size_str_beg);

	return 0;
}

bool Input_array(char* text, int text_size)
{
	int i = 0;

	assert(text);

	for (i = 0; i < text_size - 1; i++)
	{
		scanf("%c", &text[i]);
	}

	text[text_size - 1] = '\0';

	return true;
}

char* My_strcat(char* str_beg, const char* str_end, int* size_str_beg)
{
	char* new_str;
	int real_size_end = 0, real_size_beg = 0, delta = 0, new_size = 0;

	assert(str_beg != NULL);
	assert(str_end != NULL);
	assert(size_str_beg > 0);

	real_size_end = strlen(str_end) + 1; 
	real_size_beg = strlen(str_beg) + 1;
	
	delta = *size_str_beg - real_size_beg;

	if (delta < real_size_end)
	{
		new_size = *size_str_beg + real_size_end - delta;
		new_str = (char*)realloc(str_beg, sizeof(str_beg[0]) * (new_size));
		assert(new_str);

		*size_str_beg = new_size;
	}

	new_str = strcat(str_beg, str_end);

	new_size = strlen(new_str);
	*size_str_beg = new_size;

	return new_str;
}

