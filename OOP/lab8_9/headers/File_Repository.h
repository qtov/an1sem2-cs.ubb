#ifndef FILE_REPOSITORY_H
#define FILE_REPOSITORY_H

#include "Repository.h"
#include <iostream>
#include <fstream>

class File_Repository : public Repository
{
private:
	std::string	file_name;
	void		pull_from_file();
	void		push_to_file();
public:
	File_Repository(std::string file_name) : Repository(), file_name { file_name }	{
		pull_from_file();
	}

	void	add(const std::string& _title, const std::string& _description, const std::string& _type, const int& _duration)
	{
		Repository::add(_title, _description, _type, _duration);
		push_to_file();
	}

	void	remove(const std::string& _title)
	{
		Repository::remove(_title);
		push_to_file();
	}

	void	edit(const std::string& _title, const std::string& _description, const std::string& _type, const std::string& _duration)
	{
		Repository::edit(_title, _description, _type, _duration);
		push_to_file();
	}
};

#endif