#include "tbl.h"
#include <stdio.h>
#include "drw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	controller *ctrl = new controller(new repository());

	srand(time(NULL));

	tbl *w = new tbl(ctrl);
	drw *q = new drw(ctrl);

	w->show();
	q->show();

	int ret = a.exec();

	delete ctrl;

	return ret;
}
