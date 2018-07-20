#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUI w(new Controller(new Repository(), new Validator()));

	w.show();

	return a.exec();
}
