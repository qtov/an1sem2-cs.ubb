#include "repository.h"

using namespace std;

Repository::Repository()
{

}

void	Repository::add(int id, QString name, int val)
{
	Player p(id, name, val);
	this->lst.push_back(p);
}

vector<Player> Repository::get_lst()
{
	return this->lst;
}
