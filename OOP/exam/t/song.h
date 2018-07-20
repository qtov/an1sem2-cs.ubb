#ifndef SONG_H
#define SONG_H

#include <QString>

using namespace std;

class Song
{
public:
	Song(int, string, string, int);
	Song();
	void	set_id(int);
	int		get_id();
	void	set_title(string);
	string	get_title();
	void	set_artist(string);
	string	get_artist();
	void	set_rank(int);
	int		get_rank();
	string	get_print();

private:
	int id;
	string title;
	string artist;
	int rank;
};

#endif // SONG_H