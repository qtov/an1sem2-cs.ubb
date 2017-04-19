#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

using namespace std;

class Activity
{
public:
	Activity(string, string, string, int);
	
private:
	string	title;
	string	description;
	string	type;
	int		duration;
};

#endif