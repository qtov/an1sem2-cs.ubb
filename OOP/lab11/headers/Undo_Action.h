#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Activity.h"

class Undo_Action
{
public:
	virtual ~Undo_Action() {};

	virtual void	do_undo() = 0;
};

#endif