#include "Controller.h"

using namespace std;

Controller::Controller(Repository* _repository, Validator* _validator)
{
	this->repository = _repository;
	this->validator = _validator;
}

void	Controller::__debug_write()
{
	cout << "Controller\n";
	this->repository->__debug_write();
}

bool	Controller::isvalid_number(const string& s) const
{
	return this->validator->isvalid_number(s);
}

bool	Controller::isvalid_title(const string& s) const
{
	return this->validator->isvalid_title(s);
}

bool	Controller::isvalid_type(const string& s) const
{
	return this->validator->isvalid_type(s);
}

void	Controller::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	this->repository->add(_title, _description, _type, _duration);
}

DynamicVector<Activity>*	Controller::get_list() const
{
	DynamicVector<Activity>*	list;

	list = this->repository->get_list();
	return list;
}

Controller::~Controller()
{
	delete this->repository;
	delete this->validator;
}