#include <iostream>
#include "Builder.h"
#include "debug.h"

using namespace std;

int	main()
{
	Builder	builder;
	UI*		ui = builder.getUI();

	ui->start();
	delete ui;

	return (0);
}
