#ifndef UI_H
#define UI_H

#include "debug.h"
#include "Controller.h"
#include <iostream>

class UI
{
public:
	UI(Controller*);
	~UI();
	void		start();

private:
	Controller* controller;
	void		show_menu() const;
	void		add();
	void		display();
};

#endif
