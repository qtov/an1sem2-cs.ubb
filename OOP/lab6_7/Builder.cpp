#include "Repository.h"

UI			Builder::getUI(const Controller& controller)
{
	UI	ui(getController());
	return (ui);
}

Controller	Builder::getController()
{
	Controller controller(getRepository());
	return (controller);
}

Repository	Builder::getRepository()
{
	Repository repo;
	return (repo);
}