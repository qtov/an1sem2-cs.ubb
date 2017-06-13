#include "gui.h"
#include <QApplication>
#include "gui.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Controller *ctrl = new Controller(new Repository(), new Repository());
	GUI w(ctrl);
	w.show();

	return a.exec();
}
