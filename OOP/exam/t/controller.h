#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"
#include "validator.h"

class Controller
{
public:
	Controller(Repository*, Validator*);
	void	add(int id, string tit, string art, int rnk);
	void	edit(int id, string tit, string art, int rnk);
	void	rm(int id);
	vector<Song> get_lst();

private:
	Repository* repo;
	Validator* val;
};

#endif // CONTROLLER_H