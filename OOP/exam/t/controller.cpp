#include "controller.h"

using namespace std;

Controller::Controller(Repository* _repo, Validator *_val)
{
	this->repo = _repo;
	this->val = _val;
}

void	Controller::add(int id, string tit, string art, int rnk)
{
	/*
		input: date pt song
		trimite la repo pt a adauga
	*/
	if (this->val->isvalid_id(id) && 	this->val->isvalid_rnk(rnk))
		this->repo->add(id, tit, art, rnk);
}

void	Controller::edit(int id, string tit, string art, int rnk)
{
	/*
		input: date pt song
		trimite la repo pt a edita
	*/
	if (this->val->isvalid_id(id) && 	this->val->isvalid_rnk(rnk))
		this->repo->edit(id, tit, art, rnk);
}

void	Controller::rm(int id)
{
	/*
		input: id pt song
		trimite la repo pt a sterge elem. cu id = id
	*/
	if (this->val->isvalid_id(id))
		this->repo->rm(id);
}

vector<Song> Controller::get_lst()
{
	/*
		Returneaza copie lista din repo
	*/
	return this->repo->get_lst();
}