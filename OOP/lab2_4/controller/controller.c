#include "validator.h"
#include "repository.h"

unsigned char	send_reg_num_validator(unsigned long reg_num)
{
	return (reg_num_valid(reg_num));
}

unsigned char	send_category_validator(char category[10])
{
	return (category_valid(category));
}

void			send_car_repository(unsigned long reg_num, char model[100], char category[10])
{
	repo_add_car(reg_num, model, category);
}

unsigned char	send_model_validator(char model[100])
{
	return (model_valid(model));
}