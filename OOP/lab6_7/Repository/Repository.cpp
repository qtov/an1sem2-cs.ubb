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

	this->list->push(activity);
}

DynamicVector<Activity>*	Repository::get_list()
{
	DynamicVector<Activity>	*new_list;
	int						i;

	new_list = new DynamicVector<Activity>;
	for (i = 0; i < this->list->get_size(); ++i)
	{
		new_list->push(this->list->at_index(i));
	}
	return (new_list);
}

Repository::~Repository()
{
	delete this->list;
}
