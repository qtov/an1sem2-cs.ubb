#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Repository.h"
#include "Validator.h"

class Controller
{
public:
	Controller(Repository*, Validator*);
	~Controller();
	void						__debug_write();
	bool						isvalid_number(const std::string&) const;
	bool						isvalid_title(const std::string&) const;
	bool						isvalid_type(const std::string&) const;
	bool						isvalid_description(const string&) const;
	DynamicVector<Activity>*	get_list() const;
	DynamicVector<Activity>*	get_list_filtered(const string&, const string&);
	DynamicVector<Activity>*	get_list_sorted(const string&);
	void						add(const std::string&, const std::string&, const std::string&, const int&);
	void						remove(const std::string&);
	bool						exists(const std::string&);
	void						edit(std::string&, std::string&, std::string&, std::string&);
	void						init();
	Activity&					get_elem(const std::string&);

private:
	Repository* repository;
	Validator*	validator;
};

#endif
