#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <iostream>

using namespace std;

class Activity
{
public:
	Activity();
	Activity(string, string, string, int);
	string	get_title() const;
	string	get_description() const;
	string	get_type() const ;
	int		get_duration() const;
	void	set_title(const string&);
	void	set_description(const string&);
	void	set_type(const string&);
	void	set_duration(const int&);
	friend ostream&	operator<<(ostream& stream, const Activity& activity)
	{
		cout << "Title: " << activity.get_title() << "\n";
		cout << "Description: " << activity.get_description() << "\n";
		cout << "Type: " << activity.get_type() << "\n";
		cout << "Duration: " << activity.get_duration() << "\n";
		cout << "------------------------------------------\n";
		return stream;
	}
	Activity&	operator=(const Activity& v);
	bool	operator==(const Activity& v) const;
	bool	operator<(const Activity& v) const;
	bool	operator>(const Activity& v) const;
	string	printable_form();

private:
	string	title;
	string	description;
	string	type;
	int		duration;
};

#endif
