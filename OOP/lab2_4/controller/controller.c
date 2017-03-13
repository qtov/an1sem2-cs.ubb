#include "validator.h"
#include "controller.h"
#include "repository.h"
#include "list.h" //

unsigned char	send_reg_num_validator(long reg_num)
{
	return (reg_num_valid(reg_num));
}

unsigned char	send_category_validator(char category[])
{
	return (category_valid(category));
}

unsigned char	send_car_repository(unsigned long reg_num, char model[], char category[])
{
	return (repo_add_car(reg_num, model, category));
}

unsigned char	send_model_validator(char model[])
{
	return (model_valid(model));
}

unsigned char	check_car_exists(unsigned long reg_num)
{
	return (car_exists(reg_num));
}

void			send_car_edit(unsigned long reg_num, char model[], char category[])
{
	car_edit(reg_num, model, category);
}

unsigned char	send_loan_request(unsigned long reg_num)
{
	return (loan_request(reg_num));
}


void			send_clear_repo(Node **start)
{
	clear_repo(start);
}

Node			*send_sort_by_category(Node *start)
{
	return (repo_sort_by_category(start));
}

Node			*send_sort_by_model(Node *start)
{
	return (repo_sort_by_model(start));
}