#ifndef UNDO_ADD_H
#define UNDO_ADD_H

#include "Undo_Action.h"

class Undo_Add : public Undo_Action
{
public:
	Undo_Add(std::vector<Activity>* list)
	{
		this->undo_list = list;
	}
	~Undo_Add()
	{
		delete this->undo_list;
	}
	void	do_undo()
	{
		
	}
};

#endif