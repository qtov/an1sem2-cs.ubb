#ifndef UNDO_EDIT_H
#define UNDO_EDIT_H

#include "Undo_Action.h"

class Undo_Edit : public Undo_Action
{
public:
	Undo_Edit(std::vector<Activity>* list)
	{
		this->undo_list = list;
	}
	~Undo_Edit()
	{
		delete this->undo_list;
	}
	void	do_undo()
	{

	}
};

#endif