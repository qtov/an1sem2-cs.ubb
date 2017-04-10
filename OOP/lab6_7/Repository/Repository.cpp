#include "Repository.h"

using namespace std;

void	Repository::__debug_write()
{
	cout<<"Repository\n";
}

void	Repository::destroy()
{
	delete this;
}
