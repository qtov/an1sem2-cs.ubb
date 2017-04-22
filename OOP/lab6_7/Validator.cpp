#include "Validator.h"

using namespace std;

Validator::Validator() {};

Validator::~Validator() {};

bool	Validator::isvalid_number(const string& s)
{
	return s.find_first_not_of("0123456789") == string::npos;
}

bool	Validator::isvalid_title(const string& s)
{
	int	len = s.length();

	if (len < 1 || len > 30)
		return (0);
	return (1);
}

bool	Validator::isvalid_description(const string& s)
{
	int	len = s.length();

	if (len < 1 || len > 1000)
		return (0);
	return (1);
}

bool	Validator::isvalid_type(const string& s)
{
	int	len = s.length();

	if (len < 1 || len > 10)
		return (0);
	return (1);
}