#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "string"

class Validator
{
public:
	Validator();
	~Validator();
	bool	isvalid_input(const std::string&);

};

#endif