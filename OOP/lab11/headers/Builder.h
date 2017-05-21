#ifndef BUILDER_H
#define BUILDER_H

#include "File_Repository.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

class Builder {
public:
	Controller*			getController() const;
	UI*					getUI() const;
	Validator*			getValidator() const;
	File_Repository*	getFRepository() const;
};

#endif