#include "Repository.h"
#include <typeinfo>

using namespace std;

Repository::Repository()
{
	this->list = new DynamicVector<Activity>();
}

void						Repository::__debug_write()
{
	cout << "Repository\n";
}

void						Repository::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	Activity	activity(_title, _description, _type, _duration);

	if (this->list->exists(activity))
		throw invalid_argument("Unique name exists.");
	this->list->push(activity);
}

DynamicVector<Activity>*	Repository::get_list()
{
	DynamicVector<Activity>	*new_list;
	int						i;

	new_list = new DynamicVector<Activity>;
	for (i = 0; i < this->list->get_size(); ++i)
	{
		new_list->push((*this->list)[i]);
	}
	return (new_list);
}

void						Repository::remove(const std::string& _title)
{
	Activity	activity(_title, "", "", 0);
	
	this->list->remove(activity);
}

bool						Repository::exists(const std::string& _title)
{
	Activity	activity(_title, "", "", 0);

	return this->list->exists(activity);
}

void						Repository::edit(const std::string& _title, const std::string& _description, const std::string& _type, const std::string& _duration)
{
	Activity	activity;
	int			index;

	activity.set_title(_title);
	index = this->list->index_of(activity);
	if (_description != "")
		activity.set_description(_description);
	else
	 	activity.set_description((*this->list)[index].get_description());
	if (_type != "")
		activity.set_type(_type);
	else
		activity.set_type((*this->list)[index].get_type());
	if (_duration != "")
		activity.set_duration(stoi(_duration));
	else
		activity.set_duration((*this->list)[index].get_duration());
	this->list->edit(activity);
}

void						Repository::init()
{
	Activity t("123", "123", "123", 123);
	this->list->push(t);
	t = Activity("678", "678", "678", 678);
	this->list->push(t);
	t = Activity("567", "567", "567", 567);
	this->list->push(t);
	t = Activity("456", "456", "456", 456);
	this->list->push(t);
	t = Activity("345", "345", "345", 345);
	this->list->push(t);
	t = Activity("234", "234", "234", 234);
	this->list->push(t);
	t = Activity("6789", "678", "123", 123);
	this->list->push(t);
	t = Activity("6788", "678", "123", 123);
	this->list->push(t);
	t = Activity("5678", "567", "234", 234);
	this->list->push(t);
	t = Activity("4568", "456", "234", 233);
	this->list->push(t);
	t = Activity("3458", "345", "234", 243);
	this->list->push(t);
	t = Activity("2348", "234", "234", 132);
	this->list->push(t);
}

Activity&					Repository::get_elem(const std::string& _title)
{
	Activity activity(_title, "", "", 0);
	
	return (*this->list)[this->list->index_of(activity)];
}

Repository::~Repository()
{
	delete this->list;
}
