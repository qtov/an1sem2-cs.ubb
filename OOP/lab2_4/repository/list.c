#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node			*new_node(Car car)
{
	Node	*p;

	p = malloc(sizeof(Node) + 1);
	p->data = car;
	p->next = NULL;
	return (p);
}

void			unshift_node(Node **start, Car car)
{
	Node	*p;

	if (*start == NULL)
		*start = new_node(car);
	else
	{
		p = new_node(car);
		p->next = *start;
		*start = p;
	}
}

void			push_node(Node **start, Car car)
{
	Node	*p;
	Node	*t;

	if (*start == NULL)
		*start = new_node(car);
	else
	{
		p = new_node(car);
		t = *start;
		while (t->next != NULL)
			t = t->next;
		t->next = p;
	}
}

void			show_node(Node *start)
{
	Node	*p;

	p = start;
	while (p != NULL)
	{
		printf("%lu, %s, %s, %hhu", p->data.reg_num, p->data.model, p->data.category, p->data.loaned);
		printf("  ->  ");
		p = p->next;
	}
	printf("\n");
}

void			edit_node(Node **start, Car car)
{
	Node *p;

	p = *start;
	while (p != NULL)
	{
		if (p->data.reg_num == car.reg_num)
		{
			strcpy(p->data.model, car.model);
			strcpy(p->data.category, car.category);
			break;
		}
		p = p->next;
	}
}

int				node_exists(Node *start, Car car)
{
	Node *p;

	p = start;
	while (p != NULL)
	{
		if (p->data.reg_num == car.reg_num)
			return (1);
		p = p->next;
	}
	return (0);
}

void			clear_list(Node **start)
{
	Node	*p;
	
	while (*start != NULL)
	{
		p = *start;
		*start = (*start)->next;
		free(p);
	}
}

unsigned char	loan_car(Node *start, unsigned long reg_num)
{
	Node *p;

	p = start;
	while (p != NULL)
	{
		if (p->data.reg_num == reg_num)
		{
			p->data.loaned = !p->data.loaned;
			return (p->data.loaned);
		}
		p = p->next;
	}
	return (42); //Big problem if reached here.
}

Node			*sort_by_model(Node *start)
{
	Node			*p;
	Node			*new_list = NULL;
	unsigned char	sorted = 0;
	
	p = start;
	while (p != NULL)
	{
		push_node(&new_list, p->data);
		p = p->next;
	}
	while (!sorted)
	{
		p = new_list;
		sorted = 1;
		
		if (p != NULL)
		{
			if (p->next != NULL)
			{
				if (strcmp(p->data.model, p->next->data.model) > 0)
				{
					Node	*temp = p;
					
					new_list = p->next;
					temp->next = new_list->next;
					new_list->next = temp;
					sorted = 0;
				}
				else
				{
					while (p->next->next != NULL)
					{
						if (strcmp(p->next->data.model, p->next->next->data.model) > 0)
						{
							Node	*temp = p->next;
							
							p->next = temp->next;
							temp->next = p->next->next;
							p->next->next = temp;
							sorted = 0;
						}
						p = p->next;
					}
				}
			}
		}
	}
	return (new_list);
}

Node			*sort_by_category(Node *start)
{
	Node			*p;
	Node			*new_list = NULL;
	unsigned char	sorted = 0;
	
	p = start;
	while (p != NULL)
	{
		push_node(&new_list, p->data);
		p = p->next;
	}
	while (!sorted)
	{
		p = new_list;
		sorted = 1;
		if (p != NULL)
		{
			if (p->next != NULL)
			{
				if (strcmp(p->data.category, p->next->data.category) > 0)
				{
					Node	*temp = p;
					
					new_list = p->next;
					temp->next = new_list->next;
					new_list->next = temp;
					sorted = 0;
				}
				else
				{
					while (p->next->next != NULL)
					{
						if (strcmp(p->next->data.category, p->next->next->data.category) > 0)
						{
							Node	*temp = p->next;
							
							p->next = temp->next;
							temp->next = p->next->next;
							p->next->next = temp;
							sorted = 0;
						}
						p = p->next;
					}
				}
			}
		}
	}
	return (new_list);
}