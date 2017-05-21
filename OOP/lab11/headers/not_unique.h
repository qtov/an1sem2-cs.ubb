#ifndef NOT_UNIQUE_H
#define NOT_UNIQUE_H

#include <string>

class not_unique : public exception
{
public:
	not_unique(const char* msg) : err_msg(msg) { }
	~not_unique() throw() {};
	const char *what() const throw() { return this->err_msg.c_str(); };
private:
	std::string err_msg;
};

#endif