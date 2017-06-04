#include "Builder.h"
#include <QApplication>

using namespace std;

int	main(int argc, char** argv)
{
	QApplication a(argc, argv);

	Builder	builder;
	GUI		*gui = new GUI(builder.getController());

	gui->show();

	int ret = a.exec();

	return ret;
}
