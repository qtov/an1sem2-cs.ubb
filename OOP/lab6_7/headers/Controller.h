#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Repository.h"

class Controller
{
public:
	Controller(Repository*);
	void	__debug_write();
	void	destroy();

private:
	Repository* repository;
};

#endif