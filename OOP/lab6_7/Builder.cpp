#include "Builder.h"

UI*			Builder::getUI() const
{
	UI*	ui = new UI(getController());
	return (ui);
}

Controller*	Builder::getController() const
{
	Controller* controller = new Controller(getRepository());
	return (controller);
}

Repository*	Builder::getRepository() const
{
	Repository* repo = new Repository();
	return (repo);
}