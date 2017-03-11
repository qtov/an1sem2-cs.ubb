#include <stdio.h>
#include "controller.h"

void			show_menu(void)
{
	printf("1. Add car.\n");
	printf("2. Edit existing car.\n");
	printf("3. Loan/return car.\n");
	printf("4. View cars based on a criteria.\n");
	printf("5. Sort cars.\n");
	printf("6. Exit.\n");
}

void			show_menu_add(void)
{
	unsigned long	reg_num = 0;
	char			model[100];
	char			category[10];

	printf("Registration number: ");
	scanf("%lu", &reg_num);
	while (send_reg_num_validator(reg_num) == 0)
	{
		while (getchar() != '\n')
			;
		printf("Wrong registration number, retry.\n");
		printf("Registration number: ");
		scanf("%lu", &reg_num);
	}
	printf("Model: ");
	while (getchar() != '\n')
		;
	scanf("%[^\n]", model);
	while (send_model_validator(model) == 0)
	{
		while (getchar() != '\n')
			;
		printf("Model empty or too long.\n");
		printf("Model: ");
		scanf("%[^\n]", model);
	}
	while (getchar() != '\n')
			;
	printf("Category: ");
	scanf("%[^\n]", category);
	while (send_category_validator(category) == 0)
	{
		while (getchar() != '\n')
			;
		printf("Wrong category, retry.\n");
		printf("Category: ");
		scanf("%[^\n]", category);
	}
	send_car_repository(reg_num, model, category);
}

unsigned char	read_input(void)
{
	unsigned char	input = 0;
	
	printf("Choice: ");
	scanf("%hhu", &input);
	while (input < 1 || input > 6)
	{
		while (getchar() != '\n')
			;
		show_menu();
		printf("Wrong input, retry.\n");
		printf("Choice: ");
		scanf("%hhu", &input);
	}
	return (input);
}