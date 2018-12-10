#include "MyGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyGame w;
	w.show();
	return a.exec();
}
