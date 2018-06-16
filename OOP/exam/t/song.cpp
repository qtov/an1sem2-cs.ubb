#include "song.h"

using namespace std;

Song::Song(int _id, string _tit, string _art, int _rnk)
{
	this->id = _id;
	this->title = _tit;
	this->artist = _art;
	this->rank = _rnk;
}

Song::Song()
{}

void	Song::set_id(int _id)
{
	this->id = _id;
}

int		Song::get_id()
{
	return this->id;
}

void	Song::set_title(string _title)
{
	this->title = _title;
}

string	Song::get_title()
{
	return this->title;
}

void	Song::set_artist(string _artist)
{
	this->artist = _artist;
}

string	Song::get_artist()
{
	return this->artist;
}

void	Song::set_rank(int _rank)
{
	this->rank = _rank;
}

int		Song::get_rank()
{
	return this->rank;
}

string	Song::get_print()
{
	string str = "";

	str += QString::number(this->id).toStdString();
	str += "; ";
	str += this->title;
	str += "; ";
	str += this->artist;
	str += "; ";
	str += QString::number(this->rank).toStdString();
	return str;
}
