#include "repository.h"
#include <iostream>

using namespace std;

Repository::Repository()
{
	this->load();
}

void	Repository::add(int _id, string _tit, string _art, int _rnk)
{
	/*
		input: date pt song
		adauga song-ul cu datele din parametrii
	*/
	Song sng(_id, _tit, _art, _rnk);
	int i;
	for (i = 0; i < lst.size(); i++)
		if (_id == lst[i].get_id())
			return;
	this->lst.push_back(sng);

	this->save();
}

void	Repository::edit(int _id, string _tit, string _art, int _rnk)
{
	/*
		input: date pt song
		editeaza song-ul cu id = _id
	*/
	int i;

	for (i = 0; i < lst.size(); i++)
		if (_id == lst[i].get_id())
		{
			lst[i].set_id(_id);
			lst[i].set_title(_tit);
			lst[i].set_artist(_art);
			lst[i].set_rank(_rnk);
		}

	this->save();
}

void	Repository::rm(int _id)
{
	/*
		input: id pt song
		Sterge din lista song-ul cu id = _id
	*/
	int i;

	vector<Song> neww;

	for (i = 0; i < lst.size(); i++)
		if (_id != lst[i].get_id())
		{
			neww.push_back(lst[i]);
		}

	lst = neww;
	this->save();
}

void	Repository::load()
{
	/*
		Ia din fisier si updateaza lista
	*/
	ifstream ifs;
	Song song;

	ifs.open("data");
	string str;

	while (getline(ifs, str))
	{
		song.set_id(stoi(str));
		getline(ifs, str);
		song.set_title(str);
		getline(ifs, str);
		song.set_artist(str);
		getline(ifs, str);
		song.set_rank(stoi(str));
		this->lst.push_back(song);
	}

	ifs.close();
}

void	Repository::save()
{
	/*
		Scrie lista in fisier
	*/
	ofstream ofs;

	ofs.open("data");
	int i;
	for (i = 0; i < lst.size(); i++)
	{
		ofs << lst[i].get_id() << "\n";
		ofs << lst[i].get_title() << "\n";
		ofs << lst[i].get_artist() << "\n";
		ofs << lst[i].get_rank() << "\n";
	}
	ofs.close();
}

vector<Song> Repository::get_lst()
{
	return this->lst;
}