#include "Builder.h"

UI*					Builder::getUI() const
{
	UI*	ui = new UI(getController());
	return (ui);
}

Controller*			Builder::getController() const
{
	Controller* controller = new Controller(getFRepository(), getValidator());
	return (controller);
}

File_Repository*	Builder::getFRepository() const
{
	File_Repository* frepo = new File_Repository("./data/data");
	return (frepo);
}

Validator*			Builder::getValidator() const
{
	Validator* validator = new Validator();

	return (validator);
}
