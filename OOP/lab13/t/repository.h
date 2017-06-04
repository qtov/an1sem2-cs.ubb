#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>

using namespace std;

class repository
{
private:
	vector<vector<int>> list;

public:
	repository();
	void	add(int, int, int);
	int		get_size();
	std::vector<std::vector<int>> get_list();
	void	empty_list();
	void	remove_last();
	~repository();
};

#endif // REPOSITORY_H
