#include "Controller.h"

using namespace std;

Controller::Controller(Repository* _repository, Validator* _validator)
{
	this->repository = _repository;
	this->validator = _validator;
}

void						Controller::__debug_write()
{
	cout << "Controller\n";
	this->repository->__debug_write();
}

bool						Controller::isvalid_number(const string& s) const
{
	return this->validator->isvalid_number(s);
}

bool						Controller::isvalid_title(const string& s) const
{
	return this->validator->isvalid_title(s);
}

bool						Controller::isvalid_type(const string& s) const
{
	return this->validator->isvalid_type(s);
}

bool						Controller::isvalid_description(const string& s) const
{
	return this->validator->isvalid_description(s);
}

void						Controller::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	this->repository->add(_title, _description, _type, _duration);
}

void						Controller::remove(const std::string& _title)
{
	this->repository->remove(_title);
}

bool						Controller::exists(const std::string& _title)
{
	return this->repository->exists(_title);
}

DynamicVector<Activity>*	Controller::get_list() const
{
	DynamicVector<Activity>*	list;

	list = this->repository->get_list();
	return list;
}

void						Controller::edit(std::string& _title, std::string& _description, std::string& _type, std::string& _duration)
{
	if (!this->validator->isvalid_title(_title))
		_title = "";
	if (!this->validator->isvalid_description(_description))
		_description = "";
	if (!this->validator->isvalid_type(_type))
		_type = "";
	if (!this->validator->isvalid_number(_duration))
		_duration = "";
	this->repository->edit(_title, _description, _type, _duration);
}

void						Controller::init()
{
	this->repository->init();
}

Activity&					Controller::get_elem(const std::string& _title)
{
	return this->repository->get_elem(_title);
}

Controller::~Controller()
{
	delete this->repository;
	delete this->validator;
}