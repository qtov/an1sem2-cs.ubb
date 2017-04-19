#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "debug.h"
#include <string>
#include "DynamicVector.h"

class Repository
{
public:
	Repository();
	void	__debug_write();
	void	add(const std::string&, const std::string&, const std::string&, const int&);
	~Repository();
};

#endif
