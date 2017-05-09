#ifndef UNDO_DELETE_H
#define UNDO_DELETE_H

#include "Undo_Action.h"

class Undo_Delete : public Undo_Action
{
public:
	Undo_Delete(std::vector<Activity>* list)
	{
		this->undo_list = list;
	}
	~Undo_Delete()
	{
		delete this->undo_list;
	}
	void	do_undo()
	{
		
	}
};

#endif