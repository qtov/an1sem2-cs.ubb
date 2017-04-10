#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Repository.h"

class Controller
{
public:
	char	potato[1000];
	Controller(Repository*);
	void	__debug_write();
	void	destroy();

//private:
	Repository* repository;
};

#endif
