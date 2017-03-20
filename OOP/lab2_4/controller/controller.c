#include "validator.h"
#include "controller.h"
#include "repository.h"

/* Sends the registration number to the validator and return if it's valid or not */
unsigned char	send_reg_num_validator(long reg_num)
{
	return (reg_num_valid(reg_num));
}

/* Sends the category to the validator and return if it's valid or not */
unsigned char	send_category_validator(char category[])
{
	return (category_valid(category));
}

/* Sends the components of the car to the repository and returns the response id(1 - success, 0 - failure) */
unsigned char	send_car_repository(Node **list, unsigned long reg_num, char model[], char category[])
{
	return (repo_add_car(list, reg_num, model, category));
}

/* Sends the model to the validator and return if it's valid or not */
unsigned char	send_model_validator(char model[])
{
	return (model_valid(model));
}

/* Checks if a car with the same registration number exists */
unsigned char	check_car_exists(Node *list, unsigned long reg_num)
{
	return (car_exists(list, reg_num));
}

/* Sends the components of the car for the repo to edit */
void			send_car_edit(Node **list, unsigned long reg_num, char model[], char category[])
{
	car_edit(list, reg_num, model, category);
}

/* Returns if the loan request was successful or not */
unsigned char	send_loan_request(Node **list, unsigned long reg_num)
{
	return (loan_request(list, reg_num));
}

/* Sends the signal to clear the repository to avoid memory leaks */
void			send_clear_repo(Node **start)
{
	clear_repo(start);
}

/* Returns the beginning of the list sorted by category */
Node			*send_sort_by_category(Node *start)
{
	return (repo_sort_by_category(start));
}

/* Returns the beginning of the list sorted by model */
Node			*send_sort_by_model(Node *start)
{
	return (repo_sort_by_model(start));
}

/* Asks for the list from the repo */
Node			*request_list_creation(void)
{
	return (repo_construct());
}