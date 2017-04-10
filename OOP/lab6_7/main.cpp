#include <iostream>
#include "Builder.h"
#include "debug.h"

int	main()
{
{
		Builder	builder;
		UI*		ui = builder.getUI();
	
		ui->start();
		//ui->destroy();
		printf("%p, %p, %p->main\n", ui, ui->controller, ui->controller->repository);
		delete ui->controller->repository;
		delete ui->controller;
		delete ui;
}
	return (0);
}
