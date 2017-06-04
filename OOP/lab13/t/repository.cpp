#include "repository.h"

repository::repository()
{

}

repository::~repository()
{
	this->list.clear();
}

void	repository::add(int x, int y, int r)
{
	vector<int> lst;

	lst.push_back(x);
	lst.push_back(y);
	lst.push_back(r);
	this->list.push_back(lst);
}

int		repository::get_size()
{
	return this->list.size();
}

std::vector<std::vector<int>> repository::get_list()
{
	return this->list;
}

void	repository::empty_list()
{
	this->list.clear();
}

void	repository::remove_last()
{
	this->list.pop_back();
}
