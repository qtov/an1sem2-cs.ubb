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
	void		remove();
	void		edit();
	void		search();
	string		read_title();
	string		read_type();
	int			read_duration();
	string		read_description();
};

#endif
