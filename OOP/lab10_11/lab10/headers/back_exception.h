#ifndef BACK_EXCEPTION_H
#define BACK_EXCEPTION_H

#include <string>

class back_exception : public exception
{
public:
	back_exception(const char* msg) : err_msg(msg) { }
	~back_exception() throw() {};
	const char *what() const throw() { return this->err_msg.c_str(); };
private:
	std::string err_msg;
};

#endif