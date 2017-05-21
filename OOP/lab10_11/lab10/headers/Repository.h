#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "debug.h"
#include <string>
#include <vector>
#include "Activity.h"
#include <algorithm>
#include "not_unique.h"
#include "back_exception.h"
#include "Undo_Action.h"

class Repository
{
private:
	std::vector<Activity>*		list;
public:
	Repository();
	void						add(const std::string&, const std::string&, const std::string&, const int&);
	std::vector<Activity>*		get_list();
	void						remove(const std::string&);
	bool						exists(const std::string&);
	void						edit(const std::string&, const std::string&, const std::string&, const std::string&);
	Activity&					get_elem(const std::string&);
	void						delete_list();
	void						update_list(std::vector<Activity>* new_list);
	~Repository();
};

#endif
