#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "list.h"

	unsigned char	send_reg_num_validator(long reg_num);
	unsigned char	send_category_validator(char category[]);
	unsigned char	send_car_repository(unsigned long reg_num, char model[], char category[]);
	unsigned char	send_model_validator(char model[]);
	unsigned char	check_car_exists(unsigned long reg_num);
	void			send_car_edit(unsigned long reg_num, char model[], char category[]);
	unsigned char	send_loan_request(unsigned long reg_num);
	void			send_clear_repo(Node **start);
	Node			*send_sort_by_category(Node *start);
	Node			*send_sort_by_model(Node *start);

#endif