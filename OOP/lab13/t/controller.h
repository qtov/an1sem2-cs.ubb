#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"
#include "observer.h"

class controller : public Observable
{
public:
	controller(repository *repo);
	~controller();
	void	add(int, int, int);
	std::vector<std::vector<int>> get_list();
	int		get_size();
	void	empty_list();
	void	remove_last();

private:
	repository *repo;
};

#endif // CONTROLLER_H