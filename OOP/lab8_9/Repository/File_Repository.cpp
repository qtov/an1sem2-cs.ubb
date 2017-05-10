#include "File_Repository.h"

void	File_Repository::pull_from_file()
{
	std::ifstream	in(this->file_name);

	if (!in.is_open())
		throw invalid_argument("File could not be opened.");
	while (!in.eof())
	{
		std::string	title;
		std::string	description;
		std::string	type;
		std::string	duration;

		std::getline(in, title);
		if (in.eof())
			break;
		std::getline(in, description);
		std::getline(in, type);
		std::getline(in, duration);
		Repository::add(title, description, type, stoi(duration));
	}
	in.close();
}

void	File_Repository::push_to_file()
{
	std::ofstream 	out(this->file_name);
	vector<Activity>* list;

	if (!out.is_open())
		throw invalid_argument("File could not be opened.");
	list = Repository::get_list();
	for (const auto& elem : *list)
	{
		out << elem.get_title() << std::endl;
		out << elem.get_description() << std::endl;
		out << elem.get_type() << std::endl;
		out << elem.get_duration() << std::endl;
	}
	delete list;
	out.close();
}

void	File_Repository::push_to_specific_file(const std::string& name)
{
	std::ofstream 	out("./data/" + name + ".csv");
	vector<Activity>* list;

	if (!out.is_open())
		throw invalid_argument("File could not be opened.");
	list = Repository::get_list();
	for (const auto& elem : *list)
	{
		out << elem.get_title() << std::endl;
		out << elem.get_description() << std::endl;
		out << elem.get_type() << std::endl;
		out << elem.get_duration() << std::endl;
	}
	delete list;
	out.close();
}