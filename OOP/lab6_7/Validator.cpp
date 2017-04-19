#include "Validator.h"

using namespace std;

Validator::Validator() {};

Validator::~Validator() {};

bool	Validator::isvalid_input(const string& s)
{
	return s.find_first_not_of("0123456789") == string::npos;
}