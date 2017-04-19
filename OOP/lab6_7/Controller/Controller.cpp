#include "Controller.h"

using namespace std;

Controller::Controller(Repository* _repository, Validator* _validator)
{
	this->repository = _repository;
	this->validator = _validator;
}

void	Controller::__debug_write()
{
	cout<<"Controller\n";
	this->repository->__debug_write();
}

Controller::~Controller()
{
	delete this->repository;
	delete this->validator;
}

bool	Controller::isvalid_input(const string& s)
{
	return this->validator->isvalid_input(s);
}