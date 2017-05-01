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

DynamicVector<Activity>*	Controller::get_list_filtered(const string& filter_what, const string& input)
{
	DynamicVector<Activity>*	list;
	int	i;

	list = this->repository->get_list();
	if (filter_what == "description")
		for (i = 0; i < list->get_size(); ++i)
		{
			if ((*list)[i].get_description() != input)
			{
				list->remove(i);
				--i;
			}
		}
	else if (filter_what == "type")
		for (i = 0; i < list->get_size(); ++i)
		{
			if ((*list)[i].get_type() != input)
			{
				list->remove(i);
				--i;
			}
		}

	return list;
}

DynamicVector<Activity>*	Controller::get_list_sorted(const string& sort_by)
{
	DynamicVector<Activity>*	list;
	int							i;
	bool						ok = false;
	Activity					tmp;

	list = this->repository->get_list();
	if (sort_by == "title")
	{
		while (!ok)
		{
			ok = true;
			for (i = 0; i < list->get_size() - 1; ++i)
			{
				if ((*list)[i].get_title() > (*list)[i + 1].get_title())
				{
					tmp = (*list)[i];
					(*list)[i] = (*list)[i + 1];
					(*list)[i + 1] = tmp;
					ok = false;
				}
			}
		}
	}
	else if (sort_by == "description")
	{
		while (!ok)
		{
			ok = true;
			for (i = 0; i < list->get_size() - 1; ++i)
			{
				if ((*list)[i].get_description() > (*list)[i + 1].get_description())
				{
					tmp = (*list)[i];
					(*list)[i] = (*list)[i + 1];
					(*list)[i + 1] = tmp;
					ok = false;
				}
			}
		}
	}
	else if (sort_by == "type+duration")
	{
		while (!ok)
		{
			ok = true;
			for (i = 0; i < list->get_size() - 1; ++i)
			{
				if ((*list)[i].get_type() > (*list)[i + 1].get_type())
				{
					tmp = (*list)[i];
					(*list)[i] = (*list)[i + 1];
					(*list)[i + 1] = tmp;
					ok = false;
				}
				else if ((*list)[i].get_type() == (*list)[i + 1].get_type())
				{
					if ((*list)[i].get_duration() > (*list)[i + 1].get_duration())
					{
						tmp = (*list)[i];
						(*list)[i] = (*list)[i + 1];
						(*list)[i + 1] = tmp;
						ok = false;
					}
				}
			}
		}
	}
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