#include <string.h>
#include <stdio.h>
#include <ctype.h>

unsigned char	reg_num_valid(unsigned long reg_num)
{
	if (reg_num > 0 && reg_num < 1000000000)
		return (1);
	else
		return (0);
}

unsigned char	category_valid(char category[10])
{
	const unsigned char	arr_len = 4;
	const char*			valid_categ[arr_len];
	unsigned char		i; /* aka index */
	
	valid_categ[0] = "mini";
	valid_categ[1] = "sport";
	valid_categ[2] = "suv";
	valid_categ[3] = "etc";
	
	for (i = 0; i < strlen(category); i++)
		category[i] = tolower(category[i]);
	for (i = 0; i < arr_len; i++)
		if (strcmp(valid_categ[i], category) == 0) /* If the two strings are equal. */
			return (1);
	return (0);
}

unsigned char	model_valid(char model[100])
{
	if (strlen(model) == 0 || strlen(model) > 50 || (!isalpha(model[0]) && !isdigit(model[0])))
		return (0);
	return (1);
}