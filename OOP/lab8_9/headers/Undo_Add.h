#ifndef UNDO_ADD_H
#define UNDO_ADD_H

#include "Undo_Action.h"
#include "File_Repository.h"

class Undo_Add : public Undo_Action
{
private:
	std::vector<Activity>*	undo_list;
	File_Repository*		frepo;

public:
	Undo_Add(std::vector<Activity>* list, File_Repository* _frepo)
	{
		this->undo_list = list;
		this->frepo = _frepo;
	}

	~Undo_Add() override
	{
		delete this->undo_list;
	}

	void	do_undo() override
	{
		this->frepo->delete_list();
		for (auto elem : *this->undo_list)
			this->frepo->add(elem.get_title(), elem.get_description(), elem.get_type(), elem.get_duration());
	}
};

#endif