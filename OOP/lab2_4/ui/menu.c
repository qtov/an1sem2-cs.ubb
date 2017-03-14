#include <stdio.h>
#include "controller.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

void			clear_buffer(void)
{
	while (getchar() != '\n')
		;
}

unsigned long	read_reg_num(void)
{
	long	reg_num = -1;
	
	printf("Registration number: ");
	scanf("%ld", &reg_num);
	clear_buffer();
	while (send_reg_num_validator(reg_num) == 0)
	{
		printf("Wrong registration number, retry.\n");
		printf("Registration number: ");
		scanf("%ld", &reg_num);
		clear_buffer();
	}
	return ((unsigned long)reg_num);
}

void			read_model(char model[])
{
	printf("Model: ");
	scanf("%[^\n]", model);
	while (send_model_validator(model) == 0)
	{
		clear_buffer();
		printf("Model too short/long.\n");
		printf("Model: ");
		scanf("%[^\n]", model);
	}
	clear_buffer();
}

void			read_category(char category[])
{
	printf("Category: ");
	scanf("%[^\n]", category);
	while (send_category_validator(category) == 0)
	{
		clear_buffer();
		printf("Wrong category, retry.\n");
		printf("Category: ");
		scanf("%[^\n]", category);
	}
	clear_buffer();
}

void			show_menu(void)
{
	printf("1. Add car.\n");
	printf("2. Edit existing car.\n");
	printf("3. Loan/return car.\n");
	printf("4. View cars based on a criteria.\n");
	printf("5. Sort cars.\n");
	printf("6. Show cars.\n");
	printf("7. Exit.\n");
}

void			ui_add(Node **list)
{
	unsigned long	reg_num = 0;
	char			model[100];
	char			category[10];

	strcpy(model, "");
	strcpy(category, "");
	reg_num = read_reg_num();
	if (reg_num == 0)
		return;
	read_model(model);
	read_category(category);
	if (send_car_repository(list, reg_num, model, category) == 1)
		printf("\nAdd successful.\n\n");
	else
		printf("\nSame registration number already exists.\n\n");
}

void			ui_edit(Node **list)
{
	unsigned long	reg_num;
	char			model[100];
	char			category[10];
	
	strcpy(model, "");
	strcpy(category, "");
	reg_num = read_reg_num();
	if (reg_num == 0)
		return;
	while (check_car_exists(*list, reg_num) == 0)
	{
		printf("Wrong registration number, retry.\n");
		reg_num = read_reg_num();
		if (reg_num == 0)
			return;
	}
	read_model(model);
	read_category(category);
	send_car_edit(list, reg_num, model, category);
}

void			ui_loan(Node **list)
{
	unsigned long	reg_num;
	unsigned char	loan_request;
	
	reg_num = read_reg_num();
	if (reg_num == 0)
		return;
	while (check_car_exists(*list, reg_num) == 0)
	{
		printf("Wrong registration number, retry.\n");
		reg_num = read_reg_num();
		if (reg_num == 0)
			return;
	}
	loan_request = send_loan_request(list, reg_num);
	if (loan_request == 1)
		printf("Car loaned successfully.\n");
	else if (loan_request == 0)
		printf("Car returned.\n");
	else
		printf("Fatal error. Kill the programmer.\n");
}

void			show_submenu(void)
{
	printf("1. Model.\n");
	printf("2. Categorie.\n");
}

void			ui_criteria(Node **list)
{
	unsigned char	input = 0;
	char			model[100];
	char			category[10];
	Node			*tmp_list = NULL;
	
	strcpy(model, "");
	strcpy(category, "");
	show_submenu();
	printf("Choice: ");
	scanf("%hhu", &input);
	if (input == 1)
	{
		clear_buffer();
		read_model(model);
		tmp_list = *list;
		while (tmp_list != NULL)
		{
			if (strcmp(tmp_list->data.model, model) == 0)
			{
				printf("%lu, %s, %s, %hhu", tmp_list->data.reg_num, tmp_list->data.model, tmp_list->data.category, tmp_list->data.loaned);
				printf("  ->  ");
			}
			tmp_list = tmp_list->next;
		}
		printf("\n");
	}
	else if (input == 2)
	{
		clear_buffer();
		read_category(category);
		tmp_list = *list;
		while (tmp_list != NULL)
		{
			if (strcmp(tmp_list->data.category, category) == 0)
			{
				printf("%lu, %s, %s, %hhu", tmp_list->data.reg_num, tmp_list->data.model, tmp_list->data.category, tmp_list->data.loaned);
				printf("  ->  ");
			}
			tmp_list = tmp_list->next;
		}
		printf("\n");
	}
	(void)list;
}

void			ui_sort(Node **list)
{
	unsigned char	input = 0;
	
	show_submenu();
	printf("Choice: ");
	scanf("%hhu", &input);
	if (input == 1)
	{
		Node	*sorted_list;
		Node	*p;

		sorted_list = send_sort_by_model(*list);
		p = sorted_list;
		while (p != NULL)
		{
			Node	*tmp = p;
			
			printf("%lu, %s, %s, %hhu", p->data.reg_num, p->data.model, p->data.category, p->data.loaned);
			printf("  ->  ");
			p = p->next;
			free(tmp);
		}
		printf("\n");
	}
	else if (input == 2)
	{
		Node	*sorted_list;
		Node	*p;

		sorted_list = send_sort_by_category(*list);
		p = sorted_list;
		while (p != NULL)
		{
			Node	*tmp = p;
			
			printf("%lu, %s, %s, %hhu", p->data.reg_num, p->data.model, p->data.category, p->data.loaned);
			printf("  ->  ");
			p = p->next;
			free(tmp);
		}
		printf("\n");
	}
}

unsigned char	read_input(void)
{
	unsigned char	input = 0;
	
	printf("Choice: ");
	scanf("%hhu", &input);
	while (input < 1 || input > 7)
	{
		clear_buffer();
		show_menu();
		printf("Wrong input, retry.\n");
		printf("Choice: ");
		scanf("%hhu", &input);
	}
	return (input);
}

void			start_program(void)
{
	unsigned char	input = 0;
	Node			*list = NULL;

	list = request_list_creation();
	//push_node(&list, car); Testing purposes;
	//show_node(list);
	while (1)
	{
		show_menu();
		input = read_input();
		if (input == 1)
		{
			ui_add(&list);
		}
		else if (input == 2)
		{
			ui_edit(&list);
		}
		else if (input == 3)
		{
			ui_loan(&list);
		}
		else if (input == 4)
		{
			ui_criteria(&list);
		}
		else if (input == 5)
		{
			ui_sort(&list);
		}
		else if (input == 6)
		{
			Node	*p;

			p = list;
			while (p != NULL)
			{
				printf("%lu, %s, %s, %hhu", p->data.reg_num, p->data.model, p->data.category, p->data.loaned);
				printf("  ->  ");
				p = p->next;
			}
			printf("\n");
		}
		else if (input == 7)
		{
			send_clear_repo(&list);
			return;
		}
	}
}