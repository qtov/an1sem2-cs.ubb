#include "Controller.h"

using namespace std;

Controller::Controller(Repository* _repository)
{
	this->repository = _repository;
}

void	Controller::__debug_write()
{
	cout<<"Controller\n";
	this->repository->__debug_write();
}

void	Controller::destroy()
{
	repository->destroy();
	delete this;
}
