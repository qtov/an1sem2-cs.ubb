#include "Builder.h"
#include <QApplication>

using namespace std;

int	main(int argc, char** argv)
{
	QApplication a(argc, argv);

	Builder	builder;
	GUI		gui(builder.getController());

	gui.show();

	return a.exec();
}
