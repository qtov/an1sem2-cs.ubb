#include "controller.h"

controller::controller(repository *_repo)
{
	this->repo = _repo;
}

controller::~controller()
{
	delete this->repo;
}

void	controller::add(int x, int y, int r)
{
	this->repo->add(x, y, r);
	notify_all();
}

int		controller::get_size()
{
	return this->repo->get_size();
}

std::vector<std::vector<int>>& controller::get_list()
{
	return this->repo->get_list();
}

void	controller::empty_list()
{
	this->repo->empty_list();
	notify_all();
}

void	controller::remove_last()
{
	this->repo->remove_last();
	notify_all();
}

void	controller::rm_lst(Observer* _obs)
{
	this->obs.erase(std::remove(this->obs.begin(), this->obs.end(), _obs), this->obs.end());	
}