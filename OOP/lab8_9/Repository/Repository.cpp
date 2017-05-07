#include "Repository.h"
#include <typeinfo>

using namespace std;

Repository::Repository()
{
	this->list = new std::vector<Activity>();
}

void						Repository::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	Activity					activity(_title, _description, _type, _duration);
	vector<Activity>::iterator	it;

	it = std::find(this->list->begin(), this->list->end(), activity);
	if (it != this->list->end())
		throw not_unique("Unique name exists.");
	this->list->push_back(activity);
}

std::vector<Activity>*		Repository::get_list()
{
	std::vector<Activity>	*new_list;
	int						i;

	new_list = new std::vector<Activity>;
	for (const Activity& elem : *this->list)
		new_list->push_back(elem);
	return (new_list);
}

void						Repository::remove(const std::string& _title)
{
	Activity	activity(_title, "", "", 0);
	
	auto it = std::find(this->list->begin(), this->list->end(), activity);
	if (it != this->list->end())
		this->list->erase(it);
}

bool						Repository::exists(const std::string& _title)
{
	Activity	activity(_title, "", "", 0);

	auto it = std::find_if(this->list->begin(), this->list->end(), [activity](auto elem) {
		return activity == elem;
	});
	if (it != this->list->end())
		return true;
	else
		return false;
}

void						Repository::edit(const std::string& _title, const std::string& _description, const std::string& _type, const std::string& _duration)
{
	Activity	activity;

	activity.set_title(_title);
	auto it = std::find(this->list->begin(), this->list->end(), activity);
	auto index = std::distance(this->list->begin(), it);
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
	(*this->list)[index] = activity;
}

Activity&					Repository::get_elem(const std::string& _title)
{
	Activity activity(_title, "", "", 0);
	
	auto it = std::find(this->list->begin(), this->list->end(), activity);
	auto index = std::distance(this->list->begin(), it);
	return (*this->list)[index];
}

Repository::~Repository()
{
	delete this->list;
}
