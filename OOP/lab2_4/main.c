#include "menu.h"
#include "car.h"
#include "node.h"
#include <stdlib.h>

Node*	list = NULL;

int		main(void)
{
	unsigned char	input;

	show_menu();
	input = read_input();
	if (input == 1)
	{
		show_menu_add();
	}
	/*else if ()
	{
		
	}
	else if ()
	{
		
	}*/
	return (0);
}