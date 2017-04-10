#include "UI.h"

UI::UI(Controller* _controller)
{
	this->controller = _controller;
}

void	UI::start()
{
	std::cout<<"potatoes\n";
	this->controller->__debug_write();

	controller->destroy();
}

void	UI::destroy()
{
	this->controller->destroy();
}