#include "validator.h"
#include "controller.h"
#include "repository.h"

unsigned char	send_reg_num_validator(long reg_num)
{
	return (reg_num_valid(reg_num));
}

unsigned char	send_category_validator(char category[])
{
	return (category_valid(category));
}

unsigned char	send_car_repository(Node **list, unsigned long reg_num, char model[], char category[])
{
	return (repo_add_car(list, reg_num, model, category));
}

unsigned char	send_model_validator(char model[])
{
	return (model_valid(model));
}

unsigned char	check_car_exists(Node *list, unsigned long reg_num)
{
	return (car_exists(list, reg_num));
}

void			send_car_edit(Node **list, unsigned long reg_num, char model[], char category[])
{
	car_edit(list, reg_num, model, category);
}

unsigned char	send_loan_request(Node **list, unsigned long reg_num)
{
	return (loan_request(list, reg_num));
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

Node			*request_list_creation(void)
{
	return (repo_construct());
}