#include "testing.h"
#include <assert.h>
#include "validator.h"
#include <string.h>
#include "repository.h"
#include "list.h"
#include <stdio.h>

void	test_repository(void)
{
	Node	*test_list = repo_construct();
	Node	*p;
	char	category[10];
	
	(void)p;
	assert(test_list == NULL);
	strcpy(category, "miNi");
	assert(repo_add_car(&test_list, 123, "just a model", category) == 1);
	assert(test_list->data.reg_num == 123 &&  strcmp(test_list->data.category, category) == 0 && strcmp(test_list->data.model, "just a model") == 0);
	assert(car_exists(test_list, 123) == 1);
	assert(car_exists(test_list, 1234) == 0);
	strcpy(category, "SuV");
	car_edit(&test_list, 123, "another model", category);
	assert(test_list->data.reg_num == 123 &&  strcmp(test_list->data.category, category) == 0 && strcmp(test_list->data.model, "another model") == 0);
	assert(loan_request(&test_list, 123) == 1);
	assert(loan_request(&test_list, 123) == 0);
	assert(loan_request(&test_list, 123) == 1);
	strcpy(category, "Etc");
	assert(repo_add_car(&test_list, 123, "won't add", category) == 0);
	assert(repo_add_car(&test_list, 1234, "ab will add", category) == 1);
	p = repo_sort_by_category(test_list);
	/*printf("%lu, %s, %s\n%lu, %s, %s\n", p->data.reg_num, p->data.model, p->data.category, p->next->data.reg_num, p->next->data.model, p->next->data.category);*/
	assert(p->data.reg_num == 1234 && p->next->data.reg_num == 123);
	clear_repo(&p);
	assert(p == NULL);
	p = repo_sort_by_model(test_list);
	/*printf("%lu, %s, %s\n%lu, %s, %s\n", p->data.reg_num, p->data.model, p->data.category, p->next->data.reg_num, p->next->data.model, p->next->data.category);*/
	assert(p->data.reg_num == 1234 && p->next->data.reg_num == 123);
	clear_repo(&p);
	assert(p == NULL);
}

void	test_validator(void)
{
	char	category[10];
	
	assert(reg_num_valid(123456789) == 1);
	assert(reg_num_valid(1234567890) == 0);
	assert(reg_num_valid(1) == 1);
	assert(reg_num_valid(-30) == 0);
	strcpy(category, "mini");
	assert(category_valid(category) == 1);
	strcpy(category, "SpOrT");
	assert(category_valid(category) == 1);
	strcpy(category, "SUV");
	assert(category_valid(category) == 1);
	strcpy(category, "etc");
	assert(category_valid(category) == 1);
	strcpy(category, "smething");
	assert(category_valid(category) == 0);
	strcpy(category, "else");
	assert(category_valid(category) == 0);
	assert(model_valid("asd") == 1);
	assert(model_valid("a") == 0);
	assert(model_valid("dqwdqwdSADSD231231") == 1);
	assert(model_valid("Sdadw2313wda") == 1);
}

void	test_functions(void)
{
	test_validator();
	test_repository();
}
