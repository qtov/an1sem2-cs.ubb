#include "Activity.h"

using namespace std;

Activity::Activity(string _title, string _description, string _type, int _duration)
{
	this->title = _title;
	this->description = _description;
	this->type = _type;
	this->duration = _duration;
}