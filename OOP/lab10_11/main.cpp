#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	QLabel lbl("Hello Naito");
	lbl.show();
	return a.exec();
}
