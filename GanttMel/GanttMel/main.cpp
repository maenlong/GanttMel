#include "ganttmel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GanttMel w;
	w.show();
	return a.exec();
}
