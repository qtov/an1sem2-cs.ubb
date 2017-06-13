#include "controller.h"

Controller::Controller(Repository *_repo, Repository *_repo2)
{
	this->repo = _repo;
	this->repo2 = _repo2;
}

void	Controller::add(QString id, QString name, QString val)
{
	vector<Player> lst;
	int _id, _val;
	_id = id.toInt();
	_val = val.toInt();

	lst = this->repo->get_lst();
	for (auto elem : lst)
		if (elem.id == _id)
			return;
	this->repo->add(_id, name, _val);
}

void	Controller::add2(QString id, QString name, QString val)
{
	vector<Player> lst;
	int _id, _val;
	_id = id.toInt();
	_val = val.toInt();

	lst = this->repo2->get_lst();
	for (auto elem : lst)
		if (elem.id == _id)
			return;

	this->repo2->add(_id, name, _val);
}

vector<Player>	Controller::get_lst()
{
	return this->repo->get_lst();
}

vector<Player>	Controller::get_lst2()
{
	return this->repo2->get_lst();
}