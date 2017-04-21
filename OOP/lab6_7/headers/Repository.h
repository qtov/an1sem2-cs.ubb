#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "debug.h"
#include <string>
#include "DynamicVector.h"
#include "Activity.h"

class Repository
{
private:
	DynamicVector<Activity>*	list;
public:
	Repository();
	void						__debug_write();
	void						add(const std::string&, const std::string&, const std::string&, const int&);
	DynamicVector<Activity>*	get_list();
	~Repository();
};

#endif
