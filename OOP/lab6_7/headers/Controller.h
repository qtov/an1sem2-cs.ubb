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
	bool	isvalid_number(const std::string&);
	bool	isvalid_title(const std::string&);
	bool	isvalid_type(const std::string&);
	void	add(const std::string&, const std::string&, const std::string&, const int&);

private:
	Repository* repository;
	Validator*	validator;
};

#endif
