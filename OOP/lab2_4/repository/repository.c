#include "node.h"
#include "car.h"
#include <string.h>
#include <stdio.h>

void	repo_add_car(unsigned long reg_num, char model[100], char category[10])
{
	Car		car;
	
	(void)car;
	car.reg_num = reg_num;
	strcpy(car.model, model);
	strcpy(car.category, category);
	/*printf("%lu\n", reg_num);
	printf("%s\n", model);
	printf("%s\n", category);*/
	
}