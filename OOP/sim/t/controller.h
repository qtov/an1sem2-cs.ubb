#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"

using namespace std;

class Controller
{
public:
	Controller(Repository* repo, Repository *repo2);
	void	add(QString, QString, QString);
	void	add2(QString, QString, QString);
	vector<Player> get_lst();
	vector<Player> get_lst2();


private:
	Repository* repo;
	Repository* repo2;
};

#endif // CONTROLLER_H