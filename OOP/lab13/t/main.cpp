#include "tbl.h"
#include "drw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	tbl w;
	drw q;

	w.show();
	q.show();

	return a.exec();
}
