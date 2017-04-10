#ifndef BUILDER_H
#define BUILDER_H

#include "Repository.h"
#include "Controller.h"
#include "UI.h"

class Builder {
public:
	Repository*	getRepository() const;
	Controller*	getController() const;
	UI*			getUI() const;
};

#endif