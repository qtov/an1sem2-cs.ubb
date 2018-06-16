#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "song.h"
#include <vector>
#include <fstream>

using namespace std;

class Repository
{
public:
	Repository();
	void	add(int, string, string, int);
	void	edit(int, string, string, int);
	void	rm(int);
	void	load();
	void	save();
	vector<Song> get_lst();

private:
	vector<Song> lst;
};

#endif // REPOSITORY_H