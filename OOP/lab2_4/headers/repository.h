#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "list.h"

	unsigned char	repo_add_car(Node **list, unsigned long reg_num, char model[], char category[]);
	unsigned char	car_exists(Node *list, unsigned long reg_num);
	void			car_edit(Node **list, unsigned long reg_num, char model[], char category[]);
	unsigned char	loan_request(Node **list, unsigned long reg_num);
	void			clear_repo(Node **start);
	Node			*repo_sort_by_category(Node *start);
	Node			*repo_sort_by_model(Node *start);
	Node			*repo_construct(void);

#endif