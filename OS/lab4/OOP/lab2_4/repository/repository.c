#include "repository.h"
#include "car.h"
#include <string.h>
#include "list.h"

/* Constructs an empty list */
Node			*repo_construct(void)
{
	Node	*list_h = NULL;
	
	return (list_h);
}

/* Adds a car if it does not exist (reg_num is the unique key) */
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

/* Returns 1 if car exists, else 0 */
unsigned char	car_exists(Node *list, unsigned long reg_num)
{
	Car		car;
	
	car.reg_num = reg_num;
	strcpy(car.model, "");
	strcpy(car.category, "");
	car.loaned = 0;
	return (node_exists(list, car));
}

/* Edits the car with the given reg_num */
void			car_edit(Node **list, unsigned long reg_num, char model[], char category[])
{
	Car		car;
	
	car.reg_num = reg_num;
	strcpy(car.model, model);
	strcpy(car.category, category);
	car.loaned = 0;
	edit_node(list, car);
}

/* Returns the loan status after the request was sent to the list */
unsigned char	loan_request(Node **list, unsigned long reg_num)
{
	return (loan_car(list, reg_num));
}

/* Clears the repository */
void			clear_repo(Node **start)
{
	clear_list(start);
}

/* Returns a new list sorted by category */
Node			*repo_sort_by_category(Node *start)
{
	return (sort_by_category(start));
}

/* Returns a new list sorted by model */
Node			*repo_sort_by_model(Node *start)
{
	return (sort_by_model(start));
}