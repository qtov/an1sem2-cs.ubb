#include "repository.h"
#include "car.h"
#include <string.h>
#include "list.h"

Node			*repo_construct(void)
{
	Node	*list_h = NULL;
	
	return (list_h);
}

unsigned char	repo_add_car(Node **list, unsigned long reg_num, char model[], char category[])
{
	Car		car;

	car.reg_num = reg_num;
	strcpy(car.model, model);
	strcpy(car.category, category);
	car.loaned = 0;
	if (!node_exists(*list, car))
	{
		push_node(list, car);
	}
	else
		return (0);
	return (1);
}

unsigned char	car_exists(Node *list, unsigned long reg_num)
{
	Car		car;
	
	car.reg_num = reg_num;
	strcpy(car.model, "");
	strcpy(car.category, "");
	car.loaned = 0;
	return (node_exists(list, car));
}

void			car_edit(Node **list, unsigned long reg_num, char model[], char category[])
{
	Car		car;
	
	car.reg_num = reg_num;
	strcpy(car.model, model);
	strcpy(car.category, category);
	car.loaned = 0;
	edit_node(list, car);
}

unsigned char	loan_request(Node **list, unsigned long reg_num)
{
	return (loan_car(list, reg_num));
}

void			clear_repo(Node **start)
{
	clear_list(start);
}

Node			*repo_sort_by_category(Node *start)
{
	return (sort_by_category(start));
}

Node			*repo_sort_by_model(Node *start)
{
	return (sort_by_model(start));
}