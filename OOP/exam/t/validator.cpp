#include "validator.h"

Validator::Validator()
{

}

bool	Validator::isvalid_id(int _id)
{
	/*
		returneaza daca id e (0, inf)
	*/

	if (_id > 0)
		return true;
	return false;
}

bool	Validator::isvalid_rnk(int _rnk)
{
	/*
		returneaza daca rank e [0, 10)
	*/
	if (_rnk >= 0 && _rnk < 10)
		return true;
	return false;
}


