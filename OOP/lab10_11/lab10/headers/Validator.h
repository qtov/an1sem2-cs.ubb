#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "string"

class Validator
{
public:
	Validator();
	~Validator();
	bool	isvalid_number(const std::string&);
	bool	isvalid_title(const std::string&);
	bool	isvalid_type(const std::string&);
	bool	isvalid_filename(const std::string&);
	bool	isvalid_description(const std::string&);
};

#endif