#include <iostream>
#include "Builder.h"
#include "debug.h"

int	main()
{
{
		Builder	builder;
		UI*		ui = builder.getUI();
	
		ui->start();
		printf("%p, %p, %p->main\n", ui, ui->controller, ui->controller->repository);
		ui->destroy();
}
	return (0);
}
