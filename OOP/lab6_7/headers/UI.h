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

private:
	Controller* controller;
};

#endif