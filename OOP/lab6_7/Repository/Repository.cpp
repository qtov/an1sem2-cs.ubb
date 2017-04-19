#include "Repository.h"

using namespace std;

Repository::Repository()
{

}

void	Repository::__debug_write()
{
	cout << "Repository\n";
}

void	Repository::add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
{
	//cout << _title << " " << _description << " " << _type << " " << _duration << "\n";
}

Repository::~Repository() {}
