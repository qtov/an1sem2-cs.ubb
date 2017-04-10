#ifndef UI_H
#define UI_H

#include "debug.h"
#include "Controller.h"
#include <iostream>

class UI
{
public:
	UI(Controller*);
	void		start();
	void		destroy();
	void		show_menu();

private:
	Controller* controller;
};

#endif
