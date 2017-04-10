#include "Builder.h"

UI*			Builder::getUI() const
{
	UI*	ui = new UI(getController());
	// printf("%p -> Builder\n", ui);
	return (ui);
}

Controller*	Builder::getController() const
{
	Controller* controller = new Controller(getRepository());
	// printf("%p, ", controller);
	return (controller);
}

Repository*	Builder::getRepository() const
{
	Repository* repo = new Repository();
	// printf("%p, ", repo);
	return (repo);
}
