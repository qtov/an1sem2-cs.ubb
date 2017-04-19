#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Repository.h"
#include "Validator.h"

class Controller
{
public:
	Controller(Repository*, Validator*);
	~Controller();
	void	__debug_write();
	bool	isvalid_input(const std::string&);

private:
	Repository* repository;
	Validator*	validator;
};

#endif
