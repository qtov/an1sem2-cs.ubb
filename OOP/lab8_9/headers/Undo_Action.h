#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Activity.h"

class Undo_Action
{
private:
	std::vector<Activity>* undo_list;

public:
	Undo_Action(std::vector<Activity>* list)
	{
		this->undo_list = list;
	}
	~Undo_Action()
	{
		delete this->undo_list;
	}

	std::vector<Activity>* get_list()
	{
		return this->undo_list;
	}

	virtual void	do_undo() { };
};

#endif