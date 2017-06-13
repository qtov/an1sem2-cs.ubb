#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QString>
#include "player.h"
#include <vector>

class Repository
{
public:
	Repository();
	void	add(int, QString, int);
	std::vector<Player> get_lst();

private:
	std::vector<Player> lst;
};

#endif // REPOSITORY_H