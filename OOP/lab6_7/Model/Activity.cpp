#include "Activity.h"

using namespace std;

Activity::Activity()
{

}

Activity::Activity(string _title, string _description, string _type, int _duration)
{
	this->title = _title;
	this->description = _description;
	this->type = _type;
	this->duration = _duration;
}

void	Activity::set_title(const string& s)
{
	this->title = s;
}

void	Activity::set_description(const string& s)
{
	this->description = s;
}

void	Activity::set_type(const string& s)
{
	this->type = s;
}

void	Activity::set_duration(const int& s)
{
	this->duration = s;
}

string	Activity::get_title() const
{
	return this->title;
}

string	Activity::get_description() const
{
	return this->description;
}

string	Activity::get_type() const
{
	return this->type;
}

int		Activity::get_duration() const
{
	return this->duration;
}

bool	Activity::operator==(const Activity& v)
{
	if (this->get_title() == v.get_title())
		return true;
	return false;
}

Activity&	Activity::operator=(const Activity& v)
{
	if(this == &v)
		return *this;
	this->title = v.get_title();
	this->description = v.get_description();
	this->type = v.get_type();
	this->duration = v.get_duration();
	return *this;
}

//Activity::~Activity() {};