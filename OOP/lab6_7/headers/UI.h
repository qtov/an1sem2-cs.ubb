#ifndef UI_H
#define UI_H

#include "debug.h"
#include "Controller.h"

class UI
{
public:
	UI(Controller*);
	void		start();
	void		destroy();
	char		potaot[500];

//private:
	Controller* controller;
};

#endif
